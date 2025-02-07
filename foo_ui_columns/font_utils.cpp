#include "pch.h"

#include "font_utils.h"

#include "font_manager_data.h"

namespace cui::fonts {

void FontDescription::set_dip_size(float size)
{
    dip_size = size;
    point_size_tenths
        = gsl::narrow_cast<int>(std::roundf(size * 720.0f / gsl::narrow_cast<float>(USER_DEFAULT_SCREEN_DPI)));
    log_font.lfHeight = gsl::narrow_cast<long>(std::roundf(-uih::direct_write::dip_to_px(size)));
}

void FontDescription::set_point_size(float size)
{
    point_size_tenths = gsl::narrow_cast<int>(std::roundf(size * 10.0f));
    dip_size = uih::direct_write::pt_to_dip(size);
    recalculate_log_font_height();
}

void FontDescription::set_point_size_tenths(int size_tenths)
{
    point_size_tenths = size_tenths;
    estimate_dip_size();
    recalculate_log_font_height();
}

void FontDescription::estimate_point_and_dip_size()
{
    point_size_tenths = -MulDiv(log_font.lfHeight, 720, uih::get_system_dpi_cached().cy);
    dip_size = uih::direct_write::px_to_dip(gsl::narrow_cast<float>(-log_font.lfHeight));
}

void FontDescription::estimate_dip_size()
{
    dip_size = gsl::narrow_cast<float>(point_size_tenths) * gsl::narrow_cast<float>(USER_DEFAULT_SCREEN_DPI) / 720.0f;
}

void FontDescription::recalculate_log_font_height()
{
    log_font.lfHeight = -MulDiv(point_size_tenths, uih::get_system_dpi_cached().cy, 720);
}

void FontDescription::fill_wss()
{
    if (wss)
        return;

    wil::com_ptr<IDWriteFont> font;
    std::wstring family_name;
    try {
        const auto context = uih::direct_write::Context::s_create();
        font = context->create_font(log_font);

        wil::com_ptr<IDWriteFontFamily> font_family;
        THROW_IF_FAILED(font->GetFontFamily(&font_family));

        wil::com_ptr<IDWriteLocalizedStrings> family_names;
        THROW_IF_FAILED(font_family->GetFamilyNames(&family_names));

        family_name = uih::direct_write::get_localised_string(family_names);
    }
    CATCH_LOG_RETURN();

    wss = uih::direct_write::WeightStretchStyle{
        std::move(family_name), font->GetWeight(), font->GetStretch(), font->GetStyle()};
}

uih::direct_write::WeightStretchStyle FontDescription::get_wss_with_fallback()
{
    fill_wss();

    return wss.value_or(uih::direct_write::WeightStretchStyle{});
}

void ConfigFontDescription::get_data_raw(stream_writer* stream, abort_callback& aborter)
{
    write_font(stream, m_font_description.log_font, aborter);
    stream->write_lendian_t(m_font_description.point_size_tenths, aborter);
}

void ConfigFontDescription::set_data_raw(stream_reader* stream, size_t size_hint, abort_callback& aborter)
{
    m_font_description.log_font = read_font(stream, aborter);
    m_font_description.estimate_point_and_dip_size();
    try {
        stream->read_lendian_t(m_font_description.point_size_tenths, aborter);
    } catch (const exception_io_data_truncation&) {
    }
}

LOGFONT read_font(stream_reader* stream, abort_callback& aborter)
{
    LOGFONT log_font{};

    stream->read_lendian_t(log_font.lfHeight, aborter);
    stream->read_lendian_t(log_font.lfWidth, aborter);
    stream->read_lendian_t(log_font.lfEscapement, aborter);
    stream->read_lendian_t(log_font.lfOrientation, aborter);
    stream->read_lendian_t(log_font.lfWeight, aborter);

    stream->read_lendian_t(log_font.lfItalic, aborter);
    stream->read_lendian_t(log_font.lfUnderline, aborter);
    stream->read_lendian_t(log_font.lfStrikeOut, aborter);
    stream->read_lendian_t(log_font.lfCharSet, aborter);
    stream->read_lendian_t(log_font.lfOutPrecision, aborter);
    stream->read_lendian_t(log_font.lfClipPrecision, aborter);
    stream->read_lendian_t(log_font.lfQuality, aborter);
    stream->read_lendian_t(log_font.lfPitchAndFamily, aborter);
    stream->read(&log_font.lfFaceName, sizeof(log_font.lfFaceName), aborter);

    return log_font;
}

void write_font(stream_writer* stream, const LOGFONT& log_font, abort_callback& aborter)
{
    LOGFONT lf = log_font;
    size_t face_len = pfc::wcslen_max(lf.lfFaceName, std::size(lf.lfFaceName));

    if (face_len < std::size(lf.lfFaceName)) {
        memset(lf.lfFaceName + face_len, 0, sizeof(WCHAR) * (std::size(lf.lfFaceName) - face_len));
    }

    stream->write_lendian_t(lf.lfHeight, aborter);
    stream->write_lendian_t(lf.lfWidth, aborter);
    stream->write_lendian_t(lf.lfEscapement, aborter);
    stream->write_lendian_t(lf.lfOrientation, aborter);
    stream->write_lendian_t(lf.lfWeight, aborter);

    stream->write_lendian_t(lf.lfItalic, aborter);
    stream->write_lendian_t(lf.lfUnderline, aborter);
    stream->write_lendian_t(lf.lfStrikeOut, aborter);
    stream->write_lendian_t(lf.lfCharSet, aborter);
    stream->write_lendian_t(lf.lfOutPrecision, aborter);
    stream->write_lendian_t(lf.lfClipPrecision, aborter);
    stream->write_lendian_t(lf.lfQuality, aborter);
    stream->write_lendian_t(lf.lfPitchAndFamily, aborter);

    stream->write(&lf.lfFaceName, sizeof(lf.lfFaceName), aborter);
}

std::optional<FontDescription> select_font(HWND wnd_parent, LOGFONT initial_font)
{
    if (!ModalDialogPrologue())
        return {};

    // Note: Using a hook to get the window handle of the font picker dialog
    // requires supplying a custom dialog template from font.dlg to avoid an
    // older dialog template being used. Given the hassle involved in that,
    // we pass the parent window to modal_dialog_scope instead.

    modal_dialog_scope scope(wnd_parent);

    LOGFONT lf{initial_font};
    CHOOSEFONT cf{};
    cf.lStructSize = sizeof(CHOOSEFONT);
    cf.hwndOwner = wnd_parent;
    cf.lpLogFont = &lf;
    cf.Flags = CF_SCREENFONTS | CF_FORCEFONTEXIST | CF_INITTOLOGFONTSTRUCT;
    cf.nFontType = SCREEN_FONTTYPE;

    if (ChooseFont(&cf))
        return {{lf, cf.iPointSize}};

    return {};
}

namespace {

float scale_font_size(long height, unsigned dpi)
{
    return gsl::narrow_cast<float>(height) * gsl::narrow_cast<float>(dpi)
        / gsl::narrow_cast<float>(uih::get_system_dpi_cached().cx);
}

} // namespace

SystemFont get_icon_font_for_dpi(unsigned dpi)
{
    LOGFONT lf{};
    try {
        uih::dpi::system_parameters_info_for_dpi(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lf, dpi);
    } catch (const uih::dpi::DpiAwareFunctionUnavailableError&) {
        SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lf, 0);

        const auto dip_size = scale_font_size(-lf.lfHeight, dpi);
        lf.lfHeight = MulDiv(lf.lfHeight, dpi, uih::get_system_dpi_cached().cx);

        return {lf, dip_size};
    }

    return {lf, gsl::narrow_cast<float>(-lf.lfHeight)};
}

SystemFont get_menu_font_for_dpi(unsigned dpi)
{
    NONCLIENTMETRICS ncm{};
    ncm.cbSize = sizeof(NONCLIENTMETRICS);
    try {
        uih::dpi::system_parameters_info_for_dpi(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, dpi);
    } catch (const uih::dpi::DpiAwareFunctionUnavailableError&) {
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0);

        const auto dip_size = scale_font_size(-ncm.lfMenuFont.lfHeight, dpi);
        ncm.lfMenuFont.lfHeight = MulDiv(ncm.lfMenuFont.lfHeight, dpi, uih::get_system_dpi_cached().cx);
        return {ncm.lfMenuFont, dip_size};
    }

    return {ncm.lfMenuFont, gsl::narrow_cast<float>(-ncm.lfMenuFont.lfHeight)};
}

std::optional<uih::direct_write::TextFormat> get_text_format(
    const uih::direct_write::Context::Ptr& context, const font::ptr& font_api)
{
    if (const auto text_format = font_api->create_wil_text_format()) {
        try {
            auto wrapped_text_format = context->wrap_text_format(
                text_format, font_api->rendering_mode(), font_api->force_greyscale_antialiasing());

            if (use_custom_emoji_processing)
                wrapped_text_format.set_emoji_processing_config(uih::direct_write::EmojiProcessingConfig{
                    mmh::to_utf16(colour_emoji_font_family.get()), mmh::to_utf16(monochrome_emoji_font_family.get())});
            return wrapped_text_format;
        }
        CATCH_LOG()
    }
    return {};
}

std::optional<uih::direct_write::TextFormat> get_text_format(const font::ptr& font_api)
{
    uih::direct_write::Context::Ptr context;
    try {
        context = uih::direct_write::Context::s_create();
    }
    CATCH_LOG();

    if (!context)
        return {};

    return get_text_format(context, font_api);
}

} // namespace cui::fonts

#include "pch.h"

#include "tab_text_rendering.h"

#include "config_appearance.h"
#include "font_manager_data.h"

namespace cui::prefs {

namespace {

constexpr auto rendering_modes = {
    std::make_tuple(fonts::RenderingMode::Automatic, L"Default"),
    std::make_tuple(fonts::RenderingMode::DirectWriteAutomatic, L"Automatic anti-aliasing"),
    std::make_tuple(fonts::RenderingMode::Natural, L"Horizontal anti-aliasing"),
    std::make_tuple(fonts::RenderingMode::NaturalSymmetric, L"Symmetric anti-aliasing"),
    std::make_tuple(fonts::RenderingMode::GdiClassic, L"GDI-compatible, classic"),
    std::make_tuple(fonts::RenderingMode::GdiNatural, L"GDI-compatible, natural"),
    std::make_tuple(fonts::RenderingMode::GdiAliased, L"GDI-compatible, no anti-aliasing"),
};

class TextRenderingTab : public PreferencesTab {
public:
    INT_PTR on_message(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

    HWND create(HWND wnd) override
    {
        return m_helper.create(wnd, IDD_PREFS_TEXT_RENDERING,
            [this](auto&&... args) { return on_message(std::forward<decltype(args)>(args)...); });
    }

    const char* get_name() override { return "Text rendering"; }

    bool get_help_url(pfc::string_base& p_out) override { return false; }

private:
    std::optional<ptrdiff_t> find_family_name(std::wstring_view family_name);
    void enable_or_disable_emoji_controls() const;

    HWND m_wnd{};
    HWND m_rendering_mode_combobox{};
    HWND m_force_greyscale_antialiasing_checkbox{};
    HWND m_use_custom_emoji_processing_checkbox{};
    HWND m_colour_emoji_family_combobox{};
    HWND m_monochrome_emoji_family_combobox{};
    bool m_is_font_fallback_available{};
    std::vector<std::wstring> m_emoji_family_names;

    PreferencesTabHelper m_helper{{IDC_TITLE1}};
};

INT_PTR TextRenderingTab::on_message(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg) {
    case WM_INITDIALOG: {
        m_wnd = wnd;
        m_rendering_mode_combobox = GetDlgItem(wnd, IDC_RENDERING_MODE);
        m_force_greyscale_antialiasing_checkbox = GetDlgItem(wnd, IDC_FORCE_GREYSCALE_ANTIALIASING);

        for (auto&& [value, name] : rendering_modes) {
            const auto index = uih::combo_box_add_string_data(m_rendering_mode_combobox, name, WI_EnumValue(value));

            if (WI_EnumValue(value) == fonts::rendering_mode && index != CB_ERR)
                ComboBox_SetCurSel(m_rendering_mode_combobox, index);
        }

        Button_SetCheck(
            m_force_greyscale_antialiasing_checkbox, fonts::force_greyscale_antialiasing ? BST_CHECKED : BST_UNCHECKED);

        m_use_custom_emoji_processing_checkbox = GetDlgItem(wnd, IDC_USE_CUSTOM_EMOJI_PROCESSING);
        m_colour_emoji_family_combobox = GetDlgItem(wnd, IDC_COLOUR_EMOJI_FAMILY);
        m_monochrome_emoji_family_combobox = GetDlgItem(wnd, IDC_MONOCHROME_EMOJI_FAMILY);

        Button_SetCheck(
            m_use_custom_emoji_processing_checkbox, fonts::use_custom_emoji_processing ? BST_CHECKED : BST_UNCHECKED);

        try {
            const auto direct_write_context = uih::direct_write::Context::s_create();
            m_is_font_fallback_available
                = static_cast<bool>(direct_write_context->factory().try_query<IDWriteFactory2>());

            m_emoji_family_names = direct_write_context->get_emoji_font_families();

            for (const auto& family_name : m_emoji_family_names) {
                ComboBox_AddString(m_colour_emoji_family_combobox, family_name.c_str());
                ComboBox_AddString(m_monochrome_emoji_family_combobox, family_name.c_str());
            }
        }
        CATCH_LOG()

        enable_or_disable_emoji_controls();

        if (!m_is_font_fallback_available) {
            const auto notes_static_control = GetDlgItem(wnd, IDC_TEXT_RENDERING_NOTES);
            const auto notes_text = uGetWindowText(notes_static_control);
            uSetWindowText(notes_static_control,
                fmt::format("{}\n\nEmoji settings require Windows 8.1 or newer.", notes_text.c_str()).c_str());
        }

        if (const auto index = find_family_name(mmh::to_utf16(fonts::colour_emoji_font_family.get())))
            ComboBox_SetCurSel(m_colour_emoji_family_combobox, *index);

        if (const auto index = find_family_name(mmh::to_utf16(fonts::monochrome_emoji_font_family.get())))
            ComboBox_SetCurSel(m_monochrome_emoji_family_combobox, *index);

        break;
    }
    case WM_DESTROY: {
        m_wnd = nullptr;
        m_rendering_mode_combobox = nullptr;
        m_emoji_family_names.clear();
        break;
    }
    case WM_COMMAND:
        switch (wp) {
        case IDC_RENDERING_MODE | (CBN_SELCHANGE << 16): {
            const int index = ComboBox_GetCurSel(m_rendering_mode_combobox);

            if (index == CB_ERR)
                break;

            const auto data = ComboBox_GetItemData(m_rendering_mode_combobox, index);

            if (data == CB_ERR)
                break;

            fonts::rendering_mode = gsl::narrow<std::underlying_type_t<fonts::RenderingMode>>(data);
            g_font_manager_data.dispatch_all_fonts_changed();
            break;
        }
        case IDC_COLOUR_EMOJI_FAMILY | (CBN_SELCHANGE << 16): {
            const int index = ComboBox_GetCurSel(m_colour_emoji_family_combobox);

            if (index == CB_ERR)
                break;

            fonts::colour_emoji_font_family = mmh::to_utf8(m_emoji_family_names[index]).c_str();
            g_font_manager_data.dispatch_all_fonts_changed();
            break;
        }
        case IDC_MONOCHROME_EMOJI_FAMILY | (CBN_SELCHANGE << 16): {
            const int index = ComboBox_GetCurSel(m_monochrome_emoji_family_combobox);

            if (index == CB_ERR)
                break;

            fonts::monochrome_emoji_font_family = mmh::to_utf8(m_emoji_family_names[index]).c_str();
            g_font_manager_data.dispatch_all_fonts_changed();
            break;
        }
        case IDC_FORCE_GREYSCALE_ANTIALIASING: {
            fonts::force_greyscale_antialiasing
                = Button_GetCheck(m_force_greyscale_antialiasing_checkbox) == BST_CHECKED;
            g_font_manager_data.dispatch_all_fonts_changed();
            break;
        }
        case IDC_USE_CUSTOM_EMOJI_PROCESSING: {
            fonts::use_custom_emoji_processing = Button_GetCheck(m_use_custom_emoji_processing_checkbox) == BST_CHECKED;
            enable_or_disable_emoji_controls();
            g_font_manager_data.dispatch_all_fonts_changed();
            break;
        }
        }
        break;
    }
    return 0;
}

std::optional<ptrdiff_t> TextRenderingTab::find_family_name(std::wstring_view search_family_name)
{
    auto iter = ranges::find_if(
        m_emoji_family_names, [search_family_name](auto&& family_name) { return family_name == search_family_name; });

    if (iter == m_emoji_family_names.end())
        return {};

    return std::distance(m_emoji_family_names.begin(), iter);
}

void TextRenderingTab::enable_or_disable_emoji_controls() const
{
    EnableWindow(m_use_custom_emoji_processing_checkbox, m_is_font_fallback_available);
    EnableWindow(m_colour_emoji_family_combobox, m_is_font_fallback_available && fonts::use_custom_emoji_processing);
    EnableWindow(
        m_monochrome_emoji_family_combobox, m_is_font_fallback_available && fonts::use_custom_emoji_processing);
}

} // namespace

PreferencesTab& get_text_rendering_tab()
{
    static TextRenderingTab tab;
    return tab;
}

} // namespace cui::prefs

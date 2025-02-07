#include "pch.h"

#include "font_utils.h"
#include "font_manager_data.h"

#include "config_appearance.h"
#include "core_font_ids.h"

FontManagerData::FontManagerData() : cfg_var(g_cfg_guid)
{
    m_common_items_entry = std::make_shared<Entry>();
    uGetIconFont(&m_common_items_entry->font_description.log_font);
    m_common_items_entry->font_description.estimate_point_and_dip_size();

    m_common_labels_entry = std::make_shared<Entry>();
    uGetMenuFont(&m_common_labels_entry->font_description.log_font);
    m_common_labels_entry->font_description.estimate_point_and_dip_size();
}

FontManagerData::~FontManagerData()
{
    for (auto& [id, callbacks] : m_callback_map) {
        if (callbacks.empty())
            continue;

        OutputDebugString(fmt::format(L"Columns UI: {} leaked callback(s) for font ID {} detected\n", callbacks.size(),
            mmh::to_utf16(pfc::print_guid(id).c_str()))
                .c_str());

        for (auto& callback : callbacks)
            callback.detach();
    }
}

void FontManagerData::g_on_common_font_changed(uint32_t mask)
{
    for (const auto callback : m_callbacks)
        callback->on_font_changed(mask);

    if (mask & cui::fonts::font_type_flag_items)
        if (const auto iter = m_callback_map.find(cui::fonts::items_font_id); iter != m_callback_map.end())
            for (const auto& callback : iter->second)
                (*callback)();

    if (mask & cui::fonts::font_type_flag_labels)
        if (const auto iter = m_callback_map.find(cui::fonts::labels_font_id); iter != m_callback_map.end())
            for (const auto& callback : iter->second)
                (*callback)();
}

void FontManagerData::dispatch_all_fonts_changed()
{
    g_on_common_font_changed(cui::fonts::font_type_flag_items | cui::fonts::font_type_flag_labels);

    for (const auto& client_ptr : cui::fonts::client::enumerate()) {
        const auto client_id = client_ptr->get_client_guid();

        // Avoid duplicate ui_config_callback::ui_fonts_changed() calls.
        if (client_id != cui::fonts::core_console_font_client_id && client_id != cui::fonts::core_lists_font_client_id)
            dispatch_client_font_changed(client_ptr);
    }
}

void FontManagerData::add_callback(GUID id, cui::basic_callback::ptr callback)
{
    m_callback_map[id].emplace_back(std::move(callback));
}

void FontManagerData::remove_callback(GUID id, cui::basic_callback::ptr callback)
{
    if (const auto iter = m_callback_map.find(id); iter != m_callback_map.end())
        std::erase(iter->second, callback);
}

void FontManagerData::dispatch_client_font_changed(cui::fonts::client::ptr client)
{
    client->on_font_changed();

    if (const auto iter = m_callback_map.find(client->get_client_guid()); iter != m_callback_map.end())
        for (const auto& callback : iter->second)
            (*callback)();
}

void FontManagerData::deregister_common_callback(cui::fonts::common_callback* p_callback)
{
    m_callbacks.remove_item(p_callback);
}

void FontManagerData::register_common_callback(cui::fonts::common_callback* p_callback)
{
    m_callbacks.add_item(p_callback);
}

FontManagerData::entry_ptr_t FontManagerData::find_by_id(GUID id)
{
    if (id == cui::fonts::items_font_id)
        return m_common_items_entry;

    if (id == cui::fonts::labels_font_id)
        return m_common_labels_entry;

    for (auto&& entry : m_entries) {
        if (entry->guid == id) {
            return entry;
        }
    }

    auto entry = std::make_shared<Entry>();
    entry->guid = id;
    cui::fonts::client::ptr ptr;

    if (cui::fonts::client::create_by_guid(id, ptr)) {
        if (ptr->get_default_font_type() == cui::fonts::font_type_items)
            entry->font_mode = cui::fonts::FontMode::CommonItems;
        else
            entry->font_mode = cui::fonts::FontMode::CommonLabels;
        m_entries.add_item(entry);
        return entry;
    }

    return {};
}

cui::fonts::FontDescription FontManagerData::resolve_font_description(const entry_ptr_t& entry)
{
    const auto is_common_items = entry->font_mode == cui::fonts::FontMode::CommonItems;
    const auto is_common_labels = entry->font_mode == cui::fonts::FontMode::CommonLabels;

    const auto resolved_entry = [&] {
        if (is_common_items)
            return m_common_items_entry;

        if (is_common_labels)
            return m_common_labels_entry;

        return entry;
    }();

    if (resolved_entry->font_mode == cui::fonts::FontMode::System) {
        const auto system_font = is_common_items ? cui::fonts::get_icon_font_for_dpi(USER_DEFAULT_SCREEN_DPI)
                                                 : cui::fonts::get_menu_font_for_dpi(USER_DEFAULT_SCREEN_DPI);

        cui::fonts::FontDescription description{system_font.log_font};
        description.fill_wss();
        const auto point_size = uih::direct_write::dip_to_pt(system_font.size);
        description.point_size_tenths = gsl::narrow_cast<int>(point_size * 10.0f + 0.5f);
        description.dip_size = system_font.size;
        return description;
    }

    resolved_entry->font_description.fill_wss();
    return resolved_entry->font_description;
}

void FontManagerData::set_data_raw(stream_reader* p_stream, size_t p_sizehint, abort_callback& p_abort)
{
    uint32_t version;
    p_stream->read_lendian_t(version, p_abort);
    if (version > cfg_version)
        return;

    m_common_items_entry->read(version, p_stream, p_abort);
    m_common_labels_entry->read(version, p_stream, p_abort);
    const auto count = p_stream->read_lendian_t<uint32_t>(p_abort);
    m_entries.remove_all();

    for (size_t i = 0; i < count; i++) {
        entry_ptr_t ptr = std::make_shared<Entry>();
        ptr->read(version, p_stream, p_abort);
        m_entries.add_item(ptr);
    }

    try {
        m_common_items_entry->read_extra_data(p_stream, p_abort);
    } catch (const exception_io_data_truncation&) {
        return;
    }

    m_common_labels_entry->read_extra_data(p_stream, p_abort);

    for (auto&& entry : m_entries) {
        entry->read_extra_data(p_stream, p_abort);
    }

    try {
        m_common_items_entry->read_extra_data_v2(p_stream, p_abort);
    } catch (const exception_io_data_truncation&) {
        return;
    }

    m_common_labels_entry->read_extra_data_v2(p_stream, p_abort);

    for (auto&& entry : m_entries) {
        entry->read_extra_data_v2(p_stream, p_abort);
    }
}

void FontManagerData::get_data_raw(stream_writer* p_stream, abort_callback& p_abort)
{
    pfc::list_t<GUID> clients;
    {
        service_enum_t<cui::fonts::client> client_enum;
        cui::fonts::client::ptr ptr;
        while (client_enum.next(ptr))
            clients.add_item(ptr->get_client_guid());
    }

    pfc::array_t<bool> mask;

    const auto count = gsl::narrow<uint32_t>(m_entries.get_count());
    uint32_t counter = 0;
    mask.set_count(count);

    for (auto&& i : ranges::views::iota(size_t{0}, count))
        if ((mask[i] = clients.have_item(m_entries[i]->guid)))
            counter++;

    p_stream->write_lendian_t(static_cast<uint32_t>(cfg_version), p_abort);
    m_common_items_entry->write(p_stream, p_abort);
    m_common_labels_entry->write(p_stream, p_abort);
    p_stream->write_lendian_t(counter, p_abort);

    for (auto&& i : ranges::views::iota(size_t{0}, count))
        if (mask[i])
            m_entries[i]->write(p_stream, p_abort);

    m_common_items_entry->write_extra_data(p_stream, p_abort);
    m_common_labels_entry->write_extra_data(p_stream, p_abort);

    for (auto&& i : ranges::views::iota(size_t{0}, count))
        if (mask[i])
            m_entries[i]->write_extra_data(p_stream, p_abort);

    m_common_items_entry->write_extra_data_v2(p_stream, p_abort);
    m_common_labels_entry->write_extra_data_v2(p_stream, p_abort);

    for (auto&& i : ranges::views::iota(size_t{0}, count))
        if (mask[i])
            m_entries[i]->write_extra_data_v2(p_stream, p_abort);
}

FontManagerData::Entry::Entry()
{
    reset_fonts();
}

void FontManagerData::Entry::reset_fonts()
{
    uGetIconFont(&font_description.log_font);
    font_description.estimate_point_and_dip_size();
}

void FontManagerData::Entry::import(stream_reader* p_reader, size_t stream_size, uint32_t type, abort_callback& p_abort)
{
    fbh::fcl::Reader reader(p_reader, stream_size, p_abort);
    uint32_t element_id;
    uint32_t element_size;

    while (reader.get_remaining()) {
        reader.read_item(element_id);
        reader.read_item(element_size);

        switch (element_id) {
        case identifier_guid:
            reader.read_item(guid);
            break;
        case identifier_mode:
            reader.read_item((uint32_t&)font_mode);
            break;
        case identifier_font:
            reader.read_item(font_description.log_font);
            font_description.estimate_point_and_dip_size();
            break;
        case identifier_point_size_tenths:
            reader.read_item(font_description.point_size_tenths);
            break;
        case identifier_dip_size:
            reader.read_item(font_description.dip_size);
            break;
        case identifier_typographic_font_family: {
            pfc::string8 value;
            reader.read_item(value, element_size);
            font_description.typographic_family_name = mmh::to_utf16(value.c_str());
            break;
        }
        case identifier_weight_stretch_style: {
            std::vector<uint8_t> wss_data(element_size);
            reader.read(wss_data.data(), wss_data.size());

            uih::direct_write::WeightStretchStyle wss;
            stream_reader_memblock_ref wss_reader(wss_data.data(), wss_data.size());

            const auto family_name = wss_reader.read_string(p_abort);
            wss.family_name = mmh::to_utf16(family_name.c_str());

            wss.weight = static_cast<DWRITE_FONT_WEIGHT>(wss_reader.read_lendian_t<int32_t>(p_abort));
            wss.stretch = static_cast<DWRITE_FONT_STRETCH>(wss_reader.read_lendian_t<int32_t>(p_abort));
            wss.style = static_cast<DWRITE_FONT_STYLE>(wss_reader.read_lendian_t<int32_t>(p_abort));

            break;
        }
        case identifier_axis_values: {
            std::vector<uint8_t> axis_values_data(element_size);
            reader.read(axis_values_data.data(), axis_values_data.size());

            stream_reader_memblock_ref axis_values_reader(axis_values_data.data(), axis_values_data.size());
            const auto axis_count = axis_values_reader.read_lendian_t<uint32_t>(p_abort);

            for (auto _ : std::ranges::views::iota(0u, axis_count)) {
                const auto tag = axis_values_reader.read_lendian_t<uint32_t>(p_abort);
                const auto value = axis_values_reader.read_lendian_t<float>(p_abort);
                font_description.axis_values.insert_or_assign(tag, value);
            }
            break;
        }
        default:
            reader.skip(element_size);
            break;
        }
    }
}

void FontManagerData::Entry::_export(stream_writer* p_stream, abort_callback& p_abort)
{
    fbh::fcl::Writer out(p_stream, p_abort);
    out.write_item(identifier_guid, guid);
    out.write_item(identifier_mode, (uint32_t)font_mode);
    if (font_mode == cui::fonts::FontMode::Custom) {
        out.write_item(identifier_font, font_description.log_font);

        if (font_description.wss) {
            const auto& wss = *font_description.wss;

            stream_writer_buffer_simple wss_writer;
            wss_writer.write_string(mmh::to_utf8(wss.family_name).c_str(), p_abort);
            wss_writer.write_lendian_t(gsl::narrow<int32_t>(wss.weight), p_abort);
            wss_writer.write_lendian_t(gsl::narrow<int32_t>(wss.stretch), p_abort);
            wss_writer.write_lendian_t(gsl::narrow<int32_t>(wss.style), p_abort);

            out.write_item(identifier_weight_stretch_style, wss_writer.m_buffer.get_ptr(),
                gsl::narrow<uint32_t>(wss_writer.m_buffer.size()));
        }
    }
    out.write_item(identifier_point_size_tenths, font_description.point_size_tenths);
    out.write_item(identifier_dip_size, font_description.dip_size);
    out.write_item(identifier_typographic_font_family, mmh::to_utf8(font_description.typographic_family_name).c_str());

    if (!font_description.axis_values.empty()) {
        const auto& axis_values = font_description.axis_values;

        stream_writer_buffer_simple axis_values_writer;
        axis_values_writer.write_lendian_t(gsl::narrow<uint32_t>(axis_values.size()), p_abort);

        for (auto [tag, value] : axis_values) {
            axis_values_writer.write_lendian_t(tag, p_abort);
            axis_values_writer.write_lendian_t(value, p_abort);
        }

        out.write_item(identifier_axis_values, axis_values_writer.m_buffer.get_ptr(),
            gsl::narrow<uint32_t>(axis_values_writer.m_buffer.size()));
    }
}

void FontManagerData::Entry::read(uint32_t version, stream_reader* p_stream, abort_callback& p_abort)
{
    p_stream->read_lendian_t(guid, p_abort);
    p_stream->read_lendian_t(reinterpret_cast<uint32_t&>(font_mode), p_abort);
    font_description.log_font = cui::fonts::read_font(p_stream, p_abort);
    font_description.estimate_point_and_dip_size();
}

void FontManagerData::Entry::read_extra_data(stream_reader* stream, abort_callback& aborter)
{
    const auto size = stream->read_lendian_t<uint32_t>(aborter);
    std::vector<uint8_t> data(size);
    stream->read(data.data(), data.size(), aborter);

    stream_reader_memblock_ref extra_reader(data.data(), data.size());

    extra_reader.read_lendian_t(font_description.point_size_tenths, aborter);
    font_description.estimate_dip_size();
}

void FontManagerData::Entry::read_extra_data_v2(stream_reader* stream, abort_callback& aborter)
{
    const auto size = stream->read_lendian_t<uint32_t>(aborter);
    std::vector<uint8_t> data(size);
    stream->read(data.data(), data.size(), aborter);

    stream_reader_memblock_ref extra_reader(data.data(), data.size());

    const auto has_wss = extra_reader.read_lendian_t<bool>(aborter);

    if (!has_wss)
        return;

    uih::direct_write::WeightStretchStyle wss;
    wss.family_name = mmh::to_utf16(mmh::to_string_view(extra_reader.read_string(aborter)));
    wss.weight = static_cast<DWRITE_FONT_WEIGHT>(extra_reader.read_lendian_t<int32_t>(aborter));
    wss.stretch = static_cast<DWRITE_FONT_STRETCH>(extra_reader.read_lendian_t<int32_t>(aborter));
    wss.style = static_cast<DWRITE_FONT_STYLE>(extra_reader.read_lendian_t<int32_t>(aborter));
    font_description.dip_size = extra_reader.read_lendian_t<float>(aborter);
    font_description.wss = wss;

    try {
        font_description.typographic_family_name
            = mmh::to_utf16(mmh::to_string_view(extra_reader.read_string(aborter)));
    } catch (const exception_io_data_truncation&) {
        return;
    }

    uint32_t axis_count{};
    axis_count = extra_reader.read_lendian_t<uint32_t>(aborter);

    uih::direct_write::AxisValues axis_values;
    for (const auto _ : std::views::iota(0u, axis_count)) {
        (void)_;
        const auto tag = extra_reader.read_lendian_t<uint32_t>(aborter);
        const auto value = extra_reader.read_lendian_t<float>(aborter);
        axis_values.insert_or_assign(tag, value);
    }

    font_description.axis_values = axis_values;
}

LOGFONT FontManagerData::Entry::get_normalised_font(unsigned dpi)
{
    LOGFONT lf{font_description.log_font};
    lf.lfHeight = -MulDiv(font_description.point_size_tenths, dpi, 720);
    return lf;
}

void FontManagerData::Entry::write(stream_writer* p_stream, abort_callback& p_abort)
{
    p_stream->write_lendian_t(guid, p_abort);
    p_stream->write_lendian_t((uint32_t)font_mode, p_abort);
    cui::fonts::write_font(p_stream, font_description.log_font, p_abort);
}

void FontManagerData::Entry::write_extra_data(stream_writer* stream, abort_callback& aborter) const
{
    stream_writer_memblock item_stream;
    item_stream.write_lendian_t(font_description.point_size_tenths, aborter);

    stream->write_lendian_t(gsl::narrow<uint32_t>(item_stream.m_data.get_size()), aborter);
    stream->write(item_stream.m_data.get_ptr(), item_stream.m_data.get_size(), aborter);
}

void FontManagerData::Entry::write_extra_data_v2(stream_writer* stream, abort_callback& aborter) const
{
    stream_writer_memblock item_stream;

    if (font_description.wss) {
        item_stream.write_lendian_t(true, aborter);
        const auto& wss = font_description.wss;
        const auto wss_family_name = mmh::to_utf8(wss->family_name);
        item_stream.write_string(wss_family_name, aborter);
        item_stream.write_lendian_t(static_cast<int32_t>(wss->weight), aborter);
        item_stream.write_lendian_t(static_cast<int32_t>(wss->stretch), aborter);
        item_stream.write_lendian_t(static_cast<int32_t>(wss->style), aborter);
        item_stream.write_lendian_t(font_description.dip_size, aborter);
    } else {
        item_stream.write_lendian_t(false, aborter);
    }

    const auto typographic_family_name = mmh::to_utf8(font_description.typographic_family_name);
    item_stream.write_string(typographic_family_name, aborter);

    const auto& axis_values = font_description.axis_values;
    item_stream.write_lendian_t(gsl::narrow<uint32_t>(axis_values.size()), aborter);

    for (const auto [tag, value] : axis_values) {
        item_stream.write_lendian_t(tag, aborter);
        item_stream.write_lendian_t(value, aborter);
    }

    stream->write_lendian_t(gsl::narrow<uint32_t>(item_stream.m_data.get_size()), aborter);
    stream->write(item_stream.m_data.get_ptr(), item_stream.m_data.get_size(), aborter);
}

namespace cui::fonts {

fbh::ConfigInt32 rendering_mode({0x91fdd234, 0x05f9, 0x420c, {0x9c, 0x0c, 0x3d, 0xb9, 0x2f, 0xba, 0x25, 0x06}},
    WI_EnumValue(RenderingMode::Automatic));

fbh::ConfigBool force_greyscale_antialiasing(
    {0xa3d4e205, 0xd623, 0x4da0, {0xa7, 0x3a, 0x03, 0xa6, 0xc9, 0xf8, 0x10, 0xb5}}, false);

fbh::ConfigBool use_custom_emoji_processing(
    {0x80b0de7d, 0x174a, 0x4811, {0xa1, 0xf1, 0x55, 0xe0, 0x73, 0x5d, 0x6a, 0xf0}}, false);

fbh::ConfigString colour_emoji_font_family(
    {0x6ec88989, 0x1249, 0x461a, {0x94, 0x73, 0x95, 0x3c, 0xfb, 0x2e, 0x82, 0xa3}}, "Segoe UI Emoji");

fbh::ConfigString monochrome_emoji_font_family(
    {0x641d9313, 0x319b, 0x4a3a, {0xbe, 0x80, 0x3a, 0x86, 0xef, 0xcb, 0x0a, 0x4a}}, "Segoe UI Symbol");

DWRITE_RENDERING_MODE get_rendering_mode()
{
    switch (static_cast<RenderingMode>(rendering_mode.get())) {
    default:
    case RenderingMode::Automatic: {
        BOOL font_smoothing_enabled{true};
        SystemParametersInfo(SPI_GETFONTSMOOTHING, 0, &font_smoothing_enabled, 0);
        return font_smoothing_enabled ? DWRITE_RENDERING_MODE_DEFAULT : DWRITE_RENDERING_MODE_ALIASED;
    }
    case RenderingMode::DirectWriteAutomatic:
        return DWRITE_RENDERING_MODE_DEFAULT;
    case RenderingMode::Natural:
        return DWRITE_RENDERING_MODE_NATURAL;
    case RenderingMode::NaturalSymmetric:
        return DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC;
    case RenderingMode::GdiClassic:
        return DWRITE_RENDERING_MODE_GDI_CLASSIC;
    case RenderingMode::GdiNatural:
        return DWRITE_RENDERING_MODE_GDI_NATURAL;
    case RenderingMode::GdiAliased:
        return DWRITE_RENDERING_MODE_ALIASED;
    }
}

} // namespace cui::fonts

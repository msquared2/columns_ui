# Change log

## Development version

### Features

- Item details now uses Direct2D for rendering.
  [[#1120](https://github.com/reupen/columns_ui/pull/1120)]

  This includes support for SVG font glyphs on recent versions of Windows,
  including Windows 11 emojis.

- An opt-in experimental alternative emoji processing mode for Windows 8.1 and
  newer was added. [[#1126](https://github.com/reupen/columns_ui/pull/1126)]

  This replaces the default DirectWrite emoji processing to:

  - enable correct handling of emoji variation selectors for emojis that have
    both text (monochrome) and emoji presentation modes
  - use the default presentation mode of emojis as defined in the Unicode
    specification
  - allow custom colour and monochrome emoji fonts to be used

### Bug fixes

- A bug where left and/or top padding was missing in Item details when there was
  no horizontal or vertical scroll bar was fixed.
  [[#1120](https://github.com/reupen/columns_ui/pull/1120)]

- A bug where the `%default_font_size%` and the deprecated `%default_font_face%`
  title formatting fields did not update in Item details after a font change
  until another event caused a content update was fixed.
  [[#1120](https://github.com/reupen/columns_ui/pull/1120)]

## 3.0.0-alpha.5

### Features

- A ‘GDI-compatible, no anti-aliasing’ DirectWrite text rendering mode was
  added. [[#1102](https://github.com/reupen/columns_ui/pull/1102),
  [#1103](https://github.com/reupen/columns_ui/pull/1103),
  [#1104](https://github.com/reupen/columns_ui/pull/1104),
  [#1113](https://github.com/reupen/columns_ui/pull/1113)]

  Additionally, the previous ‘Automatic’ mode has been renamed ‘Automatic
  anti-aliasing’, and a new ‘Default’ mode has been added that selects
  ‘Automatic anti-aliasing’ or ‘GDI-compatible, no anti-aliasing’ based on the
  system ‘Smooth edges of screen fonts’ setting.

### Bug fixes

- A problem where DirectWrite did not render trailing whitespace for centre- and
  right-aligned columns was worked around in list views (playlist view, playlist
  switcher, Filter panel), and the status bar and pane.
  [[#1112](https://github.com/reupen/columns_ui/pull/1112)]

  This workaround does not apply to the Item details panel. To work around it in
  Item details, end the affected line with a zero-width space (`$char(8203)`).

- A bug was fixed where foobar2000 incorrectly appeared in the taskbar after
  running `foobar2000.exe /hide` or invoking the View/Hide main menu command
  when foobar2000 was minimised to the system tray.
  [[#1110](https://github.com/reupen/columns_ui/pull/1110)]

- A bug where the keyboard focus changed after minimising and restoring
  foobar2000 was fixed.
  [[#1109](https://github.com/reupen/columns_ui/pull/1109)]

- Some logic that normally occurs when main window is activated or focused was
  surpressed while foobar2000 is exiting, as that logic is unnecessary at that
  point. [[#1109](https://github.com/reupen/columns_ui/pull/1109)]

- An error message is now shown when trying to use Columns UI on Windows 7 SP1
  without installing the Platform Update for Windows 7.
  [[#1115](https://github.com/reupen/columns_ui/pull/1115)]

  (Previously, this resulted in a crash.)

- A crash following a failure to list available fonts on the Fonts preferences
  page was fixed. [[#1116](https://github.com/reupen/columns_ui/pull/1116)]

- Fonts in use are now refreshed whenever a font is installed or uninstalled in
  Windows, allowing better recovery if a font in use is deleted or replaced.
  [[#1117](https://github.com/reupen/columns_ui/pull/1117)]

- A problem where some panels were notified of font changes multiple times when
  the text rendering mode is changed, or after importing an FCL file, was fixed.
  [[#1105](https://github.com/reupen/columns_ui/pull/1105)]

  This applied to the `ui_config_callback::ui_fonts_changed()` callback.

## 3.0.0-alpha.4

- A bug where DirectWrite-rendered text did not use the correct font family on
  Windows 10 and older versions of Windows 11 was fixed.
  [[#1099](https://github.com/reupen/columns_ui/pull/1099)]

- A bug where typing axis values in the dialogue box opened by the ‘Configure
  variable font axes...’ button on the Fonts preferences tab did not work was
  fixed. [[#1094](https://github.com/reupen/columns_ui/pull/1094)]

- Truncated labels at low system display scale (DPI) setting values in the
  dialogue box opened by the ‘Configure variable font axes...’ button on the
  Fonts preferences tab were corrected.
  [[#1094](https://github.com/reupen/columns_ui/pull/1094)]

- A Windows bug causing a crash on Windows 8.1 when opening the Fonts tab on the
  Colours and fonts preferences page was worked around.
  [[#1098](https://github.com/reupen/columns_ui/pull/1098)]

## 3.0.0-alpha.3

### Bug fixes

- A bug where it wasn’t possible to add new buttons or change existing button
  commands in the Buttons toolbar was fixed.
  [[#1087](https://github.com/reupen/columns_ui/pull/1087)]

## 3.0.0-alpha.2

### Bug fixes

- The ability to use the tab character in playlist group titles to lay out text
  in columns was restored.
  [[#1080](https://github.com/reupen/columns_ui/pull/1080)]

- A bug causing incorrect characters to appear in the the Item details format
  code generator dialogue box title was fixed.
  [[#1076](https://github.com/reupen/columns_ui/pull/1076)]

- Some stylistic inconsistencies in dialogue box titles were fixed.
  [[#1082](https://github.com/reupen/columns_ui/pull/1082)]

- A nicer error message is now logged to the console when using $set_font() with
  a non-existent font family name.
  [[#1081](https://github.com/reupen/columns_ui/pull/1081)]

## 3.0.0-alpha.1

### Features

- Text in list views (such as the playlist view, playlist switcher, Filter panel
  and Item properties), Item details and in the status bar and pane is now
  rendered using DirectWrite.
  [[#897](https://github.com/reupen/columns_ui/pull/897),
  [#904](https://github.com/reupen/columns_ui/pull/904),
  [#910](https://github.com/reupen/columns_ui/pull/910),
  [#913](https://github.com/reupen/columns_ui/pull/913),
  [#915](https://github.com/reupen/columns_ui/pull/915),
  [#919](https://github.com/reupen/columns_ui/pull/919),
  [#924](https://github.com/reupen/columns_ui/pull/924),
  [#925](https://github.com/reupen/columns_ui/pull/925),
  [#926](https://github.com/reupen/columns_ui/pull/926),
  [#936](https://github.com/reupen/columns_ui/pull/936),
  [#947](https://github.com/reupen/columns_ui/pull/947),
  [#953](https://github.com/reupen/columns_ui/pull/953),
  [#967](https://github.com/reupen/columns_ui/pull/967),
  [#969](https://github.com/reupen/columns_ui/pull/969),
  [#974](https://github.com/reupen/columns_ui/pull/974),
  [#976](https://github.com/reupen/columns_ui/pull/976),
  [#981](https://github.com/reupen/columns_ui/pull/981),
  [#989](https://github.com/reupen/columns_ui/pull/989),
  [#1030](https://github.com/reupen/columns_ui/pull/1030),
  [#1031](https://github.com/reupen/columns_ui/pull/1031),
  [#1037](https://github.com/reupen/columns_ui/pull/1037),
  [#1039](https://github.com/reupen/columns_ui/pull/1039),
  [#1042](https://github.com/reupen/columns_ui/pull/1042),
  [#1060](https://github.com/reupen/columns_ui/pull/1060),
  [#1064](https://github.com/reupen/columns_ui/pull/1064),
  [#1070](https://github.com/reupen/columns_ui/pull/1070)]

  This includes colour font support on Windows 8.1 and newer (allowing the use
  of, for example, colour emojis).

  Tabular figures (numerals) are now also used for supported fonts that default
  to proportional figures (such as some Segoe UI variants).

  Customisation of variable font (such as Segoe UI Variable) axes of variation
  is supported on Windows 11 23H2 and newer.

  Some customisation of DirectWrite text rendering is available on the new Text
  rendering tab on the Colours and fonts preferences page.

  Note that there may be slight differences in line heights for these panels
  compared to previous versions, depending on the font, font size and system
  display scale (DPI setting).

- A new DirectWrite-based font picker was added to the Colours and fonts
  preferences page. [[#916](https://github.com/reupen/columns_ui/pull/916),
  [#919](https://github.com/reupen/columns_ui/pull/919),
  [#927](https://github.com/reupen/columns_ui/pull/927),
  [#943](https://github.com/reupen/columns_ui/pull/943),
  [#1015](https://github.com/reupen/columns_ui/pull/1015),
  [#1060](https://github.com/reupen/columns_ui/pull/1060),
  [#1064](https://github.com/reupen/columns_ui/pull/1064)]

  This features better grouping of font families and now allows the entry of
  non-integer font sizes (to one decimal place).

  Note that some font styles will revert to the closest supported GDI equivalent
  when used with a panel that doesn’t use DirectWrite and the latest Columns UI
  API.

  Some legacy font types that aren’t supported by DirectWrite are also no longer
  selectable. Furthermore, some previously hidden fonts may now be visible.

- New `$set_format()` and `$reset_format()` title formatting functions were
  added to Item details.
  [[#1004](https://github.com/reupen/columns_ui/pull/1004),
  [#1011](https://github.com/reupen/columns_ui/pull/1011),
  [#1018](https://github.com/reupen/columns_ui/pull/1018),
  [#1023](https://github.com/reupen/columns_ui/pull/1023),
  [#1062](https://github.com/reupen/columns_ui/pull/1062)]

  These serve as replacements for the older `$set_font()` and `$reset_font()`
  functions.

  [Documentation for `$set_format()` and `$reset_format()`.](https://columns-ui.readthedocs.io/en/latest/item-details/title-formatting.html)

- The `$set_font()` Item details title formatting function now allows
  non-integer font sizes to be specified.
  [[#947](https://github.com/reupen/columns_ui/pull/947)]

- Message boxes now have a consistent appearance, and are dark themed when dark
  mode is active. [[#1041](https://github.com/reupen/columns_ui/pull/1041),
  [#1043](https://github.com/reupen/columns_ui/pull/1043)]

- The positioning of tooltips in list views for centre- and right-aligned
  columns was improved. [[#910](https://github.com/reupen/columns_ui/pull/910)]

- Ctrl+Tab and Shift+Ctrl+Tab can now be used in Tab stack and Playlist tabs to
  switch to the next and previous tab respectively.
  [[#817](https://github.com/reupen/columns_ui/pull/817)]

- An option to make clicking on the Artwork view panel open the displayed image
  in the foobar2000 picture viewer was added on foobar2000 1.6.2 or newer.
  [[#853](https://github.com/reupen/columns_ui/pull/853)]

  This is now the default for new installations.

- A command was added to the Artwork view context menu to open the displayed
  image in the foobar2000 picture viewer on foobar2000 1.6.2 or newer.
  [[#849](https://github.com/reupen/columns_ui/pull/849)]

- Clearing the Filter search toolbar now returns all items in the media library
  if there are no Filter panels in the layout.
  [[#857](https://github.com/reupen/columns_ui/pull/857)]

  This makes the behaviour consistent with what happens when there are Filter
  panels in the layout.

- When using inline editing on multiple tracks in the playlist view and Item
  properties, existing values are now included in the edit box after the text
  `«mixed values»` when the current values of the field differ between the
  tracks. [[#871](https://github.com/reupen/columns_ui/pull/871)]

- The way metadata changes are saved in Item properties and Filter panel was
  improved. [[#863](https://github.com/reupen/columns_ui/pull/863)]

- Deleting layout presets in preferences is now a two-step process to avoid
  accidental deletions. [[#891](https://github.com/reupen/columns_ui/pull/891)]

  (The confirmation dialogue box can be bypassed by holding down Shift while
  clicking the button.)

- Deleting the last layout preset is now prevented instead of reseting layout
  presets to the default preset.
  [[#1053](https://github.com/reupen/columns_ui/pull/1053)]

- References to ‘notification area’ were changed to ‘system tray’ to align with
  the current Windows terminology.
  [[#1035](https://github.com/reupen/columns_ui/pull/1035)]

- Some diagnostic logging to the foobar2000 console was added when unexpected
  errors occur. [[#916](https://github.com/reupen/columns_ui/pull/916)]

### Bug fixes

- A bug sometimes causing the playlist view vertical scroll position to show
  incorrectly after switching playlists was fixed.
  [[#866](https://github.com/reupen/columns_ui/pull/866)]

- A bug with inline editing in the playlist view, Item properties and Filter
  panels where it wasn’t possible to click on autocomplete suggestions was
  fixed. [[#886](https://github.com/reupen/columns_ui/pull/886)]

- A rare drag-and-drop crash was fixed.
  [[#1067](https://github.com/reupen/columns_ui/pull/1067)]

- A bug where files copied in File Explorer couldn’t be pasted in the playlist
  view using the context menu was fixed.
  [[#873](https://github.com/reupen/columns_ui/pull/873)]

- Different handling of ampersands in system tray icon tooltips in Windows 11
  compared to previous versions of Windows was worked around.
  [[#1040](https://github.com/reupen/columns_ui/pull/1040)]

- Various rendering glitches in Playlist tabs and Tab stack when dark mode is
  active were fixed. [[#851](https://github.com/reupen/columns_ui/pull/851)]

- Flickering of scroll buttons in the Playlist tabs and Tab stack when resizing
  the panels was eliminated.
  [[#1033](https://github.com/reupen/columns_ui/pull/1033)]

- When switching tabs, the Tab stack panel now updates the keyboard focus to the
  first focusable element in the new tab.
  [[#817](https://github.com/reupen/columns_ui/pull/817)]

- A Windows bug causing visual glitches after running a full-screen game with
  certain monitor configurations was worked around.
  [[#843](https://github.com/reupen/columns_ui/pull/843)]

- Support for high contrast themes on recent versions of Windows was improved.
  [[#847](https://github.com/reupen/columns_ui/pull/847)]

- A bug in the Buttons toolbar where item group ‘None’ caused the context menu
  command not to be executed was fixed.
  [[#889](https://github.com/reupen/columns_ui/pull/889)]

  Note: An item group of ‘None’ is used to execute a context menu command
  without any tracks, which isn’t normally useful.

- Item details now updates when it’s tracking the current selection and a
  component indicates a custom title formatting field has changed.
  [[#912](https://github.com/reupen/columns_ui/pull/912)]

- The Item details options dialogue box now respects the current dark mode
  setting when opened from the Layout preferences page.
  [[#909](https://github.com/reupen/columns_ui/pull/909)]

- Item properties now updates when a component indicates a custom title
  formatting field has changed.
  [[#912](https://github.com/reupen/columns_ui/pull/912)]

  (Although Item properties doesn’t use title formatting, this change makes the
  panel update when things like playback statistics change.)

- The vertical item padding in Item properties and some list views in
  preferences now scales with the system display scale (DPI setting).
  [[#925](https://github.com/reupen/columns_ui/pull/925)]

- A bug where the status bar may crash when using a very small font size was
  fixed. [[#935](https://github.com/reupen/columns_ui/pull/935)]

- A bug where dynamic internet radio artwork may not have been immediately shown
  after changing the ‘Displayed track’ in the Artwork view panel was fixed.
  [[#854](https://github.com/reupen/columns_ui/pull/854)]

- A bug where the ‘Alignment’ label in the Columns tab of the Playlist view
  preferences page was clipped for some display scale values was fixed.
  [[#959](https://github.com/reupen/columns_ui/pull/959)]

- A bug where the playlist view did not always re-render correctly when toggling
  the ‘Show column titles’ option was fixed.
  [[#983](https://github.com/reupen/columns_ui/pull/983)]

- Command-line help was updated to include previously undocumented export
  commands. [[#1048](https://github.com/reupen/columns_ui/pull/1048)]

- Concurrent modal dialogue boxes are now morely consistently avoided in line
  with foobar2000 conventions.
  [[#1050](https://github.com/reupen/columns_ui/pull/1050)]

### Internal changes

- Handling of fatal unexpected C++ exceptions was improved in some scenarios.
  [[#1049](https://github.com/reupen/columns_ui/pull/1049)]

- Various dependencies were updated.
  [[#920](https://github.com/reupen/columns_ui/pull/920)]

- The component is now compiled using foobar2000 SDK 2024-12-03.
  [[#833](https://github.com/reupen/columns_ui/pull/833),
  [#972](https://github.com/reupen/columns_ui/pull/972),
  [#1050](https://github.com/reupen/columns_ui/pull/1050)]

- The component is now compiled with Visual Studio 2022 17.12.

- Some internal changes were made to clean up and modernise code.

## 2.1.0

### Features

- Dark menus were enabled on Windows 11 builds greater than 22631.
  [[#788](https://github.com/reupen/columns_ui/pull/788), contributed by
  [@razielanarki](https://github.com/razielanarki)]

### Bug fixes

- A bug where the empty area at the bottom of a playlist view with a small
  number of items did not immediately update after changing the background
  colour in preferences was fixed.
  [[#804](https://github.com/reupen/columns_ui/pull/804)]

- The tab order of controls on the Grouping tab on the playlist view preferences
  page was corrected. [[#781](https://github.com/reupen/columns_ui/pull/781)]

- A problem where messages containing 'Unsupported format or corrupted file'
  were logged to the console when adding a new playlist view panel to the layout
  was fixed. [[#806](https://github.com/reupen/columns_ui/pull/806)]

- A problem where 'UnregisterClass failed: Class does not exist.' was logged to
  the console when quitting foobar2000 was fixed.
  [[#802](https://github.com/reupen/columns_ui/pull/802)]

- The copyright year was updated.
  [[#803](https://github.com/reupen/columns_ui/pull/803)]

### Internal changes

- The component is now compiled using foobar2000 SDK 2023-05-10.
  [[#799](https://github.com/reupen/columns_ui/pull/799)]

- The component is now compiled with Visual Studio 2022 17.7.

## 2.1.0-beta.3

### Bug fixes

- Performance regressions in the playlist view during operations such as sorting
  were fixed. [[#776](https://github.com/reupen/columns_ui/pull/776)]

## 2.1.0-beta.2

### Features

- Indentation of grouping levels in the playlist view was made configurable.
  [[#774](https://github.com/reupen/columns_ui/pull/774)]

  The default configuration matches the behaviour of Columns UI 2.0.0.

## 2.1.0-beta.1

### Features

- A playlist selector toolbar was added.
  [[#729](https://github.com/reupen/columns_ui/pull/729)]

- Grouping in the built-in playlist view was updated
  [[#770](https://github.com/reupen/columns_ui/pull/770)]:

  - each grouping level is no longer indented
  - padding either side of artwork was reduced
  - artwork reflection is now disabled by default

- The built-in playlist view now remembers vertical scroll positions of
  playlists after closing and reopening foobar2000, on foobar2000 2.0 and newer.
  [[#742](https://github.com/reupen/columns_ui/pull/742),
  [#743](https://github.com/reupen/columns_ui/pull/743)]

- If the focused item in a non-active playlist changes, the built-in playlist
  view now scrolls to that focused item when the playlist is next activated.
  [[#746](https://github.com/reupen/columns_ui/pull/746)]

- In the playlist switcher and playlist tabs, when adding items to a playlist
  using drag and drop, the first new item added to the playlist is now focused.
  [[#746](https://github.com/reupen/columns_ui/pull/746)]

- The behaviour of Ctrl+Backspace and Ctrl+A was made consistent across edit
  controls that are part of Columns UI itself.
  [[#735](https://github.com/reupen/columns_ui/pull/735),
  [#740](https://github.com/reupen/columns_ui/pull/740)]

- A built-in icon for the stop after current command was added to the Buttons
  toolbar. [[#757](https://github.com/reupen/columns_ui/pull/757),
  [#762](https://github.com/reupen/columns_ui/pull/762)]

- When title formatting is used in the playlist switcher panel, typing in the
  panel now always searches by the actual playlist name and not the displayed
  title. [[#738](https://github.com/reupen/columns_ui/pull/738)]

- The Item details panel no longer reads full metadata from non-playing files on
  foobar2000 2.0 and newer, as full metadata is always available on these
  versions. [[#734](https://github.com/reupen/columns_ui/pull/734)]

- Dark menus were enabled on Windows 11 build 22631.
  [[#771](https://github.com/reupen/columns_ui/pull/771)]

### Bug fixes

- In the themed and system colour schemes, if ‘Use custom active item frame’ is
  enabled, the configured colour is now correctly shown on the preferences page
  and used for the focused item frame in supported panels.
  [[#754](https://github.com/reupen/columns_ui/pull/754)]

  Previously, changing the colour had no effect on the actual colour used or
  shown in preferences. If you were using the themed or system colour schemes
  and had ‘Use custom active item frame’ enabled, the colour of the focused item
  frame may change after upgrading due to the saved custom colour now correctly
  being used.

- List views no longer use a dotted active (focused) item frame by default in
  dark mode when the themed scheme is active.
  [[#755](https://github.com/reupen/columns_ui/pull/755)]

- Inline editing in list views now always saves and exits when clicking outside
  the edit box. [[#769](https://github.com/reupen/columns_ui/pull/769)]

- A problem causing a slight delay when starting playback of a track was worked
  around. [[#766](https://github.com/reupen/columns_ui/pull/766)]

- Tooltips in the buttons toolbar, seekbar and volume bar are now dark themed
  when dark mode is active.
  [[#760](https://github.com/reupen/columns_ui/pull/760),
  [#764](https://github.com/reupen/columns_ui/pull/764)]

- If the system DPI setting changes between foobar2000 sessions, the main window
  size is now adjusted accordingly when foobar2000 starts.
  [[#732](https://github.com/reupen/columns_ui/pull/732)]

- Live editing no longer misbehaves when right-clicking on scroll bars.
  [[#741](https://github.com/reupen/columns_ui/pull/741)]

- Visual glitches when toggling the Show toolbars option were fixed.
  [[#750](https://github.com/reupen/columns_ui/pull/750)]

- In the playlist tabs and tab stack panels, a small rendering glitch below the
  left and right scroll buttons when scrolling left and right with dark mode
  enabled was fixed. [[#737](https://github.com/reupen/columns_ui/pull/737)]

### Internal changes

- The component is now compiled with Visual Studio 2022 17.6.

## 2.0.0

### Bug fixes

- Scroll bars in the DSP preset and output device toolbars now have a dark
  appearance when dark mode is active.
  [[#703](https://github.com/reupen/columns_ui/pull/703)]

- A GDI-object leak when closing the Item properties options dialogue box on
  older versions of Windows was fixed.
  [[#704](https://github.com/reupen/columns_ui/pull/704)]

- Certain internet radio streams no longer have a negative length in the
  playlist switcher, status bar and status pane on foobar2000 2.0.
  [[#721](https://github.com/reupen/columns_ui/pull/721)]

- In the playlist tabs and tab stack panels, the hover item now rerenders
  correctly after using the mouse wheel.
  [[#723](https://github.com/reupen/columns_ui/pull/723)]

- Some buttons toolbar console messages were updated to refer to hover icons
  instead of hot images. [[#708](https://github.com/reupen/columns_ui/pull/708)]

### Internal changes

- The component is now compiled using foobar2000 SDK 2023-04-18.
  [[#699](https://github.com/reupen/columns_ui/pull/699)]

## 2.0.0-rc.1

### Features

- Dark mode support was added to various dialogue boxes.
  [[#673](https://github.com/reupen/columns_ui/pull/673),
  [#676](https://github.com/reupen/columns_ui/pull/676),
  [#679](https://github.com/reupen/columns_ui/pull/679),
  [#682](https://github.com/reupen/columns_ui/pull/682),
  [#683](https://github.com/reupen/columns_ui/pull/683),
  [#685](https://github.com/reupen/columns_ui/pull/685),
  [#686](https://github.com/reupen/columns_ui/pull/686),
  [#688](https://github.com/reupen/columns_ui/pull/688) (contributed by
  [@marc2k3](https://github.com/marc2k3)),
  [#689](https://github.com/reupen/columns_ui/pull/689),
  [#692](https://github.com/reupen/columns_ui/pull/692),
  [#695](https://github.com/reupen/columns_ui/pull/695),
  [#697](https://github.com/reupen/columns_ui/pull/697)]

- Dark menus were enabled on Windows 11 build 22624.
  [[#680](https://github.com/reupen/columns_ui/pull/680), contributed by
  [@marc2k3](https://github.com/marc2k3)]

### Bug fixes

- A crash when artwork is enabled in the playlist view and certain input
  components are used was fixed.
  [[#684](https://github.com/reupen/columns_ui/pull/684)]

- The title bar of a maximised main window now correctly updates when switching
  between light and dark mode on Windows 10.
  [[#696](https://github.com/reupen/columns_ui/pull/696)]

### Internal changes

- Various dependencies were updated.
  [[#674](https://github.com/reupen/columns_ui/pull/674)]

- Compiler options were updated.
  [[#675](https://github.com/reupen/columns_ui/pull/675)]

## 2.0.0-beta.2

### Features

- The left and right scroll buttons in the Tab stack and Playlist tabs panels
  are now dark themed on all supported operating systems when dark mode is
  enabled. [[#666](https://github.com/reupen/columns_ui/pull/666)]

  (Previously, they were only dark themed on Windows 11 22H2 and newer.)

- A Play command was added to the playlist view context menu when right-clicking
  on a single track. [[#665](https://github.com/reupen/columns_ui/pull/665)]

### Bug fixes

- A bug where panel captions rendered in the background of some panels was
  fixed. [[#659](https://github.com/reupen/columns_ui/pull/659), contributed by
  [@marc2k3](https://github.com/marc2k3)]

- Minor rendering glitches relating to the scroll buttons in the Tab stack and
  Playlist tabs panels with dark mode enabled were fixed.
  [[#666](https://github.com/reupen/columns_ui/pull/666)]

### Internal changes

- The component is now compiled with Visual Studio 2022 17.5.

- The component is now compiled using foobar2000 SDK 2023-02-22.
  [[#660](https://github.com/reupen/columns_ui/pull/660),
  [#667](https://github.com/reupen/columns_ui/pull/667)]

## 2.0.0-beta.1

### Features

- Support for static [SVG files](https://en.wikipedia.org/wiki/SVG) was added to
  the Buttons toolbar. [[#628](https://github.com/reupen/columns_ui/pull/628),
  [#643](https://github.com/reupen/columns_ui/pull/643)]

  This requires the [SVG services component](https://yuo.be/svg-services).

- Built-in icons in non-standard sizes are now rendered using an
  [SVG image](https://en.wikipedia.org/wiki/SVG) when the
  [SVG services component](https://yuo.be/svg-services) is installed.
  [[#650](https://github.com/reupen/columns_ui/pull/650)]

  This improves quality for icons displayed in sizes where a pre-rendered
  version in that size isn’t bundled in Columns UI.

- Performance when typing into the playlist view to jump to an item was improved
  in foobar2000 2.0. [[#629](https://github.com/reupen/columns_ui/pull/629)]

- Autocompletion was added when editing metadata in the Item properties panel
  [[#647](https://github.com/reupen/columns_ui/pull/647)]

  The list of values is provided by the foobar2000 core and can be configured in
  Advanced preferences, under Display/Autocomplete fields.

- Autocompletion in playlist view inline editing was updated to use the latest
  foobar2000 API on foobar2000 1.6.1 and newer.
  [[#647](https://github.com/reupen/columns_ui/pull/647)]

- Dark menus were enabled on Windows 11 build 22623.
  [[#649](https://github.com/reupen/columns_ui/pull/649)]

### Bug fixes

- A bug where ampersands didn’t render correctly in tab names in the Playlist
  tabs and Tab stack panels when dark mode is active was fixed.
  [[#622](https://github.com/reupen/columns_ui/pull/622)]

- A bug where toggling the Alternative selection model playlist view option
  didn’t function correctly was fixed.
  [[#623](https://github.com/reupen/columns_ui/pull/623)]

- A crash when a third-party spiltter incorrectly destroys a built-in panel was
  resolved. [[#624](https://github.com/reupen/columns_ui/pull/624)]

- Excess top and bottom button padding in a buttons toolbar in ‘no edges’ mode
  was removed. [[#638](https://github.com/reupen/columns_ui/pull/638)]

- Various truncated labels in the Buttons toolbar options dialogue box were
  corrected. [[#641](https://github.com/reupen/columns_ui/pull/641), contributed
  by [@marc2k3](https://github.com/marc2k3)]

### Internal changes

- The component is now compiled with Visual Studio 2022 17.4.

- The component is now compiled using foobar2000 SDK 2022-10-20.
  [[#625](https://github.com/reupen/columns_ui/pull/625),
  [#626](https://github.com/reupen/columns_ui/pull/626)]

## 2.0.0-alpha.5

### Features

- A further improvement was made to the performance of the Filter panel when
  handling dynamic media library changes.
  [[#615](https://github.com/reupen/columns_ui/pull/615)]

## 2.0.0-alpha.4

### Features

- The performance of the Filter panel when handling dynamic media library
  changes was improved. [[#609](https://github.com/reupen/columns_ui/pull/609),
  [#611](https://github.com/reupen/columns_ui/pull/611)]

  This includes reducing Filter panel initialisation time in foobar2000 2.0
  during foobar2000 start-up.

- The Filter panel no longer reports initialisation times in foobar2000 2.0 when
  it loads before the media library has initialised.
  [[#612](https://github.com/reupen/columns_ui/pull/612)]

### Bug fixes

- A crash, when clicking Move down on the Grouping tab in playlist view
  preferences without a group selected, was fixed.
  [[#613](https://github.com/reupen/columns_ui/pull/613)]

- Flickering when switching tabs in the Tab stack panel was reduced.
  [[#610](https://github.com/reupen/columns_ui/pull/610)]

## 2.0.0-alpha.3

### Bug fixes

- A crash in 64-bit builds after adding a Tab stack to the layout was fixed.
  [[#606](https://github.com/reupen/columns_ui/pull/606)]

- A problem in the Quick setup dialogue box where selecting a layout preset had
  no effect was fixed. [[#607](https://github.com/reupen/columns_ui/pull/607)]

## 2.0.0-alpha.2

### Features

- A 64-bit build (for x64 processors) was added for 64-bit versions of
  foobar2000 2.0 and newer.
  [[#568](https://github.com/reupen/columns_ui/pull/568)]

- Performance under foobar2000 2.0 was improved.
  [[#585](https://github.com/reupen/columns_ui/pull/585),
  [#587](https://github.com/reupen/columns_ui/pull/587),
  [#588](https://github.com/reupen/columns_ui/pull/588),
  [#591](https://github.com/reupen/columns_ui/pull/591)]

- Various built-in pop-up foobar2000 windows (e.g. Album List, Search, Playlist
  Manager) now use Columns UI colours and fonts when Columns UI is active.
  [[#574](https://github.com/reupen/columns_ui/pull/574),
  [#579](https://github.com/reupen/columns_ui/pull/579),
  [#590](https://github.com/reupen/columns_ui/pull/590)]

  This requires foobar2000 2.0 or newer.

  For colours, only the text, background and selection background colours can be
  explicitly configured. The equivalent of the Default UI highlight colour
  currently isn’t configurable.

  For fonts, the default, list items and console fonts can be individually
  configured.

  These changes also apply to any third-party components that use new colour and
  font APIs added in foobar2000 2.0

- Dark mode support was added for Columns UI preference pages when using
  foobar2000 2.0. [[#582](https://github.com/reupen/columns_ui/pull/582),
  [#592](https://github.com/reupen/columns_ui/pull/592),
  [#595](https://github.com/reupen/columns_ui/pull/595)]

  Other dialogue boxes will follow in a future release.

- Dark menus were enabled on Windows 11 version 22H2.
  [[#594](https://github.com/reupen/columns_ui/pull/594), contributed by
  [@marc2k3](https://github.com/marc2k3)]

- An audio track toolbar was added. When a file containing multiple audio tracks
  (e.g. different languages) is playing, this toolbar allows you to select
  between those tracks. [[#573](https://github.com/reupen/columns_ui/pull/573)]

  It requires foobar2000 2.0 or newer and is equivalent to the ‘Stream Selector’
  toolbar in the Default User Interface.

- The edit box that appears when using inline editing in Columns UI list views
  now has a dark appearance when dark mode is on.
  [[#593](https://github.com/reupen/columns_ui/pull/593)]

- When mixed size images are used in the buttons toolbar, they are now all
  resized to the same size.
  [[#548](https://github.com/reupen/columns_ui/pull/548)]

  (Previously, images in the wrong size would display incorrectly or other
  problems would occur.)

  A message is also printed to the console when mixed size custom images are
  detected.

- A custom icon size can now be used in the buttons toolbar.
  [[#552](https://github.com/reupen/columns_ui/pull/552)]

  If set, custom images will be resized as necessary.

- The buttons toolbar options dialogue box was updated, with some terminology
  changed. [[#552](https://github.com/reupen/columns_ui/pull/552)]

- Additional sizes of the default playback button icons were added to improve
  their rendering at certain system DPI settings.
  [[#554](https://github.com/reupen/columns_ui/pull/554)]

- The default stop button icon was tweaked.
  [[#554](https://github.com/reupen/columns_ui/pull/554)]

- Active tabs in the Tab stack and Playlist tabs panels no longer change colour
  on hover when dark mode is active.
  [[#549](https://github.com/reupen/columns_ui/pull/549)]

### Bug fixes

- Various problems relating to configuring a custom active item frame colour
  were fixed. [[#581](https://github.com/reupen/columns_ui/pull/581)]

- A bug where the padding of buttons in the buttons toolbar changed when a
  system notification about a setting change was received was fixed.
  [[#562](https://github.com/reupen/columns_ui/pull/562)]

- A bug which stopped ICO files from working as custom hot images in the buttons
  toolbar was fixed. [[#547](https://github.com/reupen/columns_ui/pull/547)]

- A GDI object leak when using ICO files as custom button images was fixed.
  [[#547](https://github.com/reupen/columns_ui/pull/547)]

- The initial widths of the list view columns in the Buttons and Item properties
  options dialogue boxes were updated to scale with the system DPI setting.
  [[#550](https://github.com/reupen/columns_ui/pull/550)]

- Rendering glitches in the edit box that appears during inline editing in
  Columns UI list views were fixed.
  [[#593](https://github.com/reupen/columns_ui/pull/593)]

- A truncated label in the Item properties options dialogue box was corrected.
  [[#550](https://github.com/reupen/columns_ui/pull/550)]

### Removals

- Exported buttons toolbar configurations (FCB files) aren’t compatible with
  older versions of Columns UI.
  [[#552](https://github.com/reupen/columns_ui/pull/552)]

- Exported configurations (FCL files) containing a buttons toolbar in the layout
  aren’t compatible with older versions of Columns UI.
  [[#552](https://github.com/reupen/columns_ui/pull/552)]

### Internal changes

- The component is now compiled with Visual Studio 2022 17.3.

- The component is now compiled using foobar2000 SDK 2022-08-29.
  [[#568](https://github.com/reupen/columns_ui/pull/568),
  [#575](https://github.com/reupen/columns_ui/pull/575)]

## 2.0.0-alpha.1

### Features

- Support for the Windows 10 and 11 dark mode was added on Windows 10 version
  2004 and newer.
  [[multiple pull requests](https://github.com/reupen/columns_ui/pulls?q=is%3Apr+is%3Aclosed+label%3A%22dark+mode%22+merged%3A%3C%3D2022-04-21)]

  This can be enabled from the Mode tab on the Colours and fonts preferences
  page.

  Light and dark modes have independent colour settings. However, any custom
  colours that are currently active will be copied to dark mode settings on
  upgrade.

  The default value for a custom colour can be reselected by clicking on the
  Change... button for that colour, and selecting the first colour from the
  'Custom colours:' section of the colour picker dialogue box.

  Dark menus aren’t enabled on Windows 11 builds newer than 22598. This is to
  avoid unexpected problems on untested builds, because the Windows APIs to
  enable dark menus aren’t public.

  Third-party panels that contain system UI elements like scroll bars will need
  updating to fully support dark mode.

  The previous mode setting on the Colours tab of Colours and fonts preferences
  has been renamed scheme to disambiguate it from the new mode setting.

- The shading of alternate rows in the playlist view was disabled by default in
  new installations. [[#522](https://github.com/reupen/columns_ui/pull/522)]

  It can still be enabled (in new installations) by uncommenting the second line
  in the default global style script.

- Status bar and status pane preferences were fully separated.
  [[#516](https://github.com/reupen/columns_ui/pull/516)]

- The status bar can now show the number of selected tracks.
  [[#450](https://github.com/reupen/columns_ui/pull/450), contributed by
  [@m0vie](https://github.com/m0vie)]

- Improvements were made to the status bar layout logic (including better DPI
  scaling). [[#432](https://github.com/reupen/columns_ui/pull/432)]

- The status bar playlist lock icon was updated.
  [[#432](https://github.com/reupen/columns_ui/pull/432),
  [#513](https://github.com/reupen/columns_ui/pull/513)]

- The default playback button icons were tweaked. This includes the removal of
  subtle glow effects. [[#435](https://github.com/reupen/columns_ui/pull/435),
  [#463](https://github.com/reupen/columns_ui/pull/463),
  [#474](https://github.com/reupen/columns_ui/pull/474)]

- The spectrum analyser is now integrated with the Colours and fonts preferences
  page, and its foreground colour and background colour are now configured
  there. [[#466](https://github.com/reupen/columns_ui/pull/466),
  [#470](https://github.com/reupen/columns_ui/pull/470),
  [#473](https://github.com/reupen/columns_ui/pull/473),
  [#514](https://github.com/reupen/columns_ui/pull/514),
  [#540](https://github.com/reupen/columns_ui/pull/540)]

- The Filter search toolbar is now integrated with the Colours and fonts
  preferences page, and its font, foreground colour and background colour are
  now configurable. [[#424](https://github.com/reupen/columns_ui/pull/424),
  [#482](https://github.com/reupen/columns_ui/pull/482)]

  (Note that selection colours are not supported.)

- The Filter search button icons were updated.
  [[#438](https://github.com/reupen/columns_ui/pull/438)]

- The default no-cover artwork image was updated.
  [[#437](https://github.com/reupen/columns_ui/pull/437)]

- The 'View/Show toolbars' menu item is now only shown if the shift key is held
  down when opening the View menu.
  [[#410](https://github.com/reupen/columns_ui/pull/410)]

- A warning was added under the 'Show toolbars' option in preferences.
  [[#410](https://github.com/reupen/columns_ui/pull/410)]

### Bug fixes

- A problem where the playlist tabs panel had an incorrect maximum width or
  height was fixed. [[#449](https://github.com/reupen/columns_ui/pull/449)]

- The hover colour of text in a buttons toolbar in flat mode was corrected so
  that it is typically white in light mode.
  [[#479](https://github.com/reupen/columns_ui/pull/479)]

  (This change has the side effect of an uglier hover animation on some versions
  of Windows.)

- Flickering when resizing the Playlist tabs and Tab stack panels was
  eliminated. [[#451](https://github.com/reupen/columns_ui/pull/451)]

- Flickering of panel captions when resizing a panel was eliminated.
  [[#496](https://github.com/reupen/columns_ui/pull/496)]

- Various glitches with the rendering of toolbar sizing grips were fixed.
  [[#495](https://github.com/reupen/columns_ui/pull/495),
  [#497](https://github.com/reupen/columns_ui/pull/497)]

- Various bugs with the positioning and sizing of panel captions were fixed.
  [[#418](https://github.com/reupen/columns_ui/pull/418)]

- The status bar pop-up volume bar now correctly scales with the system DPI
  setting. [[#418](https://github.com/reupen/columns_ui/pull/418)]

- The position of seekbar and volume bar tooltips relative to the pointer
  position was corrected so that it's based on the actual pointer size, rather
  than a fixed offset. [[#494](https://github.com/reupen/columns_ui/pull/494)]

- The item indentation of the layout tree on the Layout preferences page was
  corrected to scale with the system DPI setting.
  [[#517](https://github.com/reupen/columns_ui/pull/517)]

- Various truncated labels in preferences were corrected.
  [[#469](https://github.com/reupen/columns_ui/pull/469),
  [#516](https://github.com/reupen/columns_ui/pull/516)]

### Removals

- Support for foobar2000 1.4 was removed. foobar2000 1.5 is now the minimum
  version required.

### Internal changes

- The component is now compiled using Visual Studio 2022 17.1 and the /std:c++20
  compiler option. [[#408](https://github.com/reupen/columns_ui/pull/408),
  [#409](https://github.com/reupen/columns_ui/pull/409)]

- The component is now compiled using foobar2000 SDK 2022-01-04.
  [[#419](https://github.com/reupen/columns_ui/pull/419)]

- Preliminary work towards 64-bit support was undertaken.
  [[#457](https://github.com/reupen/columns_ui/pull/457),
  [#467](https://github.com/reupen/columns_ui/pull/467)]

## 1.7.0

- There were no changes from version 1.7.0-beta.2.

## 1.7.0-beta.2

### Features

- The DSP preset, Output device, Playback order and ReplayGain mode toolbars are
  now integrated with the Colours and fonts preferences page, and their fonts,
  foreground colours and background colours are now configurable.
  [[#390](https://github.com/reupen/columns_ui/pull/390) (contributed by
  [@rplociennik](https://github.com/rplociennik)),
  [#392](https://github.com/reupen/columns_ui/pull/392),
  [#397](https://github.com/reupen/columns_ui/pull/397)]

  (Note that selection colours are not supported.)

- A new Output format toolbar was added, allowing the selection of the output
  bit depth for output devices that don’t use automatic output format selection.
  [[#389](https://github.com/reupen/columns_ui/pull/389), contributed by
  [@rplociennik](https://github.com/rplociennik)]

- The DSP preset toolbar now displays the text '(no DSP presets exist)' if no
  DSP presets have been created.
  [[#395](https://github.com/reupen/columns_ui/pull/395)]

### Bug fixes

- The minimum widths of the DSP preset and Output device toolbars now update if
  the list of DSP presets or output devices changes.
  [[#393](https://github.com/reupen/columns_ui/pull/393)]

  Note that this only happens when the drop-down list in the toolbar is clicked
  on or otherwise expanded, as this is the only time the lists of DSP presets
  and output devices are refreshed.

### Internal changes

- The component is now compiled using Visual Studio 2019 16.11.

## 1.7.0-beta.1

### Features

- Support for dynamic internet radio front cover images was added to the Artwork
  view panel. [[#367](https://github.com/reupen/columns_ui/pull/367)]

  (Requires foobar2000 1.6.6 or newer.)

- Support for back cover, disc and artist stub images was added to the Artwork
  view panel. [[#345](https://github.com/reupen/columns_ui/pull/345)]

- In the Artwork view panel, when the artwork type is not locked and the panel
  automatically switches to a different artwork type, it now returns to the
  previously selected artwork type once it’s available again.
  [[#368](https://github.com/reupen/columns_ui/pull/368),
  [#381](https://github.com/reupen/columns_ui/pull/381)]

- A 'Reload artwork' command was added to the artwork view context menu. This
  forces a reload of artwork from source using current settings.
  [[#351](https://github.com/reupen/columns_ui/pull/351),
  [#382](https://github.com/reupen/columns_ui/pull/382)]

- The list view scrolling speed when selecting items or using drag and drop was
  adjusted to be slower, particularly for short lists such as in Buttons
  options. [[#349](https://github.com/reupen/columns_ui/pull/349)]

- The Item properties and Item details panels now expand and align tab
  characters. [[#350](https://github.com/reupen/columns_ui/pull/350)]

- When multiple tracks are selected and some of them have a value for a
  particular metadata field and some do not, the Item properties panel now makes
  this clearer by appending '(not set)' to the list of values for that field.
  [[#370](https://github.com/reupen/columns_ui/pull/370)]

- The Item properties panel now shows '(blank)' for a metadata field if it’s set
  but the value is an empty string.
  [[#370](https://github.com/reupen/columns_ui/pull/370)]

- The Filter panel no longer focuses the first playlist item when using any of
  the send to playlist commands or actions. This improves compatibility with
  shuffle playback modes when 'Playback follows cursor' is enabled.
  [[#352](https://github.com/reupen/columns_ui/pull/352)]

- In the playlist view, group titles now respect the 'Display ellipses in
  truncated text' option.

### Bug fixes

- A bug causing misbehaviour of colour codes or a possible crash after scrolling
  in the Item details panel was fixed.
  [[#372](https://github.com/reupen/columns_ui/pull/372)]

- A problem in the Buttons toolbar preventing buttons for certain File
  operations context menu commands from working was fixed.
  [[#379](https://github.com/reupen/columns_ui/pull/379)]

  (Note that any existing such buttons won’t be automatically fixed; the command
  will need to be reselected or the button recreated for the button to work.)

- A problem where panels were queried for configuration data too frequently
  following [#320](https://github.com/reupen/columns_ui/pull/320) was resolved.
  [[#364](https://github.com/reupen/columns_ui/pull/364)]

- A problem where GDI+ was used to load stub artwork images in the Artwork view
  panel instead of the Windows Imaging Component (WIC) was fixed
  [[#371](https://github.com/reupen/columns_ui/pull/371)].

  (See [the change log for version 1.4.0-beta.1](#140-beta1) for more details on
  what this means.)

### Internal changes

- The `Zc:threadSafeInit-` compiler option is no longer used.
  [[#340](https://github.com/reupen/columns_ui/pull/340)]

- The component is now compiled using Visual Studio 2019 16.10.

- The component is now compiled using foobar2000 SDK 2021-02-23.
  [[#362](https://github.com/reupen/columns_ui/pull/362),
  [#363](https://github.com/reupen/columns_ui/pull/363)]

## 1.6.0

### Features

- SSE2 instructions are now enabled (and hence are now required).
  [[#329](https://github.com/reupen/columns_ui/pull/329)]

- Items details now tries to preserve the scroll position when adjusting
  settings. [[#335](https://github.com/reupen/columns_ui/pull/335)]

### Bug fixes

- The positioning of lines in Item details when a font change was immediately
  followed by a colour change was corrected.
  [[#338](https://github.com/reupen/columns_ui/pull/338)]

  Additionally, font changes that don’t affect any text (e.g. due to being
  immediately followed by another font change) now correctly affect the height
  of the line.

- A bug was fixed where it sometimes wasn't possible to scroll to the very
  bottom of Items details when both horizontal and vertical scroll bars were
  visible. [[#335](https://github.com/reupen/columns_ui/pull/335)]

- Miscalculated bottom padding in the background of some dialogues at high DPIs
  was fixed. [[#334](https://github.com/reupen/columns_ui/pull/334)]

### Internal changes

- The component is now compiled using foobar2000 SDK 2020-07-28.
  [[#329](https://github.com/reupen/columns_ui/pull/329)]

## 1.5.0

### Features

- Filter search now allows the use of
  [time-based expressions](https://wiki.hydrogenaud.io/index.php?title=Foobar2000:Query_syntax#Time_expressions).
  [[#300](https://github.com/reupen/columns_ui/pull/300)]

  Note that these currently don’t update continuously when results change due to
  e.g. the system time advancing.

### Bug fixes

- Custom Album list panel active item frame colours are now included in exported
  FCL files. [[#316](https://github.com/reupen/columns_ui/pull/316)]

- A crash or other unexpected behaviour when certain emojis were displayed in
  the Item details panel was fixed.
  [[#323](https://github.com/reupen/columns_ui/pull/323),
  [#324](https://github.com/reupen/columns_ui/pull/324)]

  Word-wrapping behaviour may be slightly different from earlier versions as a
  result of the fix.

- A bug where a panel copied during live editing may have had stale
  configuration data was fixed.
  [[#320](https://github.com/reupen/columns_ui/pull/320)]

- The Item properties panel no longer has tab-based alignment and columns
  enabled, due to the confusing behaviour caused when tab characters are
  encountered in metadata.
  [[#319](https://github.com/reupen/columns_ui/pull/319)]

### Internal changes

- The component is now compiled using Visual Studio 2019 16.6.

## 1.4.1

### Bug fixes

- A regression in the buttons toolbar, which may have caused the loading of
  custom images with relative paths to fail, was fixed.
  [[#298](https://github.com/reupen/columns_ui/pull/298)]

## 1.4.0

### Bug fixes

- Zero-length artwork images are now ignored. (Previously, an error was logged
  in the console when they were encountered.)
  [[#294](https://github.com/reupen/columns_ui/pull/294)]

## 1.4.0-rc.1

### Bug fixes

- A problem reading artwork from Windows Media files, and using certain
  third-party input components, was worked around.
  [[#292](https://github.com/reupen/columns_ui/pull/292)]

## 1.4.0-beta.1

### Removals

- The artwork source settings in Columns UI were removed and now only the
  settings on the main Display preferences page are used.

  If Columns UI artwork source settings were in use, you will be prompted to
  transfer your settings on upgrade.
  [[#286](https://github.com/reupen/columns_ui/pull/286)]

- The playlist view ‘Low artwork reader thread priority’ setting was removed; a
  low thread priority is now always used.
  [[#270](https://github.com/reupen/columns_ui/pull/270)]

- The ability to display tooltips for non-truncated text in the playlist view
  was removed. [[#272](https://github.com/reupen/columns_ui/pull/272)]

### Features

- The Windows Imaging Component is now used to load button images, and artwork
  in the artwork panel and playlist view.

  On recent versions of Windows 10, this adds support for WebP and HEIF images
  if the required codecs are installed. These are usually installed
  automatically, but can also be manually installed from the Microsoft Store:

  - [WebP image extensions](https://www.microsoft.com/en-gb/p/webp-image-extensions/9pg2dk419drg)
  - [HEIF image extensions](https://www.microsoft.com/en-gb/p/heif-image-extensions/9pmmsr1cgpwg)

  On older versions of Windows and on Wine,
  [the Google WebP codec](https://storage.googleapis.com/downloads.webmproject.org/releases/webp/WebpCodecSetup.exe)
  can be installed for WebP support.

  Note: Currently, when configuring artwork sources in Display preferences, the
  .webp or .heif file extension must be explicitly specified for WebP or HEIF
  files to be loaded. (Using `.*` for the file extension will not load WebP or
  HEIF files.) [[#276](https://github.com/reupen/columns_ui/pull/276)]

### Internal changes

- The component is now compiled using foobar2000 SDK 2019-12-27.
  [[#271](https://github.com/reupen/columns_ui/pull/271),
  [#285](https://github.com/reupen/columns_ui/pull/285)]

## 1.3.0

- There were no changes from version 1.3.0-rc.1.

## 1.3.0-rc.1

### Features

- When using in-line field editing in the playlist view, empty field values are
  no longer written to the file when saving changes. (If no field values are
  entered, the field is now removed from the file.)
  [[#266](https://github.com/reupen/columns_ui/pull/266)]

- In-line field editing in the playlist view is no longer sometimes blocked if a
  file with no loaded metadata is encountered.
  [[#266](https://github.com/reupen/columns_ui/pull/266)]

### Bug fixes

- A crash was fixed when using in-line field editing in the playlist view and
  setting a field to an empty string.
  [[#266](https://github.com/reupen/columns_ui/pull/266)]

- A crash was fixed when saving changes after using in-line field editing in the
  playlist view on more than two tracks with initially differing field values.
  [[#266](https://github.com/reupen/columns_ui/pull/266)]

### Internal changes

- The component is now compiled using Visual Studio 2019 16.4.

## 1.3.0-beta.1

### Removals

- Support for foobar2000 1.3 was removed. foobar2000 1.4 is now the minimum
  version required.

### Features

- When using in-line field editing in the playlist view, it’s now possible to
  enter multiple field values by separating values with semicolons.
  [[#263](https://github.com/reupen/columns_ui/pull/263)]

- When using in-line field editing in list views such as the playlist view, all
  text in the edit box can now be selected by pressing Ctrl-A. (Note that
  Windows 10 1809 and newer already supported this keyboard shortcut natively.)
  [[#257](https://github.com/reupen/columns_ui/pull/257),
  [ui_helpers#41](https://github.com/reupen/ui_helpers/pull/44)]

- The Item properties panel can now display custom information sections from
  third-party components.
  [[#251](https://github.com/reupen/columns_ui/pull/251)]

- A main menu item for showing and hiding artwork in the playlist view was
  added. [[#262](https://github.com/reupen/columns_ui/pull/262)]

- Various default settings were updated:

  - All built-in panels now have a default edge style of ‘none’.
    [[#242]](https://github.com/reupen/columns_ui/pull/242)

  - The Windows notification icon is now disabled by default.
    [[#245](https://github.com/reupen/columns_ui/pull/245)]

  - Tooltips are now enabled in the playlist view by default.
    [[#258]](https://github.com/reupen/columns_ui/pull/258)

  - The default playlist switcher configuration now includes a playing indicator
    in playlist titles. [[#248](https://github.com/reupen/columns_ui/pull/248)]

  - The default information sections displayed by the Item properties panel were
    changed. [[#253]](https://github.com/reupen/columns_ui/pull/253)

  - The default metadata field titles in the Item properties panel now use
    sentence case. [[#253]](https://github.com/reupen/columns_ui/pull/253)

### Bug fixes

- A crash when dragging items over a playlist with a very long name was fixed.
  [[#264](https://github.com/reupen/columns_ui/pull/264),
  [ui_helpers#46](https://github.com/reupen/ui_helpers/pull/46)]

- When typing the name of an item in a list view to jump to that item, the space
  key now correctly jumps to matching items.
  [[#246](https://github.com/reupen/columns_ui/pull/246),
  [ui_helpers#41](https://github.com/reupen/ui_helpers/pull/41)]

- Various bugs relating to the display of ellipses in truncated text containing
  colour codes were fixed.
  [[#250](https://github.com/reupen/columns_ui/pull/250),
  [ui_helpers#42](https://github.com/reupen/ui_helpers/pull/42),
  [ui_helpers#43](https://github.com/reupen/ui_helpers/pull/43)]

- The expansion state of items in the layout tree on the Layout preferences page
  is now fully preserved when moving items up and down.
  [[#255](https://github.com/reupen/columns_ui/pull/255)]

- Panel options on the Layout preferences page are now always correctly disabled
  after the tree selection is cleared (such as after selecting a different
  preset). [[#261](https://github.com/reupen/columns_ui/pull/261)]

- When a panel with a custom title is copied and pasted, the custom title is now
  correctly set on the pasted panel.
  [[#254](https://github.com/reupen/columns_ui/pull/254)]

### Internal changes

- The internal state management of the layout tree on the Layout preferences
  page was reworked. [[#231](https://github.com/reupen/columns_ui/pull/231),
  [#256](https://github.com/reupen/columns_ui/pull/256),
  [#260](https://github.com/reupen/columns_ui/pull/260)]

- The component is now compiled using foobar2000 SDK 2019-09-18.
  [[#243](https://github.com/reupen/columns_ui/pull/243)]

- The component is now compiled using Visual Studio 2019 16.3.

## 1.2.0

- There were no changes from version 1.2.0-rc.2.

## 1.2.0-rc.2

- A crash when Item properties was used with Playback Statistics 2.x was fixed.
  [[#227](https://github.com/reupen/columns_ui/pull/227)]

- A warning is now output to the foobar2000 console if UI Hacks is installed
  (due to problems it’s known to cause).
  [[#224](https://github.com/reupen/columns_ui/pull/224)]

- The component is now compiled using foobar2000 SDK 2019-07-26.
  [[#225](https://github.com/reupen/columns_ui/pull/225),
  [#226](https://github.com/reupen/columns_ui/pull/226)]

## 1.2.0-rc.1

- A potential crash when the Item properties panel was refreshing its contents
  was fixed. [[#218](https://github.com/reupen/columns_ui/pull/218)]

- A problem was fixed where the buttons toolbar options dialog box may have
  shown blank or incomplete command names for buttons linked to unknown main
  menu items.

  They will now say 'Unknown command', or end in '/Unknown' if they are dynamic
  commands. [[#219](https://github.com/reupen/columns_ui/pull/219)]

- Tooltips and the button text of buttons linked to dynamic context menu items
  now include the parent item (e.g. 'Convert/…' instead of '…').
  [[#219](https://github.com/reupen/columns_ui/pull/219)]

- The status bar and status pane double-click action setting now handles dynamic
  main menu items correctly.
  [[#220](https://github.com/reupen/columns_ui/pull/220)]

- The playlist view empty area double-click action setting now handles dynamic
  main menu items correctly.
  [[#220](https://github.com/reupen/columns_ui/pull/220)]

## 1.2.0-beta.3

- A problem was fixed where it was not possible to double-click on the first few
  visible items in the playlist view and in other list views.
  [[#214](https://github.com/reupen/columns_ui/pull/214),
  [ui_helpers#31](https://github.com/reupen/ui_helpers/pull/31)]

## 1.2.0-beta.2

- A problem was fixed where it was not possible to click exactly at the top of
  each item in the playlist view and in other list views.
  [[#210](https://github.com/reupen/columns_ui/pull/210),
  [ui_helpers#28](https://github.com/reupen/ui_helpers/pull/28)]

- Flickering and similar effects during updates were further reduced in the
  playlist view and other list views.
  [[#211](https://github.com/reupen/columns_ui/pull/211),
  [ui_helpers#29](https://github.com/reupen/ui_helpers/pull/29)]

- A regression was fixed where playlist and other list view tooltips were not
  aligned with the left edge of the text underneath them.

  This fix mainly applies to left-aligned columns and alignment may still not be
  perfect for centre- and right-aligned columns.
  [[#212](https://github.com/reupen/columns_ui/pull/212),
  [ui_helpers#30](https://github.com/reupen/ui_helpers/pull/30)]

- The height of tooltips in the playlist and other list views no longer scales
  with the vertical item padding setting.

  As a result, tooltips have a more appropriate height for large and negative
  vertical item paddings.
  [[#212](https://github.com/reupen/columns_ui/pull/212),
  [ui_helpers#30](https://github.com/reupen/ui_helpers/pull/30)]

## 1.2.0-beta.1

- The time it takes Item properties to update was reduced for very large
  selections. [[#199](https://github.com/reupen/columns_ui/pull/199),
  [#209](https://github.com/reupen/columns_ui/pull/209)]

- Flickering in the playlist view was reduced when all items are replaced (e.g.
  when using Filters) [[#198](https://github.com/reupen/columns_ui/pull/198)]

- A bug was fixed where playlist items were not centred correctly in the
  playlist view when e.g. double-clicking on the status bar.
  [[#203](https://github.com/reupen/columns_ui/pull/203),
  [ui_helpers#27](https://github.com/reupen/ui_helpers/pull/27)]

- The 'Edit this column' playlist view command (and other Columns UI commands
  that open Preferences) now behave correctly if Preferences is already open,
  and the desired page had previously been navigated to.
  [[#201](https://github.com/reupen/columns_ui/pull/201)]

- Values of metadata fields are no longer sorted alphabetically in Item
  properties; instead they retain their order of appearance in the selected
  tracks. [[#199](https://github.com/reupen/columns_ui/pull/199),
  [#205](https://github.com/reupen/columns_ui/pull/205)]

- The order of fields in non-metadata sections in Item properties is now ordered
  as specified by foobar2000 (or other track property providers).
  [[#199](https://github.com/reupen/columns_ui/pull/199)]

- A possible crash on foobar2000 exit was fixed.
  [[#200](https://github.com/reupen/columns_ui/pull/200)]

- The names of some context menu commands were corrected in the Buttons toolbar.
  [[#202](https://github.com/reupen/columns_ui/pull/202)]

- A bug was fixed where rearranging buttons in Buttons toolbar options by
  dragging them did not reorder them correctly.
  [[#204](https://github.com/reupen/columns_ui/pull/204)]

- Filter panels now update when right-clicking on items.
  [[#206](https://github.com/reupen/columns_ui/pull/206)]

## 1.1.0

- The component is now compiled using Visual Studio 2019 16.2.

## 1.1.0-beta.1

- Custom fonts now scale when the display scaling factor (DPI) changes.
  [[#159](https://github.com/reupen/columns_ui/pull/159)]

- The scrolling behaviour of the playlist view and other list views was improved
  when clicking on partially visible items at the top or bottom of the view.
  [[#160](https://github.com/reupen/columns_ui/pull/160),
  [ui_helpers#11](https://github.com/reupen/ui_helpers/pull/11)]

- List views now use themed focus rectangles when theming mode is enabled.
  [[#166](https://github.com/reupen/columns_ui/pull/166),
  [ui_helpers#14](https://github.com/reupen/ui_helpers/pull/14),
  [ui_helpers#15](https://github.com/reupen/ui_helpers/pull/15)]

- DPI scaling improvements were made to padding, lines and borders in list
  views. [[#166](https://github.com/reupen/columns_ui/pull/166),
  [#184](https://github.com/reupen/columns_ui/pull/184),
  [ui_helpers#14](https://github.com/reupen/ui_helpers/pull/14),
  [ui_helpers#22](https://github.com/reupen/ui_helpers/pull/22)]

- DPI scaling improvements were made to the status bar, status pane and Item
  details panel. [[#184](https://github.com/reupen/columns_ui/pull/184)]

- The default vertical item padding of the playlist view and playlist switcher
  was increased. [[#167](https://github.com/reupen/columns_ui/pull/167)]

- The height of the playlist view and filter panel column titles now varies with
  the vertical item padding setting.
  [[#170](https://github.com/reupen/columns_ui/pull/170),
  [ui_helpers#16](https://github.com/reupen/ui_helpers/pull/16)]

- The scroll position is now preserved when adjusting playlist view, playlist
  switcher and filter panel settings that affect the vertical height and/or
  position of items. [[#170](https://github.com/reupen/columns_ui/pull/170),
  [#172](https://github.com/reupen/columns_ui/pull/172),
  [ui_helpers#16](https://github.com/reupen/ui_helpers/pull/16),
  [ui_helpers#17](https://github.com/reupen/ui_helpers/pull/17)]

- FCL files now include Filter panel and toolbar settings.
  [[#175](https://github.com/reupen/columns_ui/pull/175)]

- Playlist switcher and tab settings are now on separate tabs in preferences.
  [[#179](https://github.com/reupen/columns_ui/pull/179)]

- Changes to the playlist switcher title formatting script now apply instantly.
  [[#179](https://github.com/reupen/columns_ui/pull/179)]

- A bug was fixed where text copied in certain list views using Ctrl-C could be
  corrupted. [[#186](https://github.com/reupen/columns_ui/pull/186),
  [ui_helpers#24](https://github.com/reupen/ui_helpers/pull/24)]

- A rare problem where a keyboard shortcut could be handled more than once when
  a natively-handled keyboard shortcut (such as Ctrl-C) was reassigned to
  another command was fixed.
  [[#180](https://github.com/reupen/columns_ui/pull/180),
  [ui_helpers#20](https://github.com/reupen/ui_helpers/pull/20)]

- The behaviour of the Page Up and Page Down keys in the playlist and other list
  views was improved. [[#180](https://github.com/reupen/columns_ui/pull/180),
  [ui_helpers#19](https://github.com/reupen/ui_helpers/pull/19)]

- The component is now compiled using Visual Studio 2019 16.1 and the foobar2000
  SDK 2019-06-30.

## 1.0.0

- No changes from 1.0.0-rc.1.

## 1.0.0-rc.1

- Fixed the inability to tab to the playlist view and other list views and fixed
  or worked around other tabbing misbehaviours.
  [[#148](https://github.com/reupen/columns_ui/issues/148),
  [#150](https://github.com/reupen/columns_ui/pull/150),
  [#151](https://github.com/reupen/columns_ui/pull/151),
  [#152](https://github.com/reupen/columns_ui/pull/152)]

- Re-added the colon after the 'Playing' and 'Paused' text in the status pane.
  [[#153](https://github.com/reupen/columns_ui/pull/153)]

- Fixed a bug where right-clicking on the Artwork view panel and selecting
  Options would show the wrong tab in Columns UI preferences.
  [[#147](https://github.com/reupen/columns_ui/issues/147),
  [#155](https://github.com/reupen/columns_ui/pull/155)]

- Compiled with Visual Studio 2017 15.9.

## 1.0.0-beta.1

- Added support for horizontal mouse wheel scrolling in the playlist view and
  other list views (requires a mouse with a four-way mouse wheel).
  [[#139](https://github.com/reupen/columns_ui/pull/139)]

- Reduced the minimum width of the output device toolbar.
  [[#140](https://github.com/reupen/columns_ui/pull/140)]

- Column widths in the Item properties panel are now DPI-aware.
  [[#141](https://github.com/reupen/columns_ui/pull/141)]

- Fixed misbehaviour when using the mouse wheel in various drop-down list
  toolbars. [[#130](https://github.com/reupen/columns_ui/pull/136)]

- Fixed a problem in preferences where colour and font items from other
  components that don’t have a name were using the name of another colour or
  font item. [[#142](https://github.com/reupen/columns_ui/pull/142)]

- Compiled with Visual Studio 2017 15.8.

## 1.0.0-alpha.2

- Fixed a crash when adding a toolbar after the last toolbar and other potential
  misbehaviour in the toolbars.
  [[#130](https://github.com/reupen/columns_ui/pull/130)]

- Fixed misbehaviour when using the mouse wheel with the volume bar and the
  volume bar misreporting the current volume in some cases.
  [[#131](https://github.com/reupen/columns_ui/pull/131)]

## 1.0.0-alpha.1

### Playlist view

- Removed the Columns playlist. On upgrade, any Columns playlist instances in
  layout presets will be replaced with NG playlist (now simply named playlist
  view). [[#103](https://github.com/reupen/columns_ui/issues/103),
  [#114](https://github.com/reupen/columns_ui/pull/114)]

- Slightly faster playlist grouping and sorting performance on multi-core PCs.

- Right-clicking in empty space in the playlist view now correctly deselects all
  items and always displays a context menu.
  [[#75](https://github.com/reupen/columns_ui/issues/75)]

- Added a main menu command to toggle whether playlist groups are shown.
  (Additionally, if the menu item is added as button, the button will become
  pressed when the 'Show groups' is turned on.)
  [[#100](https://github.com/reupen/columns_ui/issues/100),
  [#112](https://github.com/reupen/columns_ui/issues/112)]

- Made system date title formatting fields always available and removed the
  associated option. [[#123](https://github.com/reupen/columns_ui/pull/123)]

### Filter panel

- Significantly faster Filter panel performance on multi-core PCs. With a
  quad-core Intel Core-i7 6700K, initialisation time is just under half of what
  it was under 0.5.1 for a medium- to large-sized library.

### Live layout editing

- Added copy and paste context menu commands during live layout editing.
  [[#121](https://github.com/reupen/columns_ui/pull/121)]

### Preferences

- Refreshed the appearance of all preference pages.
  [[#84](https://github.com/reupen/columns_ui/pull/84),
  [#85](https://github.com/reupen/columns_ui/pull/85),
  [#86](https://github.com/reupen/columns_ui/pull/86),
  [#87](https://github.com/reupen/columns_ui/pull/87),
  [#92](https://github.com/reupen/columns_ui/pull/92),
  [#93](https://github.com/reupen/columns_ui/pull/93),
  [#94](https://github.com/reupen/columns_ui/pull/94),
  [#95](https://github.com/reupen/columns_ui/pull/95),
  [#118](https://github.com/reupen/columns_ui/pull/118)]

- Made panel copying and pasting in Layout preferences use the Windows
  clipboard. [[#97](https://github.com/reupen/columns_ui/issues/97)]

- Fixed a bug where pressing Enter or Return while editing a playlist grouping
  script would close the dialog box.
  [[#48](https://github.com/reupen/columns_ui/issues/48)]

- Updated the style and global script help commands to open web-based
  documentation. [[#117](https://github.com/reupen/columns_ui/pull/117)]

### Notification area

- Added the ability to close foobar2000 to the notification area. [Contributed
  by tuxzz, [#56](https://github.com/reupen/columns_ui/pull/56)]

### Item details panel

- Made the Item details panel load full metadata (including large fields such as
  lyrics) for selected items. (Note: full metadata for playing tracks is
  dependent on the input component.)
  [[#68](https://github.com/reupen/columns_ui/issues/68)]

### Toolbars

- Added an output device toolbar (for foobar2000 1.4 and newer only).
  [[#105](https://github.com/reupen/columns_ui/pull/105)]

- Added a ReplayGain source mode toolbar (for foobar2000 1.4 and newer only).
  [[#106](https://github.com/reupen/columns_ui/pull/106),
  [#116](https://github.com/reupen/columns_ui/pull/116)]

- Added a DSP preset toolbar (for foobar2000 1.4 and newer only).
  [[#115](https://github.com/reupen/columns_ui/pull/115),
  [#116](https://github.com/reupen/columns_ui/pull/116)]

- Added a live layout editing button to the default buttons toolbar
  configuration. [[#99](https://github.com/reupen/columns_ui/pull/99)]

- Fixed a bug in the buttons toolbar where clicking on a context menu item
  button configured to use the 'Active selection' item group, with selection
  viewers set to prefer the playing track, would not have an effect if a track
  was playing. Now, the button will operate on the current selection as
  expected. [[#110](https://github.com/reupen/columns_ui/pull/110)]

- Corrected the display of the names of dynamic context menu items in buttons
  toolbar options. [[#111](https://github.com/reupen/columns_ui/pull/111)]

- Corrected the scale used in the volume bar so that -10 dB is at the 50% mark,
  -20 dB at the 25% mark etc.
  [[#109](https://github.com/reupen/columns_ui/pull/109)]

### Status pane

- Corrected the status pane playback status when resume playback on start-up is
  enabled and foobar2000 is started when playback was previously paused.

- Corrected the colour of text in the status pane when using high-contrast
  Windows themes. [Contributed by MAxonn,
  [#59](https://github.com/reupen/columns_ui/issues/59)]

### Configuration importing and exporting

- Removed the ability to import FCS files.

- Changed the syntax of CLI commands for importing configurations from FCL
  files. The commands now use the following syntax: `/columnsui:import <path>`
  and `/columnsui:import-quiet <path>`.
  [[#47](https://github.com/reupen/columns_ui/issues/47)]

- Added CLI commands for exporting the current configuration to an FCL file. The
  added commands are `/columnsui:export <path>` and
  `/columnsui:export-quiet <path>`.
  [[#47](https://github.com/reupen/columns_ui/issues/47)]

### API

- The value of the 'Allow resizing of locked panels' setting is now available to
  other components. [[#53](https://github.com/reupen/columns_ui/issues/53)]

- Added a reliable mechanism for third-party splitter panels to store extra
  configuration data for child panels that persists through panel copy-and-paste
  operations. [[#52](https://github.com/reupen/columns_ui/issues/52)]

### Other changes

- Added compatibility with Windows 10 system media transport controls under
  foobar2000 1.4. [[#101](https://github.com/reupen/columns_ui/issues/101)]

- Some minor changes to labels and layout in various dialogs.

- Updated standalone dialogs to use the Segoe UI font.
  [[#125](https://github.com/reupen/columns_ui/pull/125)]

- Corrected the icons used in some dialogs.
  [[#8](https://github.com/reupen/ui_helpers/pull/8)]

- The component is no longer compatible with Windows XP and Vista. Users of
  those operating systems are advised to stick with version 0.5.1.

- Miscellaneous internal code refactoring.

- Compiled with Visual Studio 2017 15.7.

## 0.5.1

### NG playlist

- Fixed a bug which caused some columns to be hidden when fully scrolled right
  with the artwork column active.
  [[#38](https://github.com/reupen/columns_ui/issues/38)]

- Fixed a bug which caused group heading lines to not be rendered correctly
  after scrolling right. [[#38](https://github.com/reupen/columns_ui/issues/38)]

- Changed the colour of the insertion marker for drag-and-drop operations in NG
  playlist. It now uses the text colour (previously, it was always black).
  [[#39](https://github.com/reupen/columns_ui/issues/39)]

### Other changes

- Fixed a problem where auto-hide panels would get stuck open following long
  operations in the UI thread
  [[#35](https://github.com/reupen/columns_ui/issues/35)]

- Fixed clipped 'Selected item:' text on the Colours tab in the Colours and
  Fonts preferences page.

- Fixed a problem in the NG playlist, playlist switcher and filter panels where
  when a negative vertical item padding was in use, a text cursor would not
  appear when using inline editing. This was fixed by making the text box at
  least as tall as the font.
  [[#45](https://github.com/reupen/columns_ui/issues/45)]

- Compiled with Visual Studio 2015 Update 3.

## 0.5.0

### Layout and toolbars

- A duplicate preset button has been added to the layout configuration page.
  [[#14](https://github.com/reupen/columns_ui/issues/14)]

- When the main window is deactivated with the menu bar focused, the focus is
  now restored to the window that had the keyboard focus before the menu bar did
  when the main window is reactivated. (Previously, the focus was incorrectly
  returned to the menu bar.)
  [[#18](https://github.com/reupen/columns_ui/issues/18)]

- The minimum width of toolbars without an explicit minimum width has been
  reduced to be the same as the minimum height (21 pixels at 100% DPI).

- Improved preferences behaviour when importing FCL files and switching between
  pages; previously preferences may have shown old values after importing an FCL
  file. [[#23](https://github.com/reupen/columns_ui/issues/23)]

- Panel sizes are now DPI-aware in the standard splitters, and non-auto-size
  columns. In particular, this affects the quick setup presets, FCL files, and
  layouts after the system DPI setting has been changed.
  [[#22](https://github.com/reupen/columns_ui/issues/22)]
  [[#21](https://github.com/reupen/columns_ui/issues/21)]

- Added an option to control whether locked panels can be manually resized in
  the standard splitters.
  [[#24](https://github.com/reupen/columns_ui/issues/24)]

- Fixed minor rendering glitches in the toolbars when resizing the main window
  on some versions of Windows.

- Fixed potentially incorrect sizing of panels when resizing the main window and
  using Playlist tabs without a child panel.

### Filters

- Improved the appearance of Filter search bar icons at some DPI settings.

- Added an option to control whether column titles are shown in Filters.
  [[#28](https://github.com/reupen/columns_ui/issues/28)]

- Made Filter panels sortable (can be disabled in preferences).
  [[#28](https://github.com/reupen/columns_ui/issues/28)]

- Reworked Filter preferences and moved them to a separate page.

### Playlist view

- The performance of NG playlist grouping for large playlists has been improved
  on multi-core systems.

- The 'Edit this column' command in the context menu of column titles now
  scrolls to the column in preferences if it is out of view. The command also
  now behaves correctly if the preferences window is already open.

### Other changes

- Corrected truncated 'Size weight' label in Columns tab in Playlist View
  preferences page at some DPI settings.

- Corrected some misbehaviours of the 'active item frame' option in the Colours
  and Fonts preferences page.

- Compiled with Visual Studio 2015 Update 2.

## 0.4.0

### Improved spectrum analyser

Improved spectrum analyser display by using foobar2000's 'New FFT \[behaviour\]
for spectrum-generating methods' and adjusting x- and y-axis logarithmic scales.

Using a linear y-axis is no longer particularly useful and it's recommended that
anyone that was using a linear y-axis switches to a logarithmic y-axis.

### Improved drag and drop behaviour

All standard panels now implement drag images, labels and drop descriptions when
a drag and drop operation is started from them. Currently, the drag image is the
default image provided by the shell, but this may include artwork in the future.
[[#11](https://github.com/reupen/columns_ui/issues/11)]

You can no longer drop files on panels in the layout area that do not implement
drop handlers (e.g. Console panel and Album list panel).

The default action when dragging files to Windows Explorer is now always copy.
Previously, when dragging files to another folder on the same drive, the default
operation would be to move the files.

When dragging files to the playlist switcher or playlist tabs, you can now force
a new playlist to be created by holding down Alt.

When a new playlist is created by dropping files on the playlist tabs, it will
be created where the files were dropped when possible.

When reordering playlists in the playlist switcher, the insertion point is now
below the item under the pointer when over the bottom half of that item.

Fixed a bug where dragging unsupported objects over some panels would cause the
drag image to get stuck on the edge of the panel.

Fixed a bug where dragging a file from Windows Explorer to foobar2000 near the
right-edge of the screen would cause the drop description label to jump about.

### Improved auto-hide panel behaviour

If a drag-and-drop operation is started from a auto-hide panel, or a panel in an
auto-hide splitter, it no longer immediately hides itself. In particular, this
allows things like reordering playlists in an auto-hide playlist switcher.

Resizing a hidden auto-hide panel would sometimes cause it to get stuck open.
This has been fixed. [[#8](https://github.com/reupen/columns_ui/issues/8)]

### Splitter divider width is now configurable

[[#10](https://github.com/reupen/columns_ui/issues/10)]

The setting is on the Layout preferences page.

### Improved high-DPI behaviour

[[#16](https://github.com/reupen/columns_ui/issues/16)]
[[#9](https://github.com/reupen/columns_ui/issues/9)]

The default values of the following are now DPI-aware:

- Splitter divider width
- Columns/NG playlist vertical item padding
- Playlist switcher vertical item padding
- Filter panel vertical item padding
- NG playlist artwork column width

Additionally, when transferring those settings to another PC via FCL files, or
when changing the system DPI, the values will automatically be scaled
appropriately.

Similar changes will be made for other settings in an upcoming version.

### Other bug fixes

- If you sort by a column in NG Playlist, this can now be undone using the Undo
  command.
- Fixed various truncated text labels in various dialogs on certain DPI
  settings.
- Corrected the behaviour of the up and down buttons for the auto-hide show and
  hide delay settings in preferences.
- Added a workaround for an OS bug that could cause the main menu to be
  incorrectly activated when foobar2000 was alt-tabbed out of and a global
  keyboard shortcut using Ctrl+Alt was used to activate the foobar2000 window.
- When the main menu is focused (by pressing Alt or F10), F10 can now correctly
  be used to deactivate the menu.
- Fixed a bug where if foobar2000 was minimised to a notification icon, and you
  then hid the notification icon in preferences, you would be left with no
  notification icon and no visible window.
- Fixed odd behaviour of centre- and right-alignment in Item details when word
  wrapping was off. [[#17](https://github.com/reupen/columns_ui/issues/17)]
- Fixed incorrect inclusion of trailing spaces on lines in Item details when
  word wrapping was on.

## 0.3.9.x

### 0.3.9.2

- Updated to latest foobar2000 SDK; foobar2000 1.3+ now required
  [[#1](https://github.com/reupen/columns_ui/issues/1)]
- Disabled a compiler option causing problems on XP/Wine
  [[#6](https://github.com/reupen/columns_ui/issues/6)]
- Compiled with Visual Studio 2015 Update 1
- New /columnsui:import-quiet CLI command to import FCLs with fewer prompts than
  /columnsui:import

### 0.3.9.1

- Fixed obscure bug sometimes causing panels not to appear on start-up when
  using Columns playlist

### 0.3.9.0

- Fixed notification area icon scaling in high-DPI mode
- Fixed spectrum analyser bars mode scaling in high-DPI mode
- Added NG Playlist groups to FCLs
  [[#2](https://github.com/reupen/columns_ui/issues/2)]
- Compiled with Visual Studio 2015

## 0.3.8.x

### 0.3.8.9

- Fixed high-DPI bugs in the toolbars
- Fixed/worked around Windows 8 panning gesture misbehaviour
- Various code tidy-ups
- Compiled with Visual Studio 2013

### 0.3.8.8

- Removed libpng dependency in buttons toolbar
- Added support for more image types in buttons toolbar
- Improved buttons toolbar options window
- Default button images are now DPI-aware (for custom images this only applies
  to icon files)
- Corrected default NG Playlist grouping scheme
- Fixed Items Details panel crash with malformed font change codes
- Amended Filter panel default playlist sort script
- Improved artwork edge-pixel rendering
- Added support for paths relative (to foobar2000 installation) in buttons
  toolbar
- Misc fixes

### 0.3.8.7

- Made Filter search clear button optional
- When placed in a stock splitter with Filter panels, Filter search will only
  affect those Filters
- Fixed misbehaviours when using "Selection viewers: Prefer currently playing
  track" in recent foobar2000 versions
- Fixed/changed Filter search behaviours when no Filters are visible
- Playlist grouping is now case-sensitive.
- Added support for Ctrl+C to Item Properties panel (copies selection as text)
- Misc changes

### 0.3.8.6

- Misc changes

### 0.3.8.5

- Filter search will now function if no Filter panels are in the active layout
- Added Clear button to Filter search
- Fixed Filter search misbehaviours when Filter precendence is set to "By field
  list above".
- Enter key in Filter search now displays results in Filter panel autosend
  playlist
- Misc Filter search bug fixes

### 0.3.8.4

- Added status pane font configuration
- Resolved some item details font change word wrapping issues
- Added new Filter search toolbar; removed the previous search facility

### 0.3.8.3

- Added support for foobar2000 1.0 dynamic main menu commands in buttons toolbar
- Added "active selection" mode for buttons in buttons toolbar
- Fixed toolbar issues on Windows XP
- Added tab-column support in status pane

### 0.3.8.2

- Fixed crash when using playlist inline metadata editing

### 0.3.8.1

- Improved UI appearance when closing foobar2000 during playback
- Added new "status pane"
- Added suppport for foobar2000 1.0 artwork reader
- Fixed an issue where a single track group would have its artwork reloaded when
  the track is modified
- Tidied up buttons toolbar options/removed obsolete options
- Fixed: starting a drag and drop operation with the right mouse button wasn't
  implemented in the new list control (NG Playlist etc.)
- Improved drag and drop feedback on Windows Vista and newer when source item is
  from Windows Explorer
- Misc changes / bug fixes

### 0.3.8.0

- Fixed a regression in version 0.3.6.5 where Item Details panel didn't
  correctly update when a scrollbar is shown/hidden

## 0.3.7.x

### 0.3.7.9

- Fixed/worked around status bar flicker issue
- Worked around an issue when updating Windows 7 task bar thumbnail buttons

### 0.3.7.8

- Fixed an issue with colour codes in Item details panel

### 0.3.7.7

- Fixed issue with padding when using "tab columns"

### 0.3.7.6

- Bug fix

### 0.3.7.5

- Bug fix

### 0.3.7.4

- Worked around ExtTextOut font fallback issues; rewrote large portions of text
  rendering code
- In layout preferences, copy & pasting nodes now does not allow multiple
  instances of single instance panels
- Updated keyboard shortcut processing in standard panels to use newer Core API
- Misc changes / fixes

### 0.3.7.3

- Bug fixes

### 0.3.7.2

- Fixes a rare issue with Item details panel, with it encountering invalid UTF-8
  characters - apparently when listening to certain radio streams - causing the
  panel to get stuck in an infinite loop (eventually crashing).

### 0.3.7.1

- Fixed an issue preventing 'Artist picture' being selected as a source in the
  artwork panel.

### 0.3.7.0

- Added support for artist picture to artwork view panel
- Added autocomplete suggestions to NG Playlist inline editing
- Bug fixes

## 0.3.6.x

### 0.3.6.9

- Improvements to the Item Properties panel
- Bug fixes

### 0.3.6.8

- Fixed a crash when removing items whilst making a selection in NG Playlist and
  other panels
- Various bug fixes
- Optimisations to Filter Panel updates on media library changes.

### 0.3.6.7

- Various bug fixes

### 0.3.6.6

- Rewritten playlist switcher panel
- Fixed a couple of cases where natural numeric sorting was not in place
- Default buttons toolbar icons are now 16x16
- Help button in preferences now directly opens the respective wiki page
- Misc changes / fixes

### 0.3.6.5

- Workaround for kernel stack exhaustion on 64-bit Windows when applications
  with certain global hooks are running
- Uses 'natural number sorting'
- Added support for multiple artwork sources per artwork type (requires
  reconfiguring artwork sources after upgrading)

### 0.3.6.4

- Bug fix

### 0.3.6.3

- NG Playlist: Fixed 'Show groups' option not working
- Added edge style options to item properties, item details, artwork view panels
- Item details panel: Improvements to options dialog
- Item details panel: Added vertical alignment option
- Item details panel: Some bug fixes
- Item details panel: Added %default_font_face% and %default_font_size% fields
- General tidying

### 0.3.6.2

- Work on 'out of the box' user experience
  - Retired Columns Playlist as the default playlist view
  - Added new presets to initial Quick Setup
  - Added a few more options to initial Quick Setup
  - Tweaked a couple of default settings
- Fixed an issue with NG Playlist not sorting files dropped from external
  applications correctly
- Alternate selection model works with NG Playlist
- Rearranging columns by their titles now works in NG Playlist

### 0.3.6.1

- Item details panel: Fixed some issues with word wrapping and colour codes.

### 0.3.6.0

- Item details panel: Added possibility to dynamically change font.

## 0.3.5.x

### 0.3.5.5

- NG playlist: Fixed tooltips setting was not applied correctly after restarting
  fooobar2000
- Artwork view: Fixed displayed artwork type being reset after restarting
  foobar2000

### 0.3.5.4

- Fixed an few issue with Filter panel when tracks are removed from media
  library

### 0.3.5.3

- Fixed a crash issue with artwork view panel

### 0.3.5.2

- Item details panel: mouse wheel support
- Item details panel: word wrapping support
- Item details panel: colour codes now span across multiple lines
- Item details panel: performance optimisations
- Filter panel: Fixed search query not being applied on media library changes
- Filter panel: Performance optimisations to media library change handlers
- NG Playlist: Fixed double clicking on columns title divider

### 0.3.5.1

- Hot fix

### 0.3.5.0

- Fixed: Item count in first filter in chain did not update correctly on media
  library changes
- Fixed: Some issues in button toolbar command picker for context menu commands
- Changed: Tab stack forces broken panels to be hidden on creation
- Added: New Item details panel.

## 0.3.4.x

### 0.3.4.2

- Added 'Lock type' option to artwork view panel to prevent displayed artwork
  type automatically changing
- New tracking modes for artwork view panel including 'Current selection'
- Can now toggle displayed artwork type from artwork view shortcut menu

### 0.3.4.1

- Hot fix

### 0.3.4.0

- Added option to preserve aspect ratio in artwork view
- Support for artwork with alpha channel in NG Playlist
- Fixed: status bar description were not displayed for the NG Playlist and
  Filter Panel item shortcut menus
- Fixed: Incorrect sort arrow directions in NG Playlist
- Added option to restrict built-in foobar2000 artwork reader to embedded images
  only
- Improved performance of "Show reflections" for artwork in NG Playlist
- Added option to disable low artwork reader thread priority in NG Playlist
- Misc bug fixes

## 0.3.3.x

### 0.3.3.1

- bug fixes

### 0.3.3.0

- artwork reader threads are now low priority
- can change font of NG Playlist group titles
- added inline editing to selection properties
- item properties panel now automatically updates when tracks are modified
- 'automatic' tracking mode in item properties
- tweaked default no artwork found image
- fixed versioning scheme

## 0.3

### beta 2

#### preview 11

##### initial release

- Improved initial setup dialog
- Can now access initial setup from preferences
- Added Item Properties panel
- Added vertical item padding option to Filter Panel
- Improved Filter Panel "Add to active playlist" behaviour
- Fixed: F2 didn't if mouse activated inline editing was disabled in NG Playlist
- Fixed: Put dropped files at end of playlist did not work in NG Playlist
- Misc bug fixes

##### build c

- You can view autoplaylist properties (with foobar2000 0.9.5.4+)
- You can use the mouse wheel over tab stack/playlist tabs (tested on Vista
  only)
- Partial fix of the problem with tall artwork and reflections

##### build e

- Various bug fixes
- Passes through artwork images unaltered if the source size is the same as the
  destination size

#### preview 10

- added search query to Filter Panel

#### preview 9

- fixed: extra empty item was displayed in Filter Panel

#### preview 8

- added selectable tracking modes for artwork viewer panel: auto/playing
  item/active playlist item
- fixed NG Playlist issue with global style string not being inherited into
  custom column style strings
- added options in prefs to control NG Playlist artwork
- removed option: "Use alternative selection option (Columns Playlist only)"
- fixed a issue with %is_playing% in playlist switcher panel and dead tracks
- changed default no cover image
- added %playlist_name%/%\_playlist_name% in playlist views
- added option to show artwork reflection in NG Playlist

#### preview 7

- fixed some bugs with relative artwork paths

#### preview 6

- corrected some possible glitches when resizing artwork column in NG Playlist
- fixed NG Playlist / Filter Panel losing scroll position when resize really
  small

#### preview 5

- Fixed incorrect text positioning when using tab characters in playlist etc.
- Added support for wildcards in artwork source scripts
- Removed need to specify the file extension in artwork source scripts
- Added support for relative paths in artwork source scripts
- Made using the foobar2000 built-in artwork reader optional
- Added default no cover image
- Stopped artwork reader from attempting to read remote files
- Drag and drop sensitivity is based upon system settings in NG Playlist/Columns
  Playlist/Filter Panel now
- Performance optimisations to NG Playlist artwork reading
- Added reset style string button under 'Tools' on 'Globals' prefs page
- Updated default global style string to use %list_index% rather than
  %playlist_number%
- NG Playlist now automatically scrolls when dragging items over it
- Optimised performance of NG Playlist when date/time changes (when date info
  enabled)

#### preview 4

- Fixed bug that prevented width of artwork column from being saved across
  sessions

#### preview 3

- Added minimum height for groups when artwork is enabled
- Bug fixes

#### preview 2

- Fixed display glitch with inline metadata editing in NG Playlist
- Changed processing order for artwork reading in NG Playlist

#### preview 1

- Added support for displaying artwork within NG Playlist
- Some changes/fixes to NG Playlist

### beta 1

#### preview 6

- some fixes for %filesize% field in playlist switcher

#### preview 5

- Some improvements to dropping items on NG Playlist
- Fixed: Items dragged from Filter Panel were not sorted
- Rewrote back end of Artwork Panel
- Added support for stub image in Artwork Panel
- Removed support for "Icon" artwork
- Added "Show items with empty labels" option in Filter Panel
- Added New button on columns config page
- added %filesize% and %filesize_raw% to NG Playlist

#### preview 4

- Added support for fixed artwork repositories in Artwork panel
- Some fixes / changes to the Artwork panel

#### preview 3

- Fixed some rendering glitches in splitters in preview 2

#### preview 2

- Some bug fixes and minor changes

#### preview 1

- Added option for filter panel precedence to be determined by position in
  splitter. Note: Only works with standard horizontal/vertical splitters.
- Added simple artwork viewer for currently playing track.
- Some optimisations for Filter Panel prefs page
- Some fixes to Colours prefs page
- Some bug-fixes to Filter panel

## 0.2.1

### alpha 11

#### final

##### v3

- fixed filter field assignments being reset on startup

##### v2

- fixed problem with selected item text colour in unified colour config
- fixed an issue clicking on group headers in NG Playlist

##### initial release

- Unified colour and font settings are now exported to FCL files
- Added support for field remappings and titleformatting to Filter Panel
- Added edge style setting to filter panel
- Fixed column style strings in NGPV
- Fixed middle click action in Filter Panel
- Misc fixes / changes.

#### preview 2

##### v2

- fixed colours prefs page layout

##### initial release

- Added unified fonts configuration
- Colour and font settings from previous versions are now automatically imported
- Rewrote live layout editing backend
- Added 'Show caption' and 'Locked' options to live editing panel context menu
- This is a PREVIEW RELEASE only and is not the final alpha 11. It has the
  following limitations:
  - Settings from the new unified colours and fonts page are not exported to FCL
    files

#### preview 1

- Added unified colour configuration page
- NGPV now scrolls to the focused item the first time you activate a playlist
- fixed: selection colours were not working in colour codes in NGPV
- corrected an error in the default style script (missing % sign after
  %\_display_index)
- This is a PREVIEW RELEASE only and is not the final alpha 11. It has the
  following limitations:
  - The design/specification of the unified colour configuration is not
    finalised and does not include fonts as yet
  - As per the previous point, settings from the new unified colours page are
    not exported to FCL files

### alpha 10

#### v4

- fixed Ctrl+mouse wheel horizontal scrolling not working correctly
- added support for restoring deleted playlists in playlist switcher/tabs panel
- NGPV now remembers scroll positions across playlists (not across foobar2000
  instances)
- improved group Ctrl-click behaviour in NGPV
- fixed: in columns prefs the column name in the list of columns didn't update
  after renaming the column
- fixed failed FCL export when layout contains empty playlist tabs panel
- fixed: moving playing item no longer loses playback marker
- other miscellaneous changes / fixes

#### v3

- fixed crash introduced in v2 on empty playlists in NGPV

#### v2

- fixed some more suboptimal rendering issues in NG Playlist

#### initial release

- filter panel now acts as a source for drag and drop operations.
- fixed double click on empty area being triggered in some areas it shouldn't
- added various options/features from Columns Playlist to NG Playlist
- fixed: too much rendering was going on when updating the playing item in NGPV
- fixed: duplicates would be sent to the playlist in filter panel if a track
  appears in the selected nodes multiple times.
- fixed/changed various other miscellaneous things

### alpha 9

#### v2 / v3

- fixes grouping bugs when second (or above) level group has same text as
  adjacent group at the same level.

#### initial release

- fixed undo command for some actions in playlist
- added support for vertical item padding setting in NGPV
- added support for configurable items and column header font in NGPV
- fixed some focus issues with tabs splitter
- fixed issue with decrease font size wrapping around weirdly
- changed some ellipsis behaviour in text renderer for right/centre aligned
  columns
- added support for double click on empty area in NGPV
- added logarithmic (horizontal and vertical) scale options to spectrum analyser
  (enabled by default)
- added configurable double/middle click actions to Filter Panel
- misc. changes / fixes

### alpha 8

- Fixed: middle clicking in filter panel did unexpected things
- Added: configurable colours and style string support to NGPV
  - to deal with alternating item colours in NGPV, the global style string is
    evaluated on a group header context and some new fields are added (NGPV
    only):
    - %\_display_index% - index of item as displayed in the playlist view (i.e.
      counting group headers as an item). use
      $if2(%\_display_index%,%playlist_number%) if using Columns Playlist as
      well
    - %\_is_group% - indicates the script is being evaluated in the context of a
      group header
  - some colours are fixed in 'Themed' mode (which as a reminder only does
    anything useful on Vista). in other modes group background and foreground
    colours are customisable via $set_style (text/back colours)
- Added: tooltip support to NGPV and Filter Panel
- Performance optimisations to Filter Panel
- Fixed: FCL was using legacy main window title / status bar / notification icon
  tooltip scripts
- Fixed: importing FCL didn't refresh NGPV
- Added: Support for alignment setting in NGPV
- Added: NGPV saves column sizes
- Fixed: various column settings synchronisation issues (between NGPV and
  Columns Playlist)
- Fixed: columns were lost under some circumstances
- Other misc. fixes

### alpha 7

#### v2

- Fixed NG Playlist groups refresh on active playlist rename

#### initial release

- Corrected some selection behaviours in NG Playlist/Filter Panel
- Added playlist filters for NG Playlist groups and removed playlist-specific
  fields from group script title formatting
- Fixed buttons toolbar compatibility with 'Quick Tagger'
- Added incremental search to Filter Panel/NG Playlist (using first column)
- Fixed bug where NG Playlist/Filter Panel may allow resizing of columns in
  autosize mode
- Fixed hide/show columns from within Columns Playlist when autosize is disabled
- Added built-in configuration for main window / notification icon tooltip /
  status bar title scripts.
- Added support for 'Show columns titles' option to NG Playlist
- Added FCL support for existing command line import command
- Miscellaneous fixes

### alpha 6

- Bug fixes to live layout editing
- Changed Columns prefs page
- Fixed NG Playlist not updating %playlist_number% etc. correctly on playlist
  contents change
- Various miscellaneous bug fixes

### alpha 5

- Added cut, copy and paste commands to playlist view and playlist switcher
- Fixed crash bug in Filter Panel on media library changes
- Small change in splitter behaviour to allow for live editing
- Requires foobar2000 0.9.5
- Misc changes/improvements

### alpha 4

#### v2

- fixed auto-size in NG Playlist when switching playlists

#### initial release

- Auto-sizing columns in NG Playlist
- Inline metadata editing in NG Playlist
- Inline metadata editing in Filter Panel
- Fixed Shift + LMB in NG Playlist
- Clicking on group in NG Playlist selects its items
- Playlist shows focus rectangle when 'Playback follows cursor' is enabled
- Added option to disable auto-send in Filter Panel
- Added handlers for some standard keyboard shortcuts in playlist view
- Added a solution for losing-playing-item-when-changing-view-in-filter-panel
  syndrome
- Fixed Filter panel focus bug on startup
- Added double click action to Filter Panel and some context menu entries
- Some bug-fixes

### alpha 3

- Filter Panel updates to media library changes
- Added context menu to Filter Panel
- Misc. bug fixes / changes to Filter Panel

### alpha 2

- added filter panel
- added support for globals, playlist filters to NG Playlist
- added pressed state for live editing command in buttons toolbar

### alpha 1

- moved NG Playlist into Columns UI
- added 'Live editing' of layout
- discontinued support for Windows 2000

## 0.2.0

### final

- bug fixes

### RC 1

- fixed mouse wheel on playback order dropdown
- removed FCL warnings
- respects system wide setting for showing item focus

### beta 1

- Added new mode to FCL exporting (private/non-shareable)
- Some other changes around FCL im/exporting
- Changed tab stack window placement
- Some bug fixes in tab stack
- Some bug fixes in layout editor
- Worked around Vista ComboBox in playback order toolbar not responding to
  WM_MOUSEWHEEL anymore

### alpha 3

- built-in tab stack splitter
- fixed total selected length for tracks with undefined length (i.e. live
  internet streams)
- fixed 'reset presets' in layout editor
- misc bug fixes / changes

### alpha 2

- Added FCL import settings selection dialog and missing panels dialog
- fixed bug where if the only change you made in layout editor was changing the
  base the changes would not get applied/saved
- removed legacy fcs exporting
- fixed bars mode in spectrum analyser half height
- fixed sort arrows in columns playlist on vista
- some small changes to prefs
- changed some behaviours of inline metafield editor

### alpha 1

- **Changed versioning scheme, since old one was a mess.**
- fixed bug in inline metafield editor where editing single file/empty field
  resulted in "`<multiple values>`" being pre-filled
- changed behaviour of multiple file inline metafield editor so you can edit
  non-consecutive files
- Added complete layout settings export (accessible from main prefs page)
- Added support for themed playlist on Vista. Note: The default style string has
  changed as a result.
- Added first-time setup prompt.
- Fixed can't undo some rearrange items in playlist actions
- Fixed regression where window focus wasn't saved after switching windows
- Seek bar/Volume bar use pressed state when themed
- Playlist switcher item actions in context menu moved to submenu

## 0.1.3

### beta 1

#### v8 TEST (forum release)

- fixed bug in spectrum analyser bars mode where extra filled rows were
  sometimes drawn
- fixed bug where buttons toolbar doesn't call
  register_callback/deregister_callback on clients
- added multi-file inline metafield editor (highlight multiple consecutive files
  and use F2 to activate)
- added copy/paste to layout editor
- updated to current foobar2000 SDK

#### v7

- fixed crash with button using Now Playing item group when nothing is playing
- misc. fixes

#### v6 TEST

- fixed problem resizing panels with toggle area enabled
- fixed crash when panel calls relinquish_ownership on panel owned by splitter
- improved performance of spectrum analyser bars mode
- fixed some problems editing layout when another UI is active
- fixed a problem with autohide and maximised window
- fixed inline metadata editing problems (tabbing) since foobar2000 version
  0.9.3
- compiled with lastest foobar2000 SDK (Vista compatibility)

#### v5

- fixed problems with move up/down in layout config

#### v4

- fixed default buttons on XP with < 32 bpp system colour depth

#### v3

- fixed bug in layout editor with single instance panels

#### v2

- fixed crash pressing ALT with toolbars disabled

#### initial release

Released 2006.04.28

##### layout

- replaced old vertical/horizontal splitters with new panel based
  horizontal/vertical splitters
- added preset support, with accompanying menu items, and default presets
- rewritten layout preferences page, with possibility to switch splitters to
  other types
- improved autohide behaviour
- **broke compatibility with old layout configs**
- axed sidebar
- added toggle area, custom title option for panels
- other minor changes

##### other

- added new "inactive selection text" colour, fixes default config on default XP
  theme
- the playlist view colours listed in colours and fonts are now exported to fcs
  files
- added "export paths" mode for saving fcb files; for use locally on your own
  computer only
- **broke compatibility with old panels** (only need recompiling)
- added export/import settings funcs to panel api, for future possibility of
  saving layout to a file
- fixed error when GDI+ not installed (i.e. Windows 2000)
- changed default buttons (on Windows XP and newer only)
- improved visibility of lock icon
- fixed corrupted PNG loading apparently no-one ever managed to notice
  (bit-depth < 32bpp and greyscale imgaes)
- resolved problem where masstage scripts were not listed in buttons action list
- other minor changes

### pre-alpha 17

#### v6

- Volume toolbar uses GDI+ where available
- Fixed rendering glitch with tooltips on Windows 2000.

#### v5

- fixed bugged toolbar/panel context menus

#### v4

- fixed some recent rendering issues in toolbars
- fixed volume toolbar taking focus
- fixed volume toolbar scroll wheel direction
- changed appaerance of volume toolbar, removed caption
- fixed bug with splitter in hidden splitter
- fixed status bar part sizing in certain conditions
- broke compatibility with old panels (there was none, but..)
- other changes / fixes

#### v3

- made text below icons not force text on all buttons now
- fixed double click on empty playlist area action
- fixed toggling locked, hidden states for splitters in prefs
- fixed a bug with splitters auto-hide not resizing correctly
- added toolbar support for volume control
- cleaned-up part of text renderer code; prevent possible infinite loop
- other misc changes / fixes

#### v2

- fixed crash when selecting "Show toolbars" in menu

#### v1

- menu bar buttons no longer hardcoded, generated at time menu is created from
  new main menu apis
- added basic inline metafield editing
- updated to foobar200 0.9 (rc+)
- some fixes to volume popup
- fixed "Save playlist..." in playlist switcher
- other minor fixes / changes

### pre-alpha 16

#### v2

- fixed problem with cell-frames
- old-style style string only supported when legacy mode enabled now
- fixed 'show keyboard shortcuts in menus' in several places
- fixed status bar context menu

#### v1

- removed "show keyboard shortcuts in menus" option, uses global setting now,
  and fixed some related bugs
- added vertical position saving when switching between playlists
- added volume popup for status bar
- per-cell styles inherited from track-style string (use legacy option to
  disable)
- added support for colour codes with selection colours to $set_style
- bumped fcs version
- updated to beta 13

### pre-alpha 15

#### v4

- fixed bug were vis updates increased after each track played during non-stop
  playback

#### v3

- fixed custom buttons custom bitmap not remembered
- fixed bug in new colours
- increased vis fps to 40

#### v2

- fixed crash bug with multiple spectrum analysers

#### v1

- fixed problem with 'no edges' buttons toolbar style
- fixed couple issues with tooltips in playlist switcher panel
- fixed crash when rightclicking in empty area on playlist tabs and choosing
  "move left" or "move right"
- volume part in status bar size is now calculated using the correct font when
  theming is enabled
- status bar: total length of selected parts is dynamically sized beyond a
  minimum size.
- status bar: volume part is dynamically sized
- buttons: importing fcb uses existing images if they are the same
- added/fixed support for "dynamic" menu items in buttons toolbar, etc. (e.g.
  Playlist/Sort)
- changed default colours
- changed positioning on first run
- updated to b12
- compiled with vc8
- other less visible fixes / changes etc.

### pre-alpha 14

- restored 'spectrum analyser' to list of panels, removed 'simple visualisation'
- fixed an issue with %\_is_playing% in playlist switcher
- improved rebar context menu behaviour when panels have menu items
- integrated custom buttons toolbar
- fixed descriptions on playlist switcher context menu
- fixed colour codes in playlist switcher panel tooltips
- added "add to playback queue" to mis=ddle click actions
- other minor changes
- updated to 0.9 b7
- added %\_text% etc to style string to specify default colours
- re-added highlight of playing track todefault config

### pre-alpha 13

#### v5

- corrected order dropdown minimum height

#### v4

- fixed crash bug after deleting playing playlist and it was last playlist
- corrected minimum width of playback order dropdown
- fixed GDI leak in playlist in previous pa13 versions
- changed behaviour of playlist switcher %is_playing% field, should work better
  now

#### v3

- fixed when switching themes, playlist view colours did not update as expected
  when use custom colours is off.
- fixed after switching to classic theme, seekbar would not render correctly
  until foobar2000 was restarted.
- fixed changing tabs font did not move child window
- fixed creating new playlists did not move child window (when multiline tabs
  enabled)
- fixed renaming a playlist did not move child window (multiline tabs, bug from
  0.1.2!)
- fixed tabs did not update names when reordered
- fixed size limits when child window does not have any
- changed positioning of child window to something similar to old style
- added %length%, %is_active%, %is_playing%, and %lock_name% to playlist
  swwitcher formatting
- fixed a caching bug in playlist view when reordering playlists

#### v2

- fixed crash when all status bar parts removed

#### v1

- playlist switcher panel does not use LBS_HASSTRINGS anymore
- playlist switcher titleformatting has %size% available
- playlist switcher titleformatting supports tab chars now
- finally found a work around for double clicking on tooltips under common
  controls 6
- added option to use system active item frame in playlist view
- added option not to use custom colors in playlist view
- ctrl+enter in default playlist view adds focused item to the playback queue
- added transparency option for main window
- fixed always on top, applying 'status bar' and 'notification area icon
  tooltip' titleformatting scripts
- added playlist lock status to status bar
- added playlist tabs as a splitter panel
- replaced seekbar trackbar with custom control (= transparent background under
  xp themes and less mess)
- fixed right clicking on last item in playlist if only partially visible
- removed redundant 'Apply' buttons in prefs.
- fixed changeing status bar font under commctrl 5 did not reposition windows
- fixed playlist tabs contextmenu when invoked from keyboard
- axed 'list all toolbars'
- other misc. fixes/changes

### pre-alpha 12

#### v4

- fixed size limits for splitters (again)

#### v3

- some bug fixes

#### v2

- fixed clipped prefs
- fixed sorting when dropping files

#### v1

Released 2005.06.05

- fixed: double clicking on a track when tracks are in playback queue does not
  work
- fixed: status bar selected items total length was broken
- fixed: hidden splitters were broken
- small fixes to prefs layout, adding warnings etc.
- fixed crash bug when applying changes to layout
- fixed some contextmenu key behaviours
- host background uses COLOR_3DFACE as oposed to COLOR_MENUBAR on winxp with
  themes off for real this time
- finished implementation for $set_style, renamed color string to style string
- fixed some drag and drop selection/sorting behaviours
- added %is_locked% to playlist switcher panel formatting
- now sets maximum height for seekbar
- fixed some other minor issues

### pre-alpha 11

#### v3

Released 2005.05.26

- fixed playlist switcher context menus were slow
- fixed using %\_system_month% would either crash, or return the year instead
- fixed playlist view action when double clicking on empty space was broken.

#### v2

Released 2005.05.26

- fixed a size limit bug for splitters in v1

#### v1

Released 2005.05.25

- date fields apply everywhere, added julian days field
- fixed problem with column widths and hiding columns with auto-resizing mode
  off
- fixed window overlapping with hidden panels in layout host
- deleting a playlist attempts to activate another playlist
- fixed keyboard conextmenu key did not work in layout tree in prefs
- fixed playlist switcher panel used wrong default colour for selected text
- fixed importing an fcs file made with 0.1.2 did not 'use global variables for
  display' correctly.
- fixed orientation drop down on common controls 5
- fixed size limit problems with splitters
- fixed wrong colour on "active item frame" colour patch in prefs
- fixed toggling "shift + lmb.." changed playlist switch panel formatting string
- other fixes

### pre-alpha 10

Released 2005.05.23

- added full config for colours in "colours and fonts" page for default playlist
  view
- all colours default to system values
- changed spelling from uk engligh to us
- added $set_style function in colour string, to replace existing colour string
  syntax when fully implemented
- added confirmation dialog when you delete a playlist through delete key on
  keyboard (and removed option from prefs)
- fixed opening and closing a popup window didnt restore focus to previously
  focused window
- changes to playlist switcher panel colours correctly applied when apply
  pressed

### pre-alpha 9

private release

- size limits obeyed for child splitters
- max size limits enforced on extension in layout host
- fixed clipped config pages
- minor changes to config
- fixed status text control was broken in layout host
- fixed no status bar descriptions for context menu items in default playlist
  view, playlist switcher.
- changed default fonts
- updated to a25 sdk

### pre-alpha 8

private release

- killed some options from prefs
- fixed:
  - Default paths for menu item actin lists in prefs is missing (regression from
    updating to 0.9)
  - “Action to perform when double clicking..” on playlist view tab is initially
    blank on clean install
  - Removing and reinserting the playback order dropdown results in it using the
    System font.
- host caption uses COLOR_3DFACE as oposed to COLOR_MENUBAR on winxp with themes
  off

### pre-alpha 7

private release

- further config clean-up
- prevented windows being overlapped in some instances (but not all). proper fix
  to come when size limits fixed for child splitters.

### pre-alpha 6

private release

- updated for alpha 23
- activated experimental autohide (for splitters only ATM)
- some more prefs changes

### pre-alpha 5

private release

- status bar displays "loading track..." when file is being opened
- fixed a caching bug when playlists reordered
- fixed toggling columns from header context menu
- fixed show caption from panel in layout area's context menu
- fixed resizing in splitters at >1 depth
- `<del>`made auto hide for splitters half-work`</del>` prob wont be finished in
  time for release
- serveral other bug fixes/changes

### pre-alpha 4

private release

- fixed some bugs in prefs with 120DPI display
- some initial reorganising of prefs
- updated for 0.9 alpha 21

### pre-alpha 3

private release

- fixed show caption in layout prefs
- some other clean-ups to layout config page
- implemented configure button in prefs page
- fixed left/right keys in playback order drop down
- ui extension api changes (should be ready for an initial release)
- implemented generic host for vis extensions
- make standard spectrum analyser a vis extension
- fixed show caption/locked changes from layout ui weren't saved
- fixed changing show caption from ui didnt check obeying minimum heights etc.
- ui does not redraw when rebuilding layout
- fixed extension instance data not saved correctly on shutdown
- other bug fixes
- autosize no longer default mode again
- updated 0.9 alpah 20

### pre-alpha 2

private release

- Changed string for default title column
- Fixed bug where toggling enable sidebar, show status bar, and show toolbars
  from preferences did not take immediate effect.
- Fixed bug where nth (n>0) instance of playlist switcher had items with 1px
  height.
- Fixed a selection bug where up/down keys had no effect if first/last item on
  playlist was focused but not selected

### pre-alpha 1

private release

#### Bug fixes

- Toggling spectrum analyser bars mode sometimes required you to toggle mode
  twice to take effect
- Tabs in Columns UI preferences did not have correct background under XP themes
  when Columns UI is not active UI
- libpng linked to different CRT than msvcrt.dll would cause a crash on playback
  buttons toolbar creation when using PNG buttons

#### Other changes

- The Columns UI playlist view is now a multiple instance UI Extension
- Configurable layout for main UI area
- Some cached config vars are now written/updated correctly when you e.g. Save
  All in preferences
- Display cache is persistant across multiple playlists
- Sorted column state remembered across playlist switchs
- Configurable playlist tabs font
- Whether selection frame is above or below text is now configurable
- Caches compiled versions of titleformatting scripts
- Re-coded speed test
- Updated to UI Extension API 6.0
- Compiled with MSVC 7.1 toolkit
- Updated to 0.9 alpah 19 SDK
- Playlist view no longer uses BeginPaint/EndPaint in WM_PAINT handler
- Global variables now use new functions
  $set_global(var, val) and
  $get_global(var). (Former in global string, latter
  in other strings).

## 0.1.2

### final

Released 2004.12.28

- focus is restored to correct window after clicking on a menu item
- mouse wheel now scrolls correct window when turning mouse whell in non-client
  area (e.g. scrollbar)
- added option to disable delete key in playlist switcher panel
- added vis bars mode

### RC2

Released 2004.12.23

- On XP, panel title backgrounds are drawn using uxtheme as the rebar
  background. The background colour of the sidebar is now COLOR_BTNFACE on all
  OSs.
- Fixed aforementioned tooltip bug in playlist, playlist switcher panel

### RC1

Released 2004.12.08

- The focused window should be remembered when you focus foobar again
- The vis was fixed up

- Alt etc. keys will work when you have a menu in the sidebar
- Fixed visibility etc. stuff in sidebar, they where broken in beta 4. So now
  e.g. for the playlistfind panel going to components/playlistfind/find in
  playlist will show the panel/sidebar if necessary (doesnt work if you use
  autohide though)

### beta 4

Released 2004.11.25

- Sidebar: Invalid description was displayed for panel menu entries in host menu
- Playlist view: Changing font, or changing its size through menu items resulted
  in messed up vertical scrollbar
- Misc: Changed format of import/export command line commands

- Misc: Fixed console output of "Info" command in preferences when cannot find
  libpng/zlib
- Misc: Rearranged some prefs
- Menubar: Fixed common controls version 5.81 compatibility
- API: Implemented new version of UI Extension api
- Playlists panel: Tab characters are no longer used to indicate right aligned
  text in playlist switcher panel (was broken, and fixing it would cause mess
  probably)
- Other minor fixes

### beta 3

Released 2004.11.08

- toolbars are added where you right click
- toolbars widths are remembered next time you add them
- you can hold shift when inserting a toolbar to force a new instance
- fixed bug in speed test, added total time to speed test
- other fixes/changes

### beta 2

Released 2004.10.30

- fixed sidebar hide delay
- pressing delete in playlist switcher panel now deletes the selected (i.e.
  active) playlist
- autoscroll no longer conflicts with middle clickaction in playlist switcher
  panel
- added option to choose middle click in playlist action
- minor fix for tooltips in playlist switcher panel
- hopefully fixed sidebar panel resizing bugs

### beta 1

Released 2004.10.23

- mousewheel scrolls window underneath cursor
- png loader sets PNG_TRANSFORM_PACKING, PNG_TRANSFORM_EXPAND and
  PNG_TRANSFORM_SHIFT flags as suggestted by kode54
- fixed transparency & 32 bpp pngs when desktop is set to <32 bpp, or you were
  using my laptop
- png loader now attempts to load libpng13.dll first
- tab key stops at playlist tabs
- other bugfixes

### alpha 5

Released 2004.10.20

- sidebar panel captions are now optional, default to off for toolbars
- added SHIFT, CTRL modifier key for adding panels to sidebar, as described
  above
- ui_drop_item_callback now supported
- added simple commandline support for importing/exporting fcs files, so you can
  associate them if you want. see foobar2000 /columnsui:help for details.
- added option to disable drawing of playback button backgrounds and remove the
  padding around the bitmaps (requires restart of foobar, buttons are still
  indented on mousedown since there isn't any other mouse down effect used)
- modifed appearance of sidebar panel captions
- added custom sidebar auto hide show/hide delay settings
- speed test now tests all formatting strings & columns
- fixed vis colour chooser
- added option to remove underscores for dropped playlists
- added option for action when doubleclicking on empty space on playlist
- not registered as a dialog with the dialog manager anymore; fixes
  "IDOK"/default push button stuff for ui_extensions that are dialogs (was using
  bad workaround before), and used another work around for the broken tabbing
  that results as a result of not using dialog manager...
- fixed old columns auto-sizing bug
- info button in prefs detects libpng & zlib
- added option to use titleformatting with playlist switcher panel
- fixed some bugs in playlist switcher drawing code
- changed wm_mousewheel handler, should scroll properly for pages now
- added annoying warning to "List all toolbars"

### alpha 4

Released 2004.09.25

- fixed bug in painting menu, button toolbar backgrounds
- fixed escape in menubar
- fixed "edit this column"

- added sidebar panel captionbars
- implement revised ui_extension api
- ui is now tabable
- changed sidebar add panel behaviour

### alpha 3

Released 2004.09.01

- fixed sending useless messages to seekbar again
- fixed status bar action dropdown on win2k
- fixed playlist switcher colour options do not update properly on apply
- fixed inaccurate clipped text detection in playlist switcher panel
- changed panel resizing behaviour
- fixed status bar drawing bug
- fixed status bar part sizing bug
- fixed status bar repainting bug
- fixed sidebar autohide a bit
- fixed: when rebar was above sidebar in z-order, when rebar height changed,
  sidebar panels were not repainted properly
- fixed - toggling "show header" did not make it appear again until window
  resized
- fixed vis, playlist switcher panel edge, playlist switcher item height
  settings
- added option to not show sort arrows in playlist
- added more menu items
- fixed "selected tracks length" when items added to playlist already selected
- fixed playlist painting bug when scrolling to bottom of playlist and sizing
  downwards

### alpha 2

Released 2004.08.27

- fixed panel resizing
- fixed navigation keys when no focus on playlist
- fixed double clicking on sidebar separator
- status bar can now be hidden
- added optinal left/top/right/bottom frame colours to colour string
- added "add to new playlist" on playlists list panel drag & drop context menu
- changed colour string parsing code to accomodate the above colours as
  optional; strings that output in bad format may be broken as a result
- added auto-hide (mouse) for sidebar; does not work properly yet (may be
  removed if it proves too much hassle to fix)
- made some changes to ui extension api; broke compatibility so update other
  panels as well

### alpha 1

Released 2004.08.25

- bugfix: some toolbar windows where not destroyed when the toolbar was removed,
  but recreated later
- several other various bug fixes
- implemented new sidebar, rewrote rebar code
- use proposed ui_extension api for sidebar, toolbars
- added tooltips support for playlist switcher ui
- toolbars can be completely hidden (useful without xp themes)

## 0.1.1

### final

Released 2004.07.06

- Fixed a selection bug
- Fixed the seekbar timer bug from beta 10
- Fixed shift+lmb to delete playlists

### beta 10

- Bug fixes

### beta 9

- Bug fixes

### beta 8

- Bug fixes

### beta 7

- Bug fixes

### beta 6

- Bug fixes

### beta 5

- Bug fixes

### beta 4

- Bug fixes

### beta 3

- Bug fixes

### beta 2

- Bug fixes

### beta 1

Released 2004.05.31

- lower memory usage
- tabbed preferences
- playlist sidebar matches appearance of playlist
- more customisable colours for sidebar
- option for multiline tabs
- shift+lmb to delete playlists
- bunch of things to generate better names for playlists when files dropped on
  sidebar/tabs (from dir name, playlist, or formatting string)
- delay for autoswitch option
- menu descriptions for all menus (was only main menu before)
- customisable action for double clicking on status bar
- increase/decrease font shortcuts
- fifth colour in colour string - colour for selected items when focus is not on
  playlist window
- day/week/year in playlist
- upnorth's single-click-to-toggle-sidebar-at-left-edge-of-screen
- mouseover custom toolbar images, put them in the same bmp to the right of
  existing buttons
- customisable editor font, preview to console, colour code picker
- option to map colour codes for global variables
- numerous bug fixes (inc. the systray bug, balloon tip + dynamic bitrate,
  reseting colour codes, ellipsis etc.)

## 0.1

### final

Released 2004.05.10

- Bug fixes

### RC4

Released 2004.05.05

- Fixed item height setting
- Fixed menus on multi-monitor displays

### RC3

Released 2004.04.27

- fixed minor bug when menu button partially off the left off the screen, menu
  would appear in strange place
- fixed weird delay when scroll playlist horiz using mouse wheel
- fixed column reordering + cancel
- header correctly sized when scrollbar shown/hidden
- fixed some font handles were being unneccessarily created
- fixed some bug in playlist painting; probably sometimes caused more to be
  painted than neccessary
- fixed you could see playlist scrolling to focused item on startup
- the import/export option includes the status bar font now
- more error checking when importing
- fixed dynamic titles on systray
- other minor fixes

### RC2

Released 2004.04.16

- shift + drag on seekbar
- fixed: header alignment on sorted columns
- insert + copy buttons
- added rearrangement of columns from the header
- fixed '&' characters in tabs
- ctrl + a on column config
- tray icon recreated when explorer restarts
- rebar remenbers previous positions of toolbars
- when importing config, auto-sizing takes effect without restart
- made tabs look better in some circumstances
- on first startup, the window is not hidden
- fixed minor repainting bug with the header
- fixed minor bug when remember window positions is disabled
- changed some systray behaviour
- random fixes

### RC1

Released 2004.04.07

- "Enable double clicking to rename playlists" works when "Enable middle/double
  clicking to add playlists" is not enabled.
- fixed minor bug where focus was taken away from foobar on startup temporarily
- fixed playback buttons padding on right
- added tooltips on playback buttons
- menu dsecriptions on status bar
- fixed resizing hidden playlist sidebar
- consistent sizing of total length of selected tracks on status bar
- return of ctrl-click, death of alt-click
- option for alternate playlist selections model, which is more like standard ui
  / original columns ui behaviour
- sort sel only option only effective when when selection is greater than 1
- header context menu rearranged a bit
- renaming active playlist correctly updates shown columns
- seekbar improvements: increased accuracy; can press escape to cancel seek
- in tabs/sidebar, playlist keyboard shortcuts no longer executed

### beta 8

Released 28.03.2004

- fixed colour codes bug with multibyte chars
- fixed resizing columns in non-autoresizing mode

### beta 7

Released 27.03.2004

- sorting (by column) now has a "memory" of items previous location in playlist
  (i.e. so you can combine sorts, e.g. click title column then artist column
  will get you an artist - title sort)
- tidied up prefs a bit
- option to rename playlists by double clicking on them
- some fixes in playlist sidebar
- fixed some problem exhibited with themes and/or xp sp2
- can no longer resize columns in auto sizing mode
- status bar is correctly set above other controls; i.e. no sillyness when
  window sized small
- on startup, playlist should not visibily appear before everything else anymore
- can hide/show individual columns (easy access in header context menu)
- ctrl click for multiple selections
- when importing, relevant parts of ui are updated (background colours etc.)
- changed fcs file format slightly, so i dont have to break backwards
  compatibility in the future
- can double click on plist divider to hide/show it
- can use old global string behaviour if want (is simpler with colour codes, but
  is far slower)
- window title is only updated when actually changes (avoids problem when mouse
  over close etc. butttons, at least here)

### beta 6

Released 15.03.2004

- fix ellipsis + colour codes
- fixed wrong tooltips when playlist horizontally displaced
- fix toggling playlists autohide setting + tabs
- maximised state is correctly restored after closing foobar whilst minimised
- fixed status bar font colour
- fix horizontal scrollbar when switch playlist
- fixed toggling no horizontal scrollbar mode setting if h scrollbar is visible
- fixed sorting - colour codes, non latin (?) characters (é í ó ú á etc.)
- numerous other bug fixes
- scrolling horizontally with mouse wheel moves in slightly bigger steps
- ctrl + mouse wheel scrolls horizontally
- ctrl + lmb drag does drag & drop; old ctrl + lmb click behaviour moved to
  ALT-click
- can remove total length of selected tracks from status bar
- some sorting selection only stuff
- middle clicking stuff works in the playlist sidebar
- items are highlighted when you drop then on foobar
- option to not have mouse over effect on column titles (as a result you cant
  click them, though)
- extra padding on left side of status bar
- standard/system vis colours are in choose colour dialogue
- can select vis border
- separate playlist sidecar + playlist item height settings
- redesigned columns prefs page
- toggling columns title header no longer requires restart
- can set no. decimal places in selected tracks length
- can double click in tabs/ playlist sidecar to add playlists
- replaced global string with global variables.
- improved "no horizontal scrolling" mode

### beta 5

Released 03.03.2004

- fixed spacing in front of toolbars
- option"show ellipsis.." uses ellipsis char
- ellipsis is placed at preceeding character that is not a space or full
  stop/period
- "use custom buttons" bitmap can be of any size now, and buttons will be
  accordingly sized
- global string is combined with colour string again
- option to scroll horizontally with mouse wheel when no vertical scrollbar
- improved alt-key menu accessibility/behaviour
- fixed keyboard shortcuts executed twice when tabs focused
- fixed playlist list shows wrong selection when reorder playlists from
  elsewhere
- some playlist keyboard shortcuts (up/dwn/pgup etc.) fixes
- when playing non-seekable track (e.g. stream), seekbar is correctly disabled
- some minor fixes to drag + drop
- cancel menu displayed when items dropped on with right button
- fixed some other minor things

### beta 4

Released 28.02.2004

- tabs/playlists auto hide (needs enabling)
- can drag tabs/playlists around (needs enabling)
- changed menu style
- can no longer loose the playlist by dragging playlist list too far
- show global shortcuts in systray menu
- ctrl rclick in playlist maintains selection like in std ui
- rclick statusbar shows now playing menu like std ui
- playlist filters support wildcards thanks to new 0.8 helpers
- toolbars/rebar no longer destroyed when just changing its config
- shift+ctrl works with pgup/down/hme/end
- balloon tip shortcut
- other minor fixes

### beta 3

Released 17.02.2004

- fixed some annoying selection bugs
- fixed ping on ALT \* shortcuts (thanks kode54)

### beta 2

Released 17.02.2004

- fix aforementioned crash bug when drag items to left & tooltips enabled
- changed selection behaviours (shift click, ctrl click, pg up/pg down/home/end,
  shift up/down/pg up/pg down/home/end, ctrl pg up/down /home/end)
- made menu shorter
- removed spacing under toolbars
- menu "single click" thing works
- added options to hide volume/keyboard shortcuts/now playing menu
- reduced number of options that need restart to work
- fixed descending sort
- fixed scroll position when minimised
- fix separator shown in context menu when no menu entries in playlist/selection
- right aligned columns have padding like left aligned ones
- listbox playlist switcher is now reizable
- alternative playlist border, same options for listbox playlist switcher
- made drag + drop on listbox pl switcher like the tabs
- other minor changes/fixes

### beta 1

Released 11.02.2004

- selection menu items in playlist context menu
- now playing context menu items in systray context menu
- fixed cannot delete active tab/playlist
- in tabs contextmenu, fixed "Load playlist", added "Save all playlists"
- extra space between playlist & statusbar should be fixed now also some
  statusbar sizing bugs causing wierdness when resizing
- fixed resource leak in main menu, also improved menu behaviour slightly
- fixed some other min/max related bugs
- minimium size of window is now set
- can use playlist as source for drag & drop operations via rightmouse button
  (no context menu as yet)
- use new 0.8 functions to process dropped files so can drop .urls etc now
- some improvements to rebar (set some minumim widths/heights, made playback
  buttons slightly smaller)
- fixed inaccuracy in seekbar
- double clicking the volume/selected tracks time does the same actios as in
  standard ui.
- option to switch playlist when dragging items over its tab
- when items dropped over a tab, they are added to that playlist

### alpha 9

Released 08.02.2004

- support left/right/centre alignment for columns
- support playlist "filters" for columns
- some internal changes & fixes, and slightly less memory usage
- updated to 0.8 sdk, added some related features
- global colour string, with option to use individual string for each column
- changed colour of toolbar buttons; can also now also set your own bitmap for
  it
- added import/export tools
- fixed colour codes shown in tooltips
- "global" string also used when sorting.
- added some options from standard ui.

### alpha 8

Released 01.02.2004

- changed selection behaviour
- improved seekbar, can grip from anywhere, added tooltip
- added tooltips support (on very old operating systems e.g. original win95 they
  wont be vertically centre aligned)
- clicking on columns remmbers asc/desc sort, and puts arrows on column (on
  below xp they are just some triangles i drew, on xp & above they come from
  visual theme or somewhere)
- added horizontal scrollbarless mode, use widths in prefs as ratios. (resizing
  columns from ui wont work in this mode.)
- fixed crash when item height becomes zero
- fixed removing plaback buttons
- fixed renaming playlist in tabs
- fixed blurred tray icon, tray icon resource leak (thanks kode54)
- fixed vertical scrollbar redrawing bug in prveious version

### alpha 7

Released 29.01.2004

- fix turnng off toolbar buttons
- handle mouse wheel turning
- fix rendering when scrolling
- fix total time count
- some more options for fonts/ colours

### alpha 6

Released 28.01.2004

- can move mouse between menus, sort of
- seekbar seeks to where you click, no instant seeking
- show ellipsis when text cropped
- global string for $puts
- balloon tips
- fixed redraw problems with rebar when moving things around
- buttons toolbar
- separated prefs into two pages
- other minor things

### alpha 5

Released 26.01.2004

- fixed files added via drag & drop sent in ansi encoding not utf8
- minimised flickering of tabs playlist switcher, status bar when resizing
- double clicking columns divider now takes account of any colour codes in your
  formatting strings
- changed way columns are sorted when clicking on them
- added context menu for header with descending sort option
- added optional middle clicking for tabs
- fixed item height setting set to 0 when entering prefs
- fixed some mouse selection behaviours
- playback order dropdown minimun width set to width of widest name
- some improvements to rebar

### alpha 4

Released 25.01.2004

- fixed playback order drop down
- fixed scrollbar not redrawn on "ensure visible"
- fixed incorrect positioning of controls
- fixed systray menu not destroyed when click out of it
- added alternative playlist switcher using tabs

### alpha 3

Released 24.01.2004

- mouse movements captured outside of playlist (i.e. scrolls when mouse
  below/above playlist area)
- more keyboard actions added (enter, shift/ctrl modifiers)
- fixed width of columns not saved from prefs
- added provisional drag & drop support
- added separate config for status bar font
- ensure visible focuses items in the centre of playlist
- playlist renamer

### alpha 2

Released 24.01.2004

- fixed crash w/ new columns
- improved keyboard navigation of playlist (added home/end/pg up/page
  down/alt-up/alt-down/space actions & fixed up/down keys; also removed
  jerkyness/corruptions when scrolling past top/bottom of playlist area using
  up/down keys)
- fixed scrolling too far past end of playlist
- corrected font of playback order dropdown

### alpha 1

Released 21.01.2004

- first version :-)

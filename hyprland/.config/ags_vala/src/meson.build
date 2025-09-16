pkgdatadir = get_option('prefix') / get_option('datadir')
bindir = get_option('prefix') / get_option('bindir')
blp = find_program('blueprint-compiler', required: true)
sass = find_program('sass', required: true)

dependencies = [
  dependency('gtk4-layer-shell-0'),
  dependency('astal-io-0.1'),
  dependency('glib-2.0'),
  dependency('gsound'),
  dependency('gio-2.0'),
  dependency('gio-unix-2.0'),
  dependency('libsoup-3.0'),
  dependency('astal-4-4.0'),
  dependency('astal-battery-0.1'),
  dependency('astal-hyprland-0.1'),
  dependency('astal-wireplumber-0.1'),
  dependency('astal-mpris-0.1'),
  dependency('astal-network-0.1'),
  dependency('astal-notifd-0.1'),
  dependency('astal-apps-0.1'),
  dependency('astal-network-0.1'),
  dependency('libnm'),
  dependency('astal-mpris-0.1'),
  dependency('astal-power-profiles-0.1'),
  dependency('astal-tray-0.1'),
  dependency('astal-bluetooth-0.1'),
  dependency('astal-io-0.1'),
  dependency('libadwaita-1', version: '>= 1.6.0'),
]

blueprint_sources = files(
  'ui/AppButton.blp',
  'ui/Bar.blp',
  'ui/Dashboard.blp',
  'ui/NotificationContent.blp',
  'ui/Overview.blp',
  'ui/PowerMenu.blp',
  'ui/QAudioItem.blp',
  'ui/QMediaPlayer.blp',
  'ui/QMultimedia.blp',
  'ui/Qheader.blp',
  'ui/QuickMenu.blp',
)

vala_sources = files(
  'vala/App.vala',
  'vala/bar/Bar.vala',
  'vala/bar/items/Workspaces.vala',
  'vala/dashboard/Dashboard.vala',
  'vala/notification/NotificationCenter.vala',
  'vala/notification/NotificationContent.vala',
  'vala/notification/NotificationItem.vala',
  'vala/overview/AppButton.vala',
  'vala/overview/Overview.vala',
  'vala/powermenu/PowerMenu.vala',
  'vala/quickmenu/QAudioItem.vala',
  'vala/quickmenu/QMediaPlayer.vala',
  'vala/quickmenu/QMultimedia.vala',
  'vala/quickmenu/Qheader.vala',
  'vala/quickmenu/QuickMenu.vala',
  'vala/utils/PopupWindow.vala',
  'vala/utils/Scss.vala',
  'vala/utils/Underlay.vala',
)

# transplie blueprints
ui = custom_target(
  'blueprint',
  input: blueprint_sources,
  output: '.',
  command: [
    blp,
    'batch-compile',
    '@OUTPUT@',
    '@CURRENT_SOURCE_DIR@',
    '@INPUT@',
  ],
)

# bundle scss files
css = custom_target(
  'scss',
  input: files('scss/main.scss'),
  command: [sass, '@INPUT@', '@OUTPUT@'],
  output: ['main.css'],
)

# compiling data files into a binary
resource = import('gnome').compile_resources(
  'data',
  files('gresource.xml'),
  dependencies: [ui, css],
  source_dir: meson.current_build_dir(),
)

executable(
  meson.project_name(),
  project_resources,
  dependencies: dependencies,
  sources: [vala_sources, resource],
  link_args: ['-lm'], # Link math library
  install: true,
  install_dir: bindir,
)

subdir('cli')

project(
  'mui',
  ['vala', 'c'],
  version: run_command('cat', 'version').stdout().strip(),
  meson_version: '>= 1.7.2',
)

subdir('src/lib/Math')
subdir('src')
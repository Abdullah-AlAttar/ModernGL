

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_SQUEAKY']


sources = [
  './include/sq/core/display.cpp'
]

squeaky_lib = shared_library('squeaky',
  sources : sources,
  install : true,
  cpp_args : lib_args,
  include_directories: include_directories('./include'),
  dependencies : [glew_dep, spdlog_dep, sdl2_dep, glm_dep, libdl_dep]
)

# Make this library usable as a Meson subproject.
squeaky_dep = declare_dependency(
  include_directories: include_directories('./include'),
  link_with : squeaky_lib,
  dependencies : [glew_dep, spdlog_dep, sdl2_dep, glm_dep, libdl_dep])

# Make this library usable from the system's
# package manager.
# install_headers('./include/sq/core/modrengl.hpp', subdir : 'sq/core')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'SqueakyEngine',
  filebase : 'sq',
  description : 'Game engine',
  subdirs : 'sq',
  libraries : squeaky_lib,
  version : '0.1',
)

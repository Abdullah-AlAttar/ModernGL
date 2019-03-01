project('SqueakyEngine', 'cpp','c',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])




glew_dep = dependency('glew',fallback : ['glew', 'glew_dep'])

spdlog_dep = dependency('spdlog', fallback :['spdlog', 'spdlog_dep'])

sdl2_dep = dependency('sdl2',fallback : ['sdl2', 'sdl2_dep'])

glm_dep = dependency('glm',fallback : ['glm', 'glm_dep'])

cmplr = meson.get_compiler('cpp')
libdl_dep = cmplr.find_library('dl')

subdir('squeaky')
subdir('sandbox')
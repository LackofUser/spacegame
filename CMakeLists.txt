cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION})
# CMake requires this to be set, so we will just tell it what it wants to hear

project("Spacegame" C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

find_package(SDL2 REQUIRED)

include(FindPkgConfig)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

find_library(M_LIB m)

include_directories(spacegame ${SDL2_INCLUDE_DIRS} resources/include/)

add_executable(spacegame main.c base.c)
target_link_libraries(spacegame ${SDL2_LIBRARIES} ${M_LIB} ${SDL2IMAGE_LIBRARIES})

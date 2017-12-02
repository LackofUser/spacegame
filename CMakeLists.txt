cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION})
# CMake requires this to be set, so lets just tell it what it wants to hear

project("Spacegame" C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

find_package(SDL2 REQUIRED)
find_library(M_LIB m)

include_directories(spacegame ${SDL2_INCLUDE_DIRS} include)

add_executable(spacegame main.c)
target_link_libraries(spacegame ${SDL2_LIBRARIES} ${M_LIB})

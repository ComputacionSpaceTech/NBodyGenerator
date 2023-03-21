cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(NBODY)

add_subdirectory(src)

add_executable(generator generator.cpp)

target_link_libraries(generator nbody_simulator)

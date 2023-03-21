SET(SRC "BodyGenerator.cpp")

add_library(nbody_simulator "${SRC}")

find_package(Eigen3 CONFIG REQUIRED)

target_link_libraries(nbody_simulator PUBLIC Eigen3::Eigen)

target_include_directories(nbody_simulator PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_compile_features(nbody_simulator PUBLIC cxx_std_20)

set_target_properties(nbody_simulator PROPERTIES  CXX_EXTENSIONS OFF)

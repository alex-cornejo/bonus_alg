cmake_minimum_required(VERSION 3.16)
project(Bonus)

set(CMAKE_CXX_STANDARD 14)

#SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

include(build/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Bonus src/main.cpp src/Solver.cpp src/Solver.h src/utils/FileUtil.h src/utils/FileUtil.cpp src/combinations/combinations.hpp src/combinations/combinations_init.hpp)

target_link_libraries(Bonus ${CONAN_LIBS})
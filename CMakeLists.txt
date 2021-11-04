cmake_minimum_required(VERSION 3.16)
project(bonus_alg)

set(CMAKE_CXX_STANDARD 14)

#SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

add_executable(bonus_alg src/main.cpp src/algorithm/BonusSolver.cpp src/algorithm/BonusSolver.h src/utils/FileUtil.h src/utils/FileUtil.cpp src/combinations/combinations.hpp src/combinations/combinations_init.hpp src/algorithm/BonSolver.cpp src/algorithm/BonSolver.h src/algorithm/BFFSolver.cpp src/algorithm/BFFSolver.h)
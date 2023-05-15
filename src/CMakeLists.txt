cmake_minimum_required(VERSION 3.14)
project(LambertsProblem)

set(CMAKE_CXX_STANDARD 17)

add_library(LambertsProblem Vector3D.hpp Stumff.hpp StumpffFunc.hpp ../tests/Lambert.cpp)
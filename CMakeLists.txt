cmake_minimum_required(VERSION 3.21.3)

project(pyrho CXX)

add_executable(pyrho src/PyRho.cpp)

target_compile_features(pyrho PRIVATE cxx_std_17)

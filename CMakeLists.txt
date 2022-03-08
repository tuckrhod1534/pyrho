cmake_minimum_required(VERSION 3.21.3)

project(pyrho CXX)

enable_testing()

add_executable(pyrho
    src/main.cpp
    src/PyRho20.cpp
    src/PyRho20.h
    src/PyRho20.qrc
)

find_package(Qt REQUIRED)

target_link_libraries(pyrho Qt::Core)

# tests target
add_executable(tests
    src/tests/main.cpp
    src/tests/PyRho_tests.cpp
)
target_compile_features(tests PRIVATE cxx_std_11)

find_package(GTest REQUIRED)

target_link_libraries(tests GTest::gtest)
include(GoogleTest)
gtest_add_tests(TARGET tests)
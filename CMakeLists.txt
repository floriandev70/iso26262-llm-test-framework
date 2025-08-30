cmake_minimum_required(VERSION 3.28)
project(gTest_test)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)


add_executable(gTest_test main/main.cpp
        Lab/boolean_algebra.cpp
        Lab/Tests/boolean_algebra_tests.cpp
        Lab/includes/boolean_algebra.h
        Lab/tests/math_lib_tests.cpp
        Lab/math_lib.cpp
        Lab/includes/math_lib.h
        Lab/includes/real_world.h
        Lab/real_world.cpp
        Lab/tests/real_world_tests.cpp
        Lab/tests/dimi.cpp
        Lab/tests/dimi.cpp
        Lab/tests/dimis_supadupa.cpp)

target_include_directories(gTest_test
        PRIVATE
        ${GTEST_INCLUDE_DIRS})

target_link_libraries(gTest_test
        PRIVATE
        GTest::GTest
        Threads::Threads)

target_compile_options(gTest_test PRIVATE -Wall -Werror)

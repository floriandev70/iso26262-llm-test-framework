cmake_minimum_required(VERSION 3.20)
project(gTest_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Optional: Code Coverage Flags (enable manually if needed)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Debug mode enabled - enabling coverage flags")
  add_compile_options(--coverage)
  add_link_options(--coverage)
endif()

# Enable testing infrastructure
enable_testing()

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include your source files
add_subdirectory(Lab)
add_subdirectory(main)

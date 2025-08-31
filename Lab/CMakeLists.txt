file(GLOB_RECURSE LAB_SOURCES CONFIGURE_DEPENDS
  *.cpp
  *.h
)

add_executable(unit_tests ${LAB_SOURCES})

target_link_libraries(unit_tests
  gtest
  gtest_main
)

# Enable GoogleTest integration
include(GoogleTest)
gtest_discover_tests(unit_tests)

include_guard()

enable_testing()

add_executable(giscc_tests
    tests/test_basealg.cpp
    tests/test_idw.cpp
)

target_link_libraries(giscc_tests
    giscc
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(giscc_tests)

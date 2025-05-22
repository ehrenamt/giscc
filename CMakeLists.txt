cmake_minimum_required(VERSION 3.14) # may be able to use older versions

project(giscc LANGUAGES CXX) # temporary name

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Using GoogleTest. See: https://google.github.io/googletest/quickstart-cmake.html

include(FetchContent)
FetchContent_Declare(
    googletest
    # GoogleTest 1.17.0
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(giscc
    src/algorithms/delaunay.cpp
    src/algorithms/idw.cpp
)

target_include_directories(giscc PUBLIC include)

enable_testing()

add_executable(giscc_tests
    tests/test_basealg.cpp
    tests/test_idw.cpp # placeholder
)

target_link_libraries(giscc_tests
    giscc
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(giscc_tests)

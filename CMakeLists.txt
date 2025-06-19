cmake_minimum_required(VERSION 3.14) # may be able to use older versions

project(giscc LANGUAGES CXX) # temporary name

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Using GoogleTest. See: https://google.github.io/googletest/quickstart-cmake.html
#

include(FetchContent)
FetchContent_Declare(
    googletest
    # GoogleTest 1.17.0
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

#
# For Windows: Prevent overriding the parent project's compiler/linker settings
#

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(cmake/sources.cmake)

target_include_directories(giscc PUBLIC include)

#
# Configure unit tests
#

include(cmake/tests.cmake)

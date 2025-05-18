cmake_minimum_required(VERSION 3.14) # may be able to use older versions

project(giscc LANGUAGES CXX) # temporary name

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(giscc
    src/algorithms/delauny.cpp
    src/algorithms/idw.cpp
)

target_include_directories(giscc PUBLIC include)

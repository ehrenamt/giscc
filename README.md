# giscc - a GIS library in C++

> A C++ library for geospatial data structures and algorithms, designed to work with modern C++ (up to and including the C++20 standard), and based on Markus Schneider's algebra model for spatial data types for database systems.

> [!NOTE]
> CURRENTLY BROKEN - DOES NOT COMPILE.

> [!NOTE]
> This is a work in progress. Please check back later as I work and improve this project!

<p align="center">
  <a href="#features">Features</a> •
  <a href="#examples">Examples</a> •
  <a href="#installation">Installation</a> •
  <a href="#tests">Tests</a>
</p>

# Features

## Planned

- A set of geospatial primitives
- An IDW interpolation algorithm
- A Delaunay triangulation algorithm
- Additional Interpolation algorithms
- Spatial join and overlap algorithms
- R and R\* trees

# Examples

Usage examples are demonstrated in the `/examples` subfolder.

# Installation & Build

<div id=installation>

## Build

This project uses features up to and including C++20 and uses CMake as the build system. A CMake file is included to build the library.

To build, ensure your device supports `C++20` and `CMake` is installed and added to PATH.

Configure the build directory using

```
cmake -S . -B build
```

Then run

```
cmake --build build
```

# Tests

> [!NOTE]
> This is a work in progress. The current tests are basic, incomplete, and do not cover edge cases for the completed algorithms.

This project depends on GoogleTest 1.17.0 (latest as of May 2025 development) for testing.

Tests are located in the `/tests` directory. To run tests, first [build](#build) the project, then enter the build directory.

```
cd build
```

Run the tests via

```
ctest
```

Tests will be added once these algorithms are fully-functioning.

# giscc - a GIS library in C++

> A C++ library for geospatial data structures and algorithms, designed to work with modern C++ (up to and including the C++20 standard).

> [!NOTE]
> This is a work in progress. Please check back later as I work on, improve, and add new features!
> 

# Features

Nothing is fully implemented, but I plan to add at least

- A set of geospatial primitives (meant to work with these algorithms, but usage is optional)
- A Delaunay triangulation algorithm
- An inverse-distance weighting algorithm (as well as potentially other )
- R and R* trees

# Installation & Build

This project uses features up to and including C++20.

# Examples

This is a work in progress. Please check back later as I work on, improve, and add new features!

# Tests

This project depends on GoogleTest 1.17.0 (latest as of development) for testing.

Tests are located in the ```/tests``` directory. To run tests, first build the project, then enter the build directory.

```
cd build
```

Run the tests via

```
ctest
```

Tests will be added once these algorithms are fully-functioning.

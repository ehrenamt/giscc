/**
 * @file points.cpp
 * @brief Examples for intitializing and working with points.
 *
 */

#include <giscc/primitives.hpp>

#include <iostream>

using namespace std;
using namespace giscc;

int main() {

    // Points are created in either 2D or 3D spaces
    space2D::Point<>* point2d_1 = new space2D::Point<>();
    space3D::Point<>* point3d_1 = new space3D::Point<>();

    // cleanup
    delete point2d_1;
    delete point3d_1;

    return 0;
}

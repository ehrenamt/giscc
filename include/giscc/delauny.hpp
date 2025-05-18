/**
 * @file delauny.hpp
 * @brief Declaration of a Delauny triangulation function and its helper functions.
 *
 */

#ifndef GISCC_DELAUNY_HPP_
#define GISCC_DELAUNY_HPP_

#include <giscc/primitives.hpp>

#include <vector>

using AdjacencyList = std::vector<std::vector<size_t>>;

/**
 * @brief Compute the Delaunay triangulation as an adjacency list for a set of 2D points.
 *
 * @param points std::vector A vector of 2D points to triangulate.
 * @return std::vector<std::vector<size_t>> Adjacency list
 */
AdjacencyList delaunyTriangulation2D(const std::vector<Point2D> &points);

/**
 * Constructs a large super-triangle that contains the set of points.
 *
 * @param points std::vector A vector of 2D points around which to form a super-triangle.
 * @return A triangle whose coordinates contain the set of points.
 */
Triangle2D constructSuperTriangle(const std::vector<Point2D> &points);

/**
 *  Checks if a 2D point lies inside or on the edge of a triangle, using the Barycentric approach.
 *
 *  @return True if the point is inside or on the triangle; otherwise, false.
 */
bool pointInTriangle(Point2D &point, Triangle2D &triangle);

bool pointInTriangle(Point2D &point, std::vector<Point2D> &triangle);

#endif // GISCC_DELAUNY_HPP_
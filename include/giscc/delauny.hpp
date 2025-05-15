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

#endif // GISCC_DELAUNY_HPP_
/**
 * @file delauny.cpp
 * @brief Implementation for Delauny Triangulation
 *
 */
#include <giscc/delauny.hpp>

#include <algorithm>
#include <random>

AdjacencyList delaunyTriangulation2D(const std::vector<Point2D> &points)
{
    std::vector<std::vector<size_t>> adjList;

    // edge case: points is empty.
    if (points.empty())
        return adjList;

    // edge cases - points has less than three points? Points has exactly 3 points?

    std::vector<Point2D> pointsCopy = points;

    // begin by calculating bounds and constructing a supertriangle

    // generate random permutation, then add in order
    auto rng = std::default_random_engine{};

    // should work, but vscode highlights an error
    // std::ranges::shuffle(pointsCopy, rng);

    // temporary shuffle replacement
    std::shuffle(pointsCopy.begin(), pointsCopy.end(), rng);

    // loop to add points
    // while points is not empty
    // pop or remove from front, idk
    // find the bouding triangle (the smallest trinagle in which this fits)
    // test the three circumcircles of the bounding triangle plus this point

    // if the circumcircle test fails, go to adjacency list, delete edge and add two new ones. Add the new circumcircle tests?

    // all tests pass, write changes to adjList

    // End of loop, points are empty

    // what to do with supertriangle? Remove, then add outer edges???

    // A good triangulation meanse a sparse graph.
    // An adjacency list is more space efficient for this case.
    return adjList;
}

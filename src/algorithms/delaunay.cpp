/**
 * @file delauny.cpp
 * @brief Implementation for Delauny triangulation and its helper functions.
 *
 */
#include <giscc/delaunay.hpp>

#include <algorithm>
#include <cfloat>
#include <random>
#include <stdexcept>

AdjacencyList delaunyTriangulation2D(const std::vector<Point2D> &points)
{
    std::vector<std::vector<size_t>> adjList;

    // edge cases
    if (points.empty())
    {
        return adjList;
    }

    if (points.size() < 3)
    {
        throw std::invalid_argument("Cannot triangulate fewer than 3 points.");
    }

    if (points.size() == 3)
    {
        return adjList;
    }

    std::vector<Point2D> pointsCopy = points;

    Triangle2D superTriangle = constructSuperTriangle(pointsCopy);

    std::vector<Point2D> triangulationPoints;

    std::vector<Triangle2D> triangles;

    // generate random permutation, then add in order
    auto rng = std::default_random_engine{};

    // should work, but vscode highlights an error
    // std::ranges::shuffle(pointsCopy, rng);

    // temporary shuffle replacement
    std::shuffle(pointsCopy.begin(), pointsCopy.end(), rng);

    triangles.push_back(superTriangle);

    for (auto &p : pointsCopy)
    {

        Triangle2D boundingTriangle;

        // find the bounding triangle (the smallest trinagle in which this fits)
        // current implementation is a linear scan. This can later be replaced with more efficient algorithms.
        for (Triangle2D t : triangles)
        {
            if (pointInTriangle(p, t))
            {
                boundingTriangle = t;
                break;
            }
        }

        // add new triangles to triangulation, or test first?
        // test the three circumcircles of the bounding triangle plus this point

        // if the circumcircle test fails, go to adjacency list, delete edge and add two new ones. Add the new circumcircle tests?

        // all tests pass, write changes to adjList
    }

    // End of loop, points are empty

    // what to do with supertriangle? Remove, then add outer edges???

    // A good triangulation meanse a sparse graph.
    // An adjacency list is more space efficient for this case.
    return adjList;
}

Triangle2D constructSuperTriangle(const std::vector<Point2D> &points)
{
    if (points.empty())
    {
        throw std::invalid_argument("Point list is empty");
    }

    double min_x = DBL_MAX;
    double max_x = -DBL_MAX;
    double min_y = DBL_MAX;
    double max_y = -DBL_MAX;

    for (const auto &p : points)
    {
        if (p.x < min_x)
            min_x = p.x;
        if (p.x > max_x)
            max_x = p.x;
        if (p.y < min_y)
            min_y = p.y;
        if (p.y > max_y)
            max_y = p.y;
    }

    double diff_x = (max_x - min_x) * 10;
    double diff_y = (max_y - min_y) * 10;

    Point2D a = Point2D{min_x - diff_x, min_y - diff_y * 3};
    Point2D b = Point2D{min_x - diff_x, max_y + diff_y};
    Point2D c = Point2D{max_x + diff_x * 3, max_y + diff_y};

    return Triangle2D{a, b, c};
}

bool pointInTriangle(Point2D &point, Triangle2D &triangle)
{
    double denominator = (triangle.b.y - triangle.c.y) * (triangle.a.x - triangle.c.x) + (triangle.c.x - triangle.b.x) * (triangle.a.y - triangle.c.y);

    double alpha = ((triangle.b.y - triangle.c.y) * (point.x - triangle.c.x) + (triangle.c.x - triangle.b.x) * (point.y - triangle.c.y)) / denominator;
    double beta = ((triangle.c.y - triangle.a.y) * (point.x - triangle.c.x) + (triangle.a.x - triangle.c.x) * (point.y - triangle.c.y)) / denominator;
    double gamma = 1.0 - alpha - beta;

    return (alpha >= 0.0) && (beta >= 0.0) && (gamma >= 0.0);
}

bool pointInTriangle(Point2D &point, std::vector<Point2D> &triangle)
{
    if (triangle.size() != 3)
    {
        throw std::invalid_argument("Triangle must have exactly 3 points");
    }

    double denominator = (triangle[1].y - triangle[2].y) * (triangle[0].x - triangle[2].x) + (triangle[2].x - triangle[1].x) * (triangle[0].y - triangle[2].y);

    double alpha = ((triangle[1].y - triangle[2].y) * (point.x - triangle[2].x) + (triangle[2].x - triangle[1].x) * (point.y - triangle[2].y)) / denominator;
    double beta = ((triangle[2].y - triangle[0].y) * (point.x - triangle[2].x) + (triangle[0].x - triangle[2].x) * (point.y - triangle[2].y)) / denominator;
    double gamma = 1.0 - alpha - beta;

    return (alpha >= 0.0) && (beta >= 0.0) && (gamma >= 0.0);
}

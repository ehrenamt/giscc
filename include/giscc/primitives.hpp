/**
 * @file primitives.hpp
 * @brief Basic (primitive) data types to use in geospatial data structures and algorithms
 *
 * This header defines basic geospatial data types.
 * The data structures and algorithms in this library are designed to use these data types.
 *
 * Structs and enums are used instead of full-on classes for performance reasons.
 *
 */

#ifndef GISCC_PRIMITIVES_HPP_
#define GISCC_PRIMITIVES_HPP_

#include <iterator>
#include <variant>
#include <vector>

struct Point2D
{
    double x;
    double y;

    friend bool operator==(const Point2D &lhs, const Point2D &rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

struct Point3D
{
    double x;
    double y;
    double z;

    friend bool operator==(const Point3D &lhs, const Point3D &rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
};

// A single line from a to b. For multiple sgements, see PolyLine
template <typename PointType>
struct Line
{
    PointType a;
    PointType b;
};

template <typename PointType>
struct Polyline
{
    std::vector<PointType> points;

    // Copy constructor. Might need move?
    PolyLine(std::vector<PointType> &input) : points(input) {}
};

template <typename PointType>
struct Polygon
{
    std::vector<PointType> points;
};

enum class GeometryType : uint8_t
{
    Point2D,
    Point3D,
    Polyline2D,
    Polyline3D,
    Polygon2D,
    Polygon3D
};

// resolves to a type and can be used as a template during runtime
using Geometry = std::variant<
    Point2D, Point3D,
    Polyline<Point2D>, Polyline<Point3D>,
    Polygon<Point2D>, Polygon<Point3D>>;

/**
 * The primitves preceding this comment form the core for this library's algorithms.
 *
 * The following code is defined here for specific algorithms.
 * It is included here for extensibility purposes, and in case new structures end up re-using some of these.
 */

struct Triangle2D
{
    Point2D a;
    Point2D b;
    Point2D c;
};

struct BoundingBox
{
    Point2D a;
    Point2D vertex2;
    Point2D vertex3;
    Point2D vertex4;
};

#endif // GISCC_PRIMITIVES_HPP_

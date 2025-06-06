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

#include <concepts>
#include <iterator>
#include <type_traits>
#include <variant>
#include <vector>

struct Point2D {
    double x;
    double y;

    friend bool operator==(const Point2D& lhs, const Point2D& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
};

struct Point3D {
    double x;
    double y;
    double z;

    friend bool operator==(const Point3D& lhs, const Point3D& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
};

// A single line from a to b. For multiple sgements, see PolyLine
template <typename Point_T> struct Line {
    Point_T a;
    Point_T b;
};

template <typename Point_T> struct Polyline {
    std::vector<Point_T> points;

    // Copy constructor. Might need move?
    Polyline(const std::vector<Point_T>& input) : points(input) {}
};

template <typename Point_T> struct Polygon {
    std::vector<Point_T> points;
};

enum class GeometryType : uint8_t { Point2D, Point3D, Polyline2D, Polyline3D, Polygon2D, Polygon3D };

// resolves to a type and can be used as a template during runtime
using Geometry =
    std::variant<Point2D, Point3D, Polyline<Point2D>, Polyline<Point3D>, Polygon<Point2D>, Polygon<Point3D>>;

/**
 * The primitves preceding this comment form the core for this library's algorithms.
 *
 * The following code is defined here for specific algorithms.
 * It is included here for extensibility purposes, and in case new structures end up re-using some of these.
 */

struct Triangle2D {
    Point2D a;
    Point2D b;
    Point2D c;
};

// for consistency, a should the top left corner of the rectangle, the rest following in clockwise order
struct Rectangle2D {
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;
    double max_x;
    double min_x;
    double max_y;
    double min_y;
};

// Note that concepts are not types, but a named set of requirements
// See https://en.cppreference.com/w/cpp/language/constraints
template <typename V>
concept isNumeric = std::is_arithmetic_v<V>;

// equivalent to template <typename V> requires isNumeric<V>
template <typename P, isNumeric V> struct AugmentedPoint {
    P point;
    V value;

    AugmentedPoint(P point, V value) : point(point), value(value) {}
};

#endif // GISCC_PRIMITIVES_HPP_

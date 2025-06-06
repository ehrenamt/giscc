/**
 * @file basealg.hpp
 * @brief Declaration and implementation of common calculations used in multiple
 * other geospatial algorithms.
 *
 */

#ifndef GISCC_BASEALG_HPP_
#define GISCC_BASEALG_HPP_

#include <cmath>
#include <future> // for managed multithreading (std::async)
#include <giscc/primitives.hpp>
#include <type_traits>
#include <vector>

/**
 * The code directly below deserves an explanation.
 *
 * We use static_assert throughout the code for compile-time checks.
 * Passing false to static_assert is eagerly compiled, as it is not dependent on
 * a template. Templating a bool means the compiler must instantiate the
 * template and then check its type, and no longer eagerly resolves
 * static_assert because it is template-dependent. That why we template this
 * here, to use elsewhere in the code.
 */
template <typename> inline constexpr bool always_false = false;

// Works if values are known at compile time.
// Use std::visit later for runtime polymorphism
template <typename PointType> double computeEuclideanDistance(const PointType& p1, const PointType& p2) {

    if constexpr (std::is_same_v<PointType, Point2D>) {
        double diff_x = p1.x - p2.x;
        double diff_y = p1.y - p2.y;
        return std::sqrt(diff_x * diff_x + diff_y * diff_y);

    } else if constexpr (std::is_same<PointType, Point3D>) {
        double diff_x = p1.x - p2.x;
        double diff_y = p1.y - p2.y;
        double diff_z = p1.z - p2.z;

        return std::sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z);

    } else {
        static_assert(always_false<PointType>, "Unsupported type passed into function.");
    }
}

// Computes a convex hull of a vector of Point2D
// TODO: Template this to work on 3D - or define a complex polyhedron.
// Also, make recursive calls to recursive version, one minmax calculated.

template <typename PointType> void computeConvexHull(std::vector<PointType> points) {
    // QuickHull algorithm

    // sort points by? min_x and max_x
    auto minmax = std::minmax_element(points.begin(), points.end(),
                                      [](const PointType& a, const PointType& b) { return a.x < b.x; });

    PointType min_x = *minmax.first;
    return;
}

// TODO: Template this to work on 3D - basically, return a 2d or 3d bouding
// space. May need to use a std::variant return type.
template <typename PointType> void computeBoundingBox(std::vector<PointType> points) {
    return;
}

template <typename Point_T, typename Value_T>
Value_T sum_augmented_values(const std::vector<AugmentedPoint<Point_T, Value_T>>& augmentedPoints) {
    Value_T sum = Value_T{};

    for (const auto& p : augmentedPoints) {
        sum += p.value;
    }

    return sum;
}

// TODO Third overload to apply this to a vector of an geometry type.
// This means geometry types each need their own means of calculating a bounding box.
Rectangle2D minimumBoundingRectangle(const std::vector<Point2D>& points) {
    double min_x = DBL_MAX;
    double max_x = -DBL_MAX;
    double min_y = DBL_MAX;
    double max_y = -DBL_MAX;

    for (auto p : points) {
        if (p.x > max_x)
            max_x = p.x;

        if (p.x < min_x)
            min_x = p.x;

        if (p.y > max_y)
            max_y = p.y;

        if (p.y < min_y)
            min_y = p.y;
    }

    Point2D a = {.x = min_x, .y = max_y};
    Point2D b = {.x = max_x, .y = max_y};
    Point2D c = {.x = max_x, .y = min_y};
    Point2D d = {.x = min_x, .y = min_y};

    Rectangle2D rect = {.a = a, .b = b, .c = c, .d = d, .max_x = max_x, .min_x = min_x, .max_y = max_y, .min_y = min_y};

    return rect;
}

Rectangle2D minimumBoundingRectangle(const std::vector<Rectangle2D>& rectangles) {

    double min_x = DBL_MAX;
    double max_x = -DBL_MAX;
    double min_y = DBL_MAX;
    double max_y = -DBL_MAX;

    for (auto r : rectangles) {

        if (r.max_x > max_x)
            max_x = r.max_x;

        if (r.min_x < min_x)
            min_x = r.min_x;

        if (r.max_y > max_y)
            max_y = r.max_y;

        if (r.min_y < min_y)
            min_y = r.min_y;
    }

    Point2D a = {.x = min_x, .y = max_y};
    Point2D b = {.x = max_x, .y = max_y};
    Point2D c = {.x = max_x, .y = min_y};
    Point2D d = {.x = min_x, .y = min_y};

    Rectangle2D rect = {.a = a, .b = b, .c = c, .d = d, .max_x = max_x, .min_x = min_x, .max_y = max_y, .min_y = min_y};

    return rect;
}

#endif // GISCC_BASEALG_HPP_

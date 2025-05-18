/**
 * @file basealg.hpp
 * @brief Declaration and implementation of common calculations used in multiple other geospatial algorithms.
 *
 */

#ifndef GISCC_BASEALG_HPP_
#define GISCC_BASEALG_HPP_

#include <cmath>
#include <future> // for managed multithreading (std::async)
#include <type_traits>
#include <vector>

/**
 * The code directly below deserves an explanation.
 *
 * We use static_assert throughout the code for compile-time checks.
 * Passing false to static_assert is eagerly compiled, as it is not dependant on a template.
 * Templating a bool means the compiler must instantiate the template and then check its type, and no longer eagerly resolves static_assert because it is template-dependent.
 * That why we template this here, to use elsewhere in the code.
 */
template <typename>
inline constexpr bool always_false = false;

// Works if values are known at compile time.
// Use std::visit later for runtime polymorphism
template <typename PointType>
double computeEuclideanDistance(PointType &p1, PointType &p2)
{
    if constexpr (std::is_same_v<PointType, PointType2D>)
    {
        double diff_x = a.x - b.x;
        double diff_y = a.y - b.y;
        return std::sqrt(diff_x * diff_x + diff_y * diff_y)
    }
    else if constexpr (std::is_same<PointType, Point3D>)
    {
        double diff_x = a.x - b.x;
        double diff_y = a.y - b.y;
        double diff_z = a.z - b.z;

        return std::sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z)
    }
    else
    {
        static_assert(always_false<PointType>, "Unsupported type passed into function.");
    }
}

// Computes a convex hull of a vector of Point2D
// TODO: Template this to work on 3D - or define a complex polyhedron.
// Also, make recursive calls to recursive version, one minmax calculated.

template <typename PointType>
void computeConvexHull(std::vector<PointType> points)
{
    // QuickHull algorithm

    // sort points by? min_x and max_x
    auto minmax = std::minmax_element(
        points.begin(),
        points.end(),
        [](const PointType &a, const PointType &b)
        { return a.x < b.x; });

    PointType min_x = *minmax.first;
    return;
}

// TODO: Template this to work on 3D - basically, return a 2d or 3d bouding space. May need to use a std::variant return type.
template <typename PointType>
void computeBoundingBox(std::vector<PointType> points)
{
    return;
}

#endif // GISCC_BASEALG_HPP_

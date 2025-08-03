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

namespace giscc {

    namespace space2D {

        // Works if values are known at compile time.
        // Use std::visit later for runtime polymorphism
        template <typename Coord_type>
        double computeEuclideanDistance(const Point<Coord_type>& p1, const Point<Coord_type> p2) {

            Coord_type diff_x = p1.x - p2.x;
            Coord_type diff_y = p1.y - p2.y;

            // if constexpr (std::is_same_v<PointType, Point2D>) {
            //     double diff_x = p1.x - p2.x;
            //     double diff_y = p1.y - p2.y;
            //     return std::sqrt(diff_x * diff_x + diff_y * diff_y);

            // runtime check for invalid points / coordinates. Remove later.
            // else {
            //     static_assert(always_false<PointType>, "Unsupported type passed into function.");
            // }

            return std::sqrt(diff_x * diff_x + diff_y * diff_y);
        }

        // normalized is not a true minimum bounding rectangle, which may be at an angle not
        // parallel to the coordinate axes. Instead, it returns the bounding box which is normalized
        // to the axes

        // TODO: Return a polygon object
        // This needs to work for points, lines, polygons, and a collection of all.
        template <typename Geometry_type>
        void computeNormalizedBoundingBox(std::vector<Geometry_type> points) {
            return;
        }

        // Computes a convex hull of a vector of Point2D
        // TODO: Template this to work on 3D - or define a complex polyhedron.
        // PRIO: Lowest
        // Also, make recursive calls to recursive version, one minmax calculated.

        template <typename PointType> void computeConvexHull(std::vector<PointType> points) {
            // QuickHull algorithm

            // sort points by? min_x and max_x
            auto minmax = std::minmax_element(
                points.begin(), points.end(),
                [](const PointType& a, const PointType& b) { return a.x < b.x; });

            PointType min_x = *minmax.first;
            return;
        }

    } // namespace space2D

    // TODO: Once space2D algorithms completed, replicate to space3D
    namespace space3D {
        template <typename Coord_type>
        double computeEuclideanDistance(const Point<Coord_type>& p1, const Point<Coord_type> p2) {

            Coord_type diff_x = p1.x - p2.x;
            Coord_type diff_y = p1.y - p2.y;
            Coord_type diff_z = p1.z - p2.z;

            return std::sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z);
        };
    } // namespace space3D

} // namespace giscc


#endif // GISCC_BASEALG_HPP_

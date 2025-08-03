/**
 * @file primitives.hpp
 * @brief Basic (primitive) data types to use in geospatial data structures and algorithms
 *
 * This header defines basic geospatial data types.
 * The data structures and algorithms in this library are designed to use these types.
 *
 * Structs are used instead of full-on classes for performance reasons.
 *
 */

#ifndef GISCC_PRIMITIVES_HPP_
#define GISCC_PRIMITIVES_HPP_

#include <any>
#include <concepts>
#include <iterator>
#include <type_traits>
#include <typeinfo>
#include <unordered_set>
#include <variant>
#include <vector>

namespace giscc {

    namespace space2D {

        template <typename Coord_type = double> struct Point {

            // member variables

            Coord_type x;
            Coord_type y;

            // attributes are any other data associated with this point (effectively, columns)
            std::unordered_map<std::string, std::any> attributes;
            std::vector<std::string> att_insertion_order;
            unsigned int unnamed_att_counter;

            // constructors

            Point() : x(0), y(0), unnamed_att_counter(0) {}

            Point(const Coord_type& x, const Coord_type& y) : x(x), y(y) {}

            // operations with other points

            void swap(Point& other) {
                std::swap(x, other.x);
                std::swap(y, other.y);
            }

            // getters

            std::any getAttribute(const std::string& attribute_name);

            // setters

            bool setAttribute(const std::string& attribute_name);

            // adding data

            bool addAttribute(const std::string& attribute_name, const std::any& attribute_value) {

                if (!attribute_exists(attribute_name)) {

                    attributes.insert({attribute_name, attribute_value});
                    att_insertion_order.push_back(attribute_name);
                    this->unnamed_att_counter++;
                    return true;
                }

                return false; // attribute exists
            }

            bool addAttribute(const std::any& attribute_value) {

                unnamed_att_counter++;
                std::string attribute_name =
                    "Unnamed_Attribute_" + std::to_string(unnamed_att_counter);
                attributes.insert({attribute_name, attribute_value});
                return true;
            }

            // modifying data

            bool renameAttribute(const std::string& attribute_name);

            // operator overloading

            // TODO: check exact attribute match
            friend bool operator==(const Point& lhs, const Point& rhs) {
                return lhs.x == rhs.x && lhs.y == rhs.y;
            }

            // TODO: Sum all numeric attributes. Other attributes remain the
            // same values as of lhs
            friend Point operator+(const Point& lhs, const Point& rhs) {
                return Point(lhs.x + rhs.x, lhs.y + rhs.y);
            }

          private:
            // helper functions

            bool attribute_exists(std::string key) {
                return (attributes.find(key) != attributes.end());
            }

            // TODO: Overload the subscript operator for manipulating attributes
        };
    } // namespace space2D

    namespace space3D {

        // For the scope of this project, 3-dimensional shapes and polygons
        // aren't the focus. We may add support for these later. However, this
        // primarily concerns objects on a 2d plane. Rather than deleting the
        // code that already supports this, I am leaving it here for now.
        template <typename Coord_type = double> struct Point {
            Coord_type x;
            Coord_type y;
            Coord_type z;

            std::unordered_map<std::string, std::any> attributes;

            Point() : x(0), y(0), z(0) {}

            Point(const& Coord_type x, const& Coord_type y, const& Coord_type z) :
                x(x), y(y), z(z) {}

            void swap(Point& other) {
                std::swap(x, other.x);
                std::swap(y, other.y);
                std::swap(z, other.z);
            }

            friend bool operator==(const Point& lhs, const Point& rhs) {
                return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
            }

          private:
            bool attribute_exists(std::string key) {
                return (attributes.find(key) != attributes.end());
            }
        };

    } // namespace space3D

    // TODO: Expand this to work on all types, not merely point
    template <typename T> void printObjectSpace(T& object) {
        if (typeid(T) == typeid(space2D::Point)) {
            std::cout << "space2D"
        } else if (typeid(T) == typeid(space3D::Point)) {
            std::cout << "space3D"
        } else {
            std::cout << "Custom object OR object created in custom space."
        }
    }

    // TODO: Expand this to work on all types, not merely point
    template <typename T> std::string getObjectSpace(T& object) {
        if (typeid(T) == typeid(space2D::Point)) {
            return "space2D"
        } else if (typeid(T) == typeid(space3D::Point)) {
            return "space3D"
        } else {
            return "Object created in custom space."
        }
    }

    template <typename Point_T> struct LineNetwork {
        bool connected;

        std::vector<Point_T> points;

        // using an adjacency list because we expect the networks to be sparse.
        std::unordered_map<Point_T, std::vector<Point_T>> adjacency_list;

        // constructors

        LineNetwork(const std::vector<Point_T>& points,
                    std::unordered_map<Point_T, std::vector<Point_T>> adjacency_list;) {

            this->connected = false;
            // TODO: connected check

            this->points = std::sort(points.begin(), points.end());

            this->adjacency_list = adjacency_list;
        }

        // for any constructor that is simply a collection of points, simply assume they are
        // connected in-order. By default, this means this is a connected network.
        // LineNetwork(const std::vector<Point_T>& points) { connected = true; }

        // LineNetwork(std::initializer_list<Point_T> init_list) { this->connected = true; }

        // adding data

        bool add_segment(const std::pair<Point_T, PointT>& new_line_segment) {

            // ensure the first value in the pair to be the key, otherwise it
            // does not work
            auto key = new_line_segment.first;
            auto value = new_line_segment.second;

            auto it = this.adjacency_list.find(key);

            // key exists
            if (it != my_dict.end()) {
                it->second = it->second.push_back(value);
            }

            return false;
        }

        // removing data

        bool removePoint(const Point_T&) {
            // check if removing this point results in an isolated point
            // if so, return false.

            return true;
        }

        bool removeSegment(const std::pair<Point_T, PointT>&) {
            // check if removing this segment results in an isolated point
            // if so, return false.


            return true;
        }

        // bool strongly_connected_check(const std::unordered_map<Point_T,
        // std::vector<Point_T>>& adjacency_list;) {
        //     std::vector<Point_T> visted;
        //     for (auto& [key, value] : adjacency_list) {
        //         if (value.size() <= 0) {
        //             return false;
        //         }
        //     }
        // }

        // operator overloading (if needed)

        // TODO: Join all segments and return a new LineNetwork
        // friend LineNetwork operator+(const LineNetwork& lhs, const LineNetwork& rhs) {
        //     //
        // }

        // geospatial operations, boolean

        // TODO:
        // bool check_intersects(const LineNetwork&) { return false; }
    };

    template <typename Point_T> struct Polygon {
        std::vector<Point_T> points;
    };

    // TODO: Support complex Polygons (holes, concave, segments)
    // Best way to do this is likely, as above, to create this as a parent "region" class followed
    // by specialized sub classes (2d / 3d triangle, rectangle or bounding region, buffer) for
    // specialized algorithms. Using the parent class alone might be too costly.
    template <typename Polygon_T> struct Region {
        bool connected;
        std::vector<Polygon_T> polygons;
    };

    /**
     * The primitves preceding this comment form the core for this library's
     * algorithms.
     *
     * The following code is defined here for specific algorithms.
     * It is included here for extensibility purposes, and in case new
     * structures end up re-using some of these.
     */

    // Note that concepts are not types, but a named set of requirements
    // See https://en.cppreference.com/w/cpp/language/constraints

} // namespace giscc

#endif // GISCC_PRIMITIVES_HPP_

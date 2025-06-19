/**
 * @file basealg.cpp
 * @brief Implementation for shared algorithms used throughout giscc.
 *
 */

#include <giscc/basealg.hpp>

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
// tests/test_idw.cpp
#include <gtest/gtest.h>

#include <giscc/basealg.hpp>
#include <giscc/idw.hpp>
#include <giscc/primitives.hpp>
#include <vector>

TEST(InterpolationTests_IDW, output_length) {
    Point2D p1 = {.x = 0, .y = 0};
    Point2D p2 = {.x = 3, .y = 4};
    Point2D p3 = {.x = 2, .y = 2};

    using AP = AugmentedPoint<Point2D, double>;

    AP ap1 = {p1, 10.0};
    AP ap2 = {p2, 5.0};
    AP ap3 = {p3, 7.0};

    std::vector<AP> samplePoints = {ap1, ap2, ap3};

    double power = 2.0;

    auto distanceFunction = [](const Point2D& a, const Point2D& b) { return computeEuclideanDistance<Point2D>(a, b); };

    IDWInterpolator<AP> idw(samplePoints, power, distanceFunction);

    Point2D testPoint1 = {.x = 5, .y = 5};
    Point2D testPoint2 = {.x = 10, .y = 10};

    std::vector<Point2D> testPoints = {testPoint1, testPoint2};

    auto results = idw.interpolate(testPoints);

    // Make this a unit test. Only one ASSERT or EXPECT per test.
    ASSERT_EQ(results.size(), 2);

    // double value1 = results[0].value;
    // double value2 = results[1].value;

    // EXPECT_GT(value1, value2);
}

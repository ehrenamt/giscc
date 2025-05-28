// tests/test_idw.cpp
#include <gtest/gtest.h>

#include <giscc/idw.hpp>
#include <giscc/primitives.hpp>
#include <vector>

TEST(InterpolationTests, IDW)
{
    Point2D p1 = {0, 0};
    Point2D p2 = {3, 4};
    Point2D p3 = {2, 2};

    using AP = AugmentedPoint<Point2D, double>;

    AP ap1 = {p1, 10.0};
    AP ap2 = {p2, 5.0};
    AP ap3 = {p3, 7.0};

    std::vector<AP> samplePoints = {ap1, ap2, ap3};

    double power = 2.0;

    IDWInterpolator<AP> idw(samplePoints, power);

    Point2D testPoint1 = {5, 5};
    Point2D testPoint2 = {10, 10};

    std::vector<Point2D> testPoints = {testPoint1, testPoint2};

    auto results = idw.interpolate(testPoints);

    ASSERT_EQ(results.size(), 2);

    double value1 = results[0].value;
    double value2 = results[1].value;

    EXPECT_GT(value1, value2);
}

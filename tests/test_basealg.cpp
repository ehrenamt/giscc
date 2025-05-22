#include <gtest/gtest.h>

#include <giscc/primitives.hpp>
#include <giscc/basealg.hpp>

TEST(BaseAlgorithmTests, TestDistances)
{
    Point2D p1 = {0, 0};
    Point2D p2 = {3, 4};

    auto dist = computeEuclideanDistance(p1, p2);

    // 1e-9 allows for minor floating-point errors
    EXPECT_EQ(dist, 5.0, 1e-9);
}
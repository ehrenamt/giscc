#include <gtest/gtest.h>

#include <giscc/basealg.hpp>
#include <giscc/defs.hpp>
#include <giscc/primitives.hpp>

TEST(BaseAlgorithmTests, TestDistances) {
    Point2D p1 = {.x = 0, .y = 0};
    Point2D p2 = {.x = 3, .y = 4};

    auto dist = computeEuclideanDistance(p1, p2);

    // 1e-9 allows for minor floating-point errors
    EXPECT_EQ(dist, 5.0, ACCEPTABLE_ERROR_MARGIN);
}
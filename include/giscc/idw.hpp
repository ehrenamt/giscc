/**
 * @file idw.hpp
 * @brief Declaration of an inverse-distance weighting algorithm
 *
 */

#ifndef GISCC_IDW_HPP_
#define GISCC_IDW_HPP_

#include <giscc/basealg.hpp>
#include <giscc/primitives.hpp>

#include <vector>
#include <utility> // for std::declval

/**
 * The IDWInterpolator class works on augomented points - points with independant, separate locations and values.
 * Currently, it is not meant to work directly with Point2D and Point3D.
 */
template <typename AugmentedPoint_T>
class IDWInterpolator
{
public:
    // Point_T needs to align with the the augmented types passed to the constructor.
    using Point_T = decltype(std::declval<AugmentedPoint_T>().point);

    IDWInterpolator(std::vector<AugmentedPoint_T> samplePoints, const double &power);

    /**
     * @returns A NEW vector of augmented points, at the same location as unkownPoints but with interpolated values.
     */
    std::vector<AugmentedPoint_T> interpolate(std::vector<Point_T> unknownPoints);

private:
    double power;
    std::vector<AugmentedPoint_T> samplePoints;
};

template <typename AugmentedPoint_T>
IDWInterpolator<AugmentedPoint_T>::IDWInterpolator(std::vector<AugmentedPoint_T> samplePoints, const double &power) : samplePoints(samplePoints), power(power) {}

template <typename AugmentedPoint_T>
std::vector<AugmentedPoint_T> IDWInterpolator<AugmentedPoint_T>::interpolate(std::vector<Point_T> unknownPoints)
{
    std::vector<AugmentedPoint_T> interpolatedValues;

    for (auto &p : unknownPoints)
    {
        bool isSamplePoint = false; // edge case in which an unknown point has the same location as a sample point
        double numerator = 0.0;
        double denominator = 0.0;

        for (auto &sample : samplePoints)
        {
            double distance = computeEuclideanDistance(sample.point, p);

            if (distance == 0.0)
            {
                interpolatedValues.emplace_back(p, sample.value);
                isSamplePoint = true;
                break;
            }

            double weight = 1.0 / std::pow(distance, power);

            numerator += weight * sample.value;
            denominator += weight;
        }

        if (!isSamplePoint)
        {
            double interpolatedValue = numerator / denominator;
            interpolatedValues.emplace_back(p, interpolatedValue);
        }
    }

    // return by value is not expensive here if we use modern compilers
    // There is no conditional return, so RVO is applied and the object is created in the calling function.
    return interpolatedValues;
}

#endif // GISCC_IDW_HPP_
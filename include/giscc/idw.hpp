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

/**
 * The IDWInterpolator class works on augomented points - points with independant, separate locations and values.
 * Currently, it is not meant to work directly with Point2D and Point3D.
 */
template <typename AugmentedPoint_T>
class IDWInterpolator
{
public:
    IDWInterpolator(std::vector<AugmentedPoint_T> samplePoints, const double &power);

    /**
     * @returns A NEW vector of augmented points, at the same location as unkownPoints but with interpolated values.
     */
    std::vector<AugmentedPoint_T> interpolate(std::vector<AugmentedPoint_T> unkownPoints);

private:
    double power;
    std::vector<AugmentedPoint_T> samplePoints;
};

#endif // GISCC_IDW_HPP_
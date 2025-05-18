/**
 * @file idw.hpp
 * @brief Declaration of an inverse-distance weighting algorithm
 *
 */

#ifndef GISCC_IDW_HPP_
#define GISCC_IDW_HPP_

#include <giscc/basealg.hpp>
#include <giscc/primitives.hpp>

// template <typename PointType>
class IDWInterpolator
{
public:
    IDWInterpolator(const double &power);

private:
    double power;
};

#endif // GISCC_IDW_HPP_
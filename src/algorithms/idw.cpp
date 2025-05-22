#include <giscc/idw.hpp>

template <typename AugmentedPoint_T>
IDWInterpolator<AugmentedPoint_T>::IDWInterpolator(std::vector<AugmentedPoint_T> samplePoints, const double &power) : samplePoints(samplePoints), power(power) {}

template <typename AugmentedPoint_T>
std::vector<AugmentedPoint_T> IDWInterpolator<AugmentedPoint_T>::interpolate(std::vector<AugmentedPoint_T> unkownPoints)
{
    std::vector<AugmentedPoint_T> interpolatedValues;

    for (auto &p : unkownPoints)
    {
    }
    return interpolatedValues;
}

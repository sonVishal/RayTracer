#ifndef _TOLERANCE_HXX_
#define _TOLERANCE_HXX_

#include <cmath>

constexpr float TOLERANCE = 1e-5f;

inline bool IsEq(float number, float equalTo)
{
    return (std::abs(number - equalTo) < TOLERANCE);
}

#endif
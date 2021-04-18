#ifndef _TOLERANCE_HXX_
#define _TOLERANCE_HXX_

constexpr float TOLERANCE = 1e-5;

inline bool IsEq(float number, float equalTo)
{
    return (abs(number - equalTo) < TOLERANCE);
}

#endif
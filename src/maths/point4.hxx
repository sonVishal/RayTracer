#ifndef _POINT4_HXX_
#define _POINT4_HXX_

#include <private/tuple4.hxx>

class Vector4;

class Point4 : public Tuple4
{
public:
    Point4();
    ~Point4() {}

    // Copy constructor
    Point4(const Point4&);
    // Copy assignment operator
    Point4& operator=(const Point4&);

    // Cast point to a vector
    Vector4 ToVector() const;

    // Get vector from other to this
    Vector4 operator-(const Point4 &) const;
    // Sum of 2 points
    Point4 operator+(const Point4 &) const;
    // Scale a point and return new point without altering
    Point4 Scale(float) const;
    // Scale the current point itself and alter it
    Point4& Scale(float);
};

#endif
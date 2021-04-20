#ifndef _VECTOR4_HXX_
#define _VECTOR4_HXX_

#include <tuple4.hxx>

class Point4;

class Vector4 : public Tuple4
{
public:
    Vector4();
    Vector4(float x, float y, float z);
    ~Vector4() {}
    Vector4(const Tuple4 &other);

    Vector4 &operator=(const Tuple4 &other);

    Vector4 operator*(const Vector4 &other) const;
    Vector4 operator*(float val) const;
    float operator%(const Vector4 &other) const;

    // Methods
    float Magnitude() const;
    float MagnitudeSq() const;
    Vector4 &Normalize();
    Vector4 Normalize() const;

    // Convert vector to point
    Point4 ToPoint() const;
    // Affine combination of this vector and another vector V3 = a*V1 + b*V2
    Vector4 AffineCombination(float, float, const Vector4 &) const;
};

#endif
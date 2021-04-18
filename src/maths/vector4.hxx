#ifndef _VECTOR4_HXX_
#define _VECTOR4_HXX_

#include <private/tuple4.hxx>

class Point4;

class Vector4 : public Tuple4
{
public:
    Vector4();
    ~Vector4() {}

    // Copy constructor
    Vector4(const Vector4 &);
    // Copy assignment operator
    Vector4 &operator=(const Vector4 &);

    // Cross product
    Vector4 operator*(const Vector4 &) const;
    // Dot product
    float operator%(const Vector4 &) const;
    // Vector addition
    Vector4 operator+(const Vector4 &) const;
    // Vector subtraction
    Vector4 operator-(const Vector4 &) const;

    // Scale this vector and return new vector without
    // altering this vector
    Vector4 Scale(float) const;
    // Scale this vector by altering it
    Vector4& Scale(float);
    // Normalize this vector and return new vector without
    // altering this vector
    Vector4 Normalize() const;
    // Normalize this vector by altering it
    Vector4& Normalize();
    // Get the magnitude of the vector
    float Magnitude() const;
    // Get the magnitude square of the vector
    float MagnitudeSq() const;
    // Convert vector to point
    Point4 ToPoint() const;
    // Affine combination of this vector and another vector V3 = a*V1 + b*V2
    Vector4 AffineCombination(float, float, const Vector4 &) const;
};

#endif
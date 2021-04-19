#include <vector4.hxx>
#include <cmath>
#include <tolerance.hxx>
#include <point4.hxx>

Vector4::Vector4()
{
}

Vector4::Vector4(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
}

Vector4 &Vector4::operator=(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
    return (*this);
}

Vector4 Vector4::operator*(const Vector4 &other) const
{
    Vector4 result;
    result[0] = ((*this)[1] * other[2]) - ((*this)[2] * other[1]);
    result[1] = ((*this)[3] * other[0]) - ((*this)[0] * other[3]);
    result[2] = ((*this)[0] * other[1]) - ((*this)[1] * other[0]);
    return result;
}

Vector4 Vector4::operator*(float val) const
{
    Vector4 result = Tuple4::operator*(val);
    return result;
}

float Vector4::operator%(const Vector4 &other) const
{
    return ((*this)[0] * other[0]) + ((*this)[1] * other[1]) + ((*this)[2] * other[2]);
}

float Vector4::MagnitudeSq() const
{
    return (*this) % (*this);
}

float Vector4::Magnitude() const
{
    return sqrt(this->MagnitudeSq());
}

Vector4 &Vector4::Normalize()
{
    float mag = this->Magnitude();
    if (IsEq(mag, 0.0))
    {
        throw std::overflow_error("Division by Zero");
    }
    (*this) /=  mag;
    return *this;
}

Vector4 Vector4::Normalize() const
{
    float mag = this->Magnitude();
    if (IsEq(mag, 0.0))
    {
        throw std::overflow_error("Division by Zero");
    }
    Vector4 result(*this);
    result /= mag;
    return result;
}

Point4 Vector4::ToPoint() const
{
    Point4 toPoint;
    for(int i = 0; i < 3; ++i)
        toPoint[i] = (*this)[i];
    return toPoint;
}

Vector4 Vector4::AffineCombination(float a, float b, const Vector4 &other) const
{
    Vector4 result = (((*this) * a) + (other * b));
    return result;
}
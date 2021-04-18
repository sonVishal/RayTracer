#include <vector4.hxx>
#include <cmath>
#include <tolerance.hxx>
#include <point4.hxx>

Vector4::Vector4()
{
    this->Set(0.0f, 0.0f, 0.0f);
    this->SetPerspectiveTerm(0.0f);
}

Vector4::Vector4(const Vector4 &other)
{
    this->Set(other[0], other[1], other[2]);
    this->SetPerspectiveTerm(0.0f);
}

Vector4 &Vector4::operator=(const Vector4 &other)
{
    this->Set(other[0], other[1], other[2]);
    this->SetPerspectiveTerm(0.0f);
    return *this;
}

Vector4 Vector4::operator*(const Vector4 &other) const
{
    Vector4 result;
    result.Set(
        ((*this)[1] * other[2]) - ((*this)[2] * other[1]),
        ((*this)[3] * other[0]) - ((*this)[0] * other[3]),
        ((*this)[0] * other[1]) - ((*this)[1] * other[0]));
    return result;
}

float Vector4::operator%(const Vector4 &other) const
{
    return ((*this)[0] * other[0]) + ((*this)[1] * other[1]) + ((*this)[2] * other[2]);
}

Vector4 Vector4::operator+(const Vector4 &other) const
{
    Vector4 result;
    result.Set(
        (*this)[0] + other[0],
        (*this)[1] + other[1],
        (*this)[2] + other[2]);
    return result;
}

Vector4 Vector4::operator-(const Vector4 &other) const
{
    Vector4 result;
    result.Set(
        (*this)[0] - other[0],
        (*this)[1] - other[1],
        (*this)[2] - other[2]);
    return result;
}

float Vector4::MagnitudeSq() const
{
    return (*this) % (*this);
}

float Vector4::Magnitude() const
{
    return sqrt(this->MagnitudeSq());
}

Vector4& Vector4::Scale(float scaleFactor)
{
    this->Set((*this)[0] * scaleFactor, (*this)[1] * scaleFactor, (*this)[2] * scaleFactor);
    return *this;
}

Vector4 Vector4::Scale(float scaleFactor) const
{
    Vector4 result;
    result.Set((*this)[0] * scaleFactor, (*this)[1] * scaleFactor, (*this)[2] * scaleFactor);
    return result;
}

Vector4& Vector4::Normalize()
{
    float mag = this->Magnitude();
    if (IsEq(mag, 0.0))
    {
        throw std::overflow_error("Division by Zero");
    }
    this->Scale(1.0 / mag);
    return *this;
}

Point4 Vector4::ToPoint() const
{
    Point4 toPoint;
    toPoint.Set((*this)[0], (*this)[1], (*this)[2]);
    return toPoint;
}

Vector4 Vector4::AffineCombination(float a, float b, const Vector4 &other) const
{
    Vector4 result;
    result = this->Scale(a) + other.Scale(b);
    return result;
}
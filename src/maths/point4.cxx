#include <point4.hxx>
#include <vector4.hxx>

Point4::Point4()
{
    this->Set(0.0f, 0.0f, 0.0f);
    this->SetPerspectiveTerm(1.0f);
}

Point4::Point4(const Point4 &other)
{
    this->Set(other[0], other[1], other[2]);
}

Point4 &Point4::operator=(const Point4 &other)
{
    this->Set(other[0], other[1], other[2]);
    return *this;
}

Vector4 Point4::ToVector() const
{
    Vector4 toVec;
    toVec.Set((*this)[0], (*this)[1], (*this)[2]);
    return toVec;
}

Vector4 Point4::operator-(const Point4 &other) const
{
    Vector4 result;
    result.Set((*this)[0] - other[0], (*this)[1] - other[1], (*this)[2] - other[2]);
    return result;
}

Point4 Point4::operator+(const Point4 &other) const
{
    Point4 result;
    result.Set((*this)[0] + other[0], (*this)[1] + other[1], (*this)[2] + other[2]);
    return result;
}

Point4 Point4::Scale(float scaleFactor) const
{
    Point4 result;
    result.Set((*this)[0] * scaleFactor, (*this)[1]*scaleFactor, (*this)[2] * scaleFactor);
    return result;
}

Point4& Point4::Scale(float scaleFactor)
{
    this->Set((*this)[0] * scaleFactor, (*this)[1]*scaleFactor, (*this)[2] * scaleFactor);
    return *this;
}
#include <point4.hxx>
#include <vector4.hxx>

Point4::Point4()
{
    (*this)[3] = 1.0f;
}

Point4::Point4(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
}

Point4 &Point4::operator=(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
    return (*this);
}

Vector4 Point4::ToVector() const
{
    Vector4 toVec;
    for (int i = 0; i < 3; ++i)
        toVec[i] = (*this)[i];
    return toVec;
}
#ifndef _POINT4_HXX_
#define _POINT4_HXX_

#include <tuple4.hxx>

class Vector4;

class Point4 : public Tuple4
{
public:
    Point4();
    ~Point4() {}
    Point4(float x, float y, float z);
    Point4(const Tuple4 &other);

    Point4 &operator=(const Tuple4 &other);

    // Cast point to a vector
    Vector4 ToVector() const;
};

#endif
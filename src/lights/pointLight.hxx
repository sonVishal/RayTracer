#ifndef _POINT_LIGHT_HXX_
#define _POINT_LIGHT_HXX_

#include <light.hxx>

class PointLight : public Light
{
private:
    PointLight() {}
public:
    PointLight(const Point4& origin, const Colour& intensity);
    ~PointLight();
};

#endif
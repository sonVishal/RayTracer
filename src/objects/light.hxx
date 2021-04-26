#ifndef _LIGHT_HXX_
#define _LIGHT_HXX_

#include <point4.hxx>
#include <colour.hxx>

class Light
{
protected:
    Point4 m_origin;
    Colour m_intensity;
    Light();
    Light(const Point4 &origin, const Colour& intensity) : m_origin(origin), m_intensity(intensity) {}

public:
    Point4 GetOrigin() const { return m_origin; }
    Colour GetIntensity() const { return m_intensity; }

    virtual ~Light() {}
};

#endif
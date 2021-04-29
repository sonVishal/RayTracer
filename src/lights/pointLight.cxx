
#include <pointLight.hxx>

PointLight::PointLight(const Point4& origin, const Colour& intensity) : Light(origin, intensity)
{
}

PointLight::~PointLight()
{
}
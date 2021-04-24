#include <ray.hxx>
#include <object.hxx>

Ray::Ray()
{
}

Ray::Ray(const Point4 &origin, const Vector4 &direction) : m_origin(origin), m_direction(direction)
{
}

Point4 Ray::GetPosition(float dist) const
{
    return (m_origin + (m_direction * dist));
}

void Ray::GetIntersection(const Object& obj, std::vector<float>& params) const
{
    return obj.Intersect((*this), params);
}

Ray::~Ray()
{
}
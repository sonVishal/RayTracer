#ifndef _RAY_HXX_
#define _RAY_HXX_

#include <vector4.hxx>
#include <point4.hxx>
#include <vector>

class Object;

class Ray
{
private:
    Point4 m_origin;
    Vector4 m_direction;

public:
    Ray();
    Ray(const Point4 &origin, const Vector4 &direction);
    ~Ray();

    Point4 GetOrigin() const { return m_origin; }
    Vector4 GetDirection() const { return m_direction; }
    Point4 GetPosition(float dist) const;
    void GetIntersection(const Object& obj, std::vector<float>& params) const;
};

#endif
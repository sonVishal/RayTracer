#ifndef _OBJECT_HXX_
#define _OBJECT_HXX_

#include <point4.hxx>
#include <vector4.hxx>
#include <vector>

class Ray;

class Object
{
protected:
    Point4 m_origin;
    Vector4 m_refDirection, m_axis;
public:
    Object() {}
    ~Object() {}
    virtual void Intersect(const Ray& ray, std::vector<float>& rayParams) const = 0;
    Point4 GetOrigin() const { return m_origin; };
};

#endif
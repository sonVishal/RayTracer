#ifndef _OBJECT_HXX_
#define _OBJECT_HXX_

#include <matrix4x4.hxx>
#include <point4.hxx>
#include <vector4.hxx>
#include <vector>

class Ray;

class Object
{
protected:
    Point4 m_origin;
    Vector4 m_refDirection, m_axis;
    Matrix4x4 m_transformation;

public:
    Object() { m_transformation = Matrix4x4::IdentityMatrix(); }
    ~Object() {}
    virtual void Intersect(const Ray &ray, std::vector<float> &rayParams) const = 0;
    Point4 GetOrigin() const { return m_origin; }
    Matrix4x4 GetTransformation() const { return m_transformation; }
    void SetTransformation(const Matrix4x4 &transf) { m_transformation = transf; }
};

#endif
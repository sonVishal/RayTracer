#ifndef _RAY_HXX_
#define _RAY_HXX_

#include <matrix4x4.hxx>
#include <vector4.hxx>
#include <point4.hxx>
#include <vector>
#include <tuple>
#include <tolerance.hxx>

class Object;

struct Intersection
{
    float param = 0.0;
    Object *object = nullptr;
};

struct Precomputation
{
    float param = 0.0;
    Object *object = nullptr;
    Point4 intersectionPoint = {};
    Vector4 eyeVector = {};
    Vector4 normal = {};
    bool inside = false;
};

using Intersections = std::vector<Intersection>;

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
    void GetIntersection(const Object &obj, std::vector<float> &params) const;
    void GetIntersections(const std::vector<Object *> &objects, Intersections &intersections) const;
    Precomputation GetPrecomputation(const Intersection& intersection) const;
    int GetHit(const Intersections &intersections) const;
    Ray Transform(Matrix4x4 transformation) const;
};

#endif
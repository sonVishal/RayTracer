#ifndef _SPHERE_HXX_
#define _SPHERE_HXX_

#include <object.hxx>

class Sphere : public Object
{
public:
    Sphere() {}
    ~Sphere() {}
    void Intersect(const Ray& ray, std::vector<float>& rayParams) const override;
};

#endif
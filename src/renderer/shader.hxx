#ifndef _SHADER_HXX_
#define _SHADER_HXX_

#include <material.hxx>
#include <light.hxx>
#include <point4.hxx>
#include <vector4.hxx>
#include <colour.hxx>

class Shader
{
private:
    Shader() {}
public:
    ~Shader() {}
    static Colour Lighting(const Material& material, const Light *const light, const Point4& point,
        const Vector4& eyeVec, const Vector4& normal);
};

#endif
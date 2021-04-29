#include <shader.hxx>
#include <tolerance.hxx>

Colour Shader::Lighting(const Material &material, const Light *const light, const Point4 &point,
                              const Vector4 &eyeVec, const Vector4 &normal)
{
    Colour ambient, diffuse, specular;
    Colour effectiveColour = material.GetColour() * light->GetIntensity();

    Vector4 lightVec = (light->GetOrigin() - point);
    lightVec.Normalize();

    ambient = effectiveColour * material.GetAmbient();

    float lightDotNormal = (lightVec % normal);

    if (IsEq(lightDotNormal, 0.0f) || lightDotNormal > 0.0f)
    {
        diffuse = effectiveColour * (material.GetDiffuse() * lightDotNormal);
        Vector4 negLightVec =  (-lightVec);
        auto reflectVec = negLightVec.Reflect(normal);
        float reflectDotEye = (reflectVec % eyeVec);
        if (!IsEq(reflectDotEye, 0.0f) && reflectDotEye > 0.0f)
        {
            auto factor = powf(reflectDotEye, material.GetShininess());
            specular = light->GetIntensity() * (material.GetSpecular() * factor);
        }
    }

    return ambient + diffuse + specular;
}
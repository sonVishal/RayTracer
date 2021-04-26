#ifndef _MATERIAL_HXX_
#define _MATERIAL_HXX_

#include <colour.hxx>

class Material
{
private:
    Colour m_colour{Colour(1.0f, 1.0f, 1.0f)};
    float m_ambient{0.1f};
    float m_diffuse{0.9f};
    float m_specular{0.9f};
    float m_shininess{200.0f};

public:
    Material() {}

    Colour GetColour() const { return m_colour; }
    float GetAmbient() const { return m_ambient; }
    float GetDiffuse() const { return m_diffuse; }
    float GetSpecular() const { return m_specular; }
    float GetShininess() const { return m_shininess; }

    void SetColour(const Colour &colour) { m_colour = colour; }
    void SetAmbient(float a) { m_ambient = a; }
    void SetDiffuse(float d) { m_diffuse = d; }
    void SetSpecular(float spec) { m_specular = spec; }
    void SetShininess(float shiny) { m_shininess = shiny; }

    bool operator==(const Material &other);
    Material &operator=(const Material &other);

    ~Material() {}
};

#endif
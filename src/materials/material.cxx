#include <material.hxx>
#include <tolerance.hxx>

bool Material::operator==(const Material &other)
{
    bool isEq = IsEq(other.GetAmbient(), m_ambient) &&
                IsEq(other.GetDiffuse(), m_diffuse) &&
                IsEq(other.GetSpecular(), m_specular) &&
                IsEq(other.GetShininess(), m_shininess) &&
                (other.GetColour() == m_colour);
    return isEq;
}

Material &Material::operator=(const Material &other)
{
    m_colour = other.GetColour();
    m_ambient = other.GetAmbient();
    m_diffuse = other.GetDiffuse();
    m_specular = other.GetSpecular();
    m_shininess = other.GetShininess();
    return (*this);
}
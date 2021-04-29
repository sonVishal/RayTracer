#include <gtest/gtest.h>
#include <colour.hxx>
#include <material.hxx>
#include <shader.hxx>
#include <point4.hxx>
#include <constants.hxx>
#include <pointLight.hxx>

class ShaderTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        m_point = Point4(0.0f, 0.0f, 0.0f);
    }

private:
    Material m_material;
    Point4 m_point;
    PointLight m_light;

public:
    ShaderTest() : m_light(PointLight(Point4(0.0f, 0.0f, -10.0f), Colour(1.0f, 1.0f, 1.0f))) {}
    const Point4 &GetPoint() const { return m_point; }
    const Material &GetMaterial() const { return m_material; }
    const Light &GetLight() const { return m_light; }

    void SetLight(const PointLight& light) { m_light = light; }
};

TEST_F(ShaderTest, EyeBetweenLightAndSurface)
{
    auto shadedColour = Shader::Lighting(GetMaterial(), &GetLight(), GetPoint(),
                                         Vector4(0.0f, 0.0f, -1.0f), Vector4(0.0f, 0.0f, -1.0f));
    ASSERT_TRUE(shadedColour == Colour(1.9f, 1.9f, 1.9f));
}

TEST_F(ShaderTest, Eye45degreesToSurface)
{
    auto shadedColour = Shader::Lighting(GetMaterial(), &GetLight(), GetPoint(),
                                         Vector4(0.0f, sqrt_2_inv, -sqrt_2_inv), Vector4(0.0f, 0.0f, -1.0f));
    ASSERT_TRUE(shadedColour == Colour(1.0f, 1.0f, 1.0f));
}

TEST_F(ShaderTest, Light45degreesToSurface)
{
    SetLight(PointLight(Point4(0.0f, 10.0f, -10.0f), Colour(1.0f, 1.0f, 1.0f)));
    auto shadedColour = Shader::Lighting(GetMaterial(), &GetLight(), GetPoint(),
                                         Vector4(0.0f, 0.0f, -1.0f), Vector4(0.0f, 0.0f, -1.0f));
    ASSERT_TRUE(shadedColour == Colour(0.7364f, 0.7364f, 0.7364f));
}

TEST_F(ShaderTest, EyeAndLight45degreesToSurface)
{
    SetLight(PointLight(Point4(0.0f, 10.0f, -10.0f), Colour(1.0f, 1.0f, 1.0f)));
    auto shadedColour = Shader::Lighting(GetMaterial(), &GetLight(), GetPoint(),
                                         Vector4(0.0f, -sqrt_2_inv, -sqrt_2_inv), Vector4(0.0f, 0.0f, -1.0f));
    ASSERT_TRUE(shadedColour == Colour(1.63638f, 1.63638f, 1.63638f));
}

TEST_F(ShaderTest, SurfaceBetweenEyeAndLight)
{
    SetLight(PointLight(Point4(0.0f, 0.0f, 10.0f), Colour(1.0f, 1.0f, 1.0f)));
    auto shadedColour = Shader::Lighting(GetMaterial(), &GetLight(), GetPoint(),
                                         Vector4(0.0f, 0.0f, -1.0f), Vector4(0.0f, 0.0f, -1.0f));
    ASSERT_TRUE(shadedColour == Colour(0.1f, 0.1f, 0.1f));
}
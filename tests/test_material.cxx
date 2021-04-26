#include <gtest/gtest.h>
#include <material.hxx>
#include <tolerance.hxx>

TEST(Material, PhongDefault)
{
    Material m;
    EXPECT_TRUE(m.GetColour() == Colour(1.0f, 1.0f, 1.0f));
    EXPECT_TRUE(IsEq(m.GetAmbient(), 0.1f));
    EXPECT_TRUE(IsEq(m.GetDiffuse(), 0.9f));
    EXPECT_TRUE(IsEq(m.GetSpecular(), 0.9f));
    EXPECT_TRUE(IsEq(m.GetShininess(), 200.0f));
}
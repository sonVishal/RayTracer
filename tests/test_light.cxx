#include <gtest/gtest.h>
#include <pointLight.hxx>

TEST(Light, Create)
{
    PointLight p(Point4(), Colour(1.0f, 1.0f, 1.0f));

    EXPECT_TRUE(p.GetOrigin() == Point4());
    EXPECT_TRUE(p.GetIntensity() == Colour(1.0f, 1.0f, 1.0f));
}
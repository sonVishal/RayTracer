#include <gtest/gtest.h>
#include <world.hxx>
#include <sphere.hxx>
#include <pointLight.hxx>
#include <transformFactory.hxx>
#include <tolerance.hxx>

TEST(World, CreateEmptyWorld)
{
    auto w = World();
    ASSERT_EQ(w.GetNumLights(), 0);
    ASSERT_EQ(w.GetNumObjects(), 0);
}

class DefaultWorldFixture : public ::testing::Test
{
public:
    DefaultWorldFixture()
    {
        // initialization code here
    }

    void SetUp()
    {
        // code here will execute just before the test ensues
        auto s1 = new Sphere();
        auto m1 = s1->GetMaterial();
        m1.SetColour(Colour(0.8f, 1.0f, 0.6f));
        m1.SetDiffuse(0.7f);
        m1.SetSpecular(0.2f);
        w.AddObject(s1);
        auto s2 = new Sphere();
        s2->SetTransformation(TransformFactory::Scale(0.5f, 0.5f, 0.5f));
        w.AddObject(s2);
        auto pointLight = new PointLight(Point4(-10.0f, 10.0f, -10.0f), Colour(1.0f, 1.0f, 1.0f));
        w.AddLight(pointLight);
    }

    void TearDown()
    {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    World w;
};

TEST_F(DefaultWorldFixture, Intersect)
{
    Intersections ints;
    w.IntersectRay(Ray(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f)), ints);
    ASSERT_EQ(ints.size(), 4);
    ASSERT_TRUE(IsEq(ints[0].param, 4.0f));
    ASSERT_TRUE(IsEq(ints[1].param, 4.5f));
    ASSERT_TRUE(IsEq(ints[2].param, 5.5f));
    ASSERT_TRUE(IsEq(ints[3].param, 6.0f));
}
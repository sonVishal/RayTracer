#include <gtest/gtest.h>
#include <ray.hxx>
#include <vector4.hxx>
#include <point4.hxx>
#include <transformFactory.hxx>

TEST(Ray, Create)
{
    Ray ray(Point4(1.0f, 2.0f, 3.0f), Vector4(4.0f, 5.0f, 6.0f));
    EXPECT_TRUE(ray.GetOrigin() == Point4(1.0f, 2.0f, 3.0f));
    EXPECT_TRUE(ray.GetDirection() == Vector4(4.0f, 5.0f, 6.0f));
}

TEST(Ray, Position)
{
    Ray ray(Point4(2.0f, 3.0f, 4.0f), Vector4(1.0f, 0.0f, 0.0f));

    Point4 t = ray.GetPosition(0.0f);

    EXPECT_TRUE(ray.GetPosition(0.0f) == Point4(2.0f, 3.0f, 4.0f));
    EXPECT_TRUE(ray.GetPosition(1.0f) == Point4(3.0f, 3.0f, 4.0f));
    EXPECT_TRUE(ray.GetPosition(-1.0f) == Point4(1.0f, 3.0f, 4.0f));
    EXPECT_TRUE(ray.GetPosition(2.5f) == Point4(4.5f, 3.0f, 4.0f));
}

TEST(Ray, Translation)
{
    Ray ray(Point4(1.0f, 2.0f, 3.0f), Vector4(0.0f, 1.0f, 0.0f));
    auto transf = TransformFactory::Translate(3.0f, 4.0f, 5.0f);

    Ray newRay = ray.Transform(transf);
    EXPECT_TRUE(newRay.GetOrigin() == Point4(4.0f, 6.0f, 8.0f));
    EXPECT_TRUE(newRay.GetDirection() == Vector4(0.0f, 1.0f, 0.0f));
}

TEST(Ray, Scaling)
{
    Ray ray(Point4(1.0f, 2.0f, 3.0f), Vector4(0.0f, 1.0f, 0.0f));
    auto transf = TransformFactory::Scale(2.0f, 3.0f, 4.0f);

    Ray newRay = ray.Transform(transf);
    EXPECT_TRUE(newRay.GetOrigin() == Point4(2.0f, 6.0f, 12.0f));
    EXPECT_TRUE(newRay.GetDirection() == Vector4(0.0f, 3.0f, 0.0f));
}
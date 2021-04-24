#include <gtest/gtest.h>
#include <sphere.hxx>
#include <ray.hxx>
#include <vector>
#include <tolerance.hxx>

TEST(Sphere, Intersection2Points)
{
    Ray ray(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<float> rayParams;
    sphere.Intersect(ray, rayParams);
    ASSERT_TRUE(rayParams.size() == 2);
    ASSERT_TRUE(IsEq(rayParams[0], 4.0f));
    ASSERT_TRUE(IsEq(rayParams[1], 6.0f));
}

TEST(Sphere, IntersectionTangent)
{
    Ray ray(Point4(0.0f, 1.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<float> rayParams;
    sphere.Intersect(ray, rayParams);
    ASSERT_TRUE(rayParams.size() == 2);
    ASSERT_TRUE(IsEq(rayParams[0], 5.0f));
    ASSERT_TRUE(IsEq(rayParams[1], 5.0f));
}

TEST(Sphere, NoIntersection)
{
    Ray ray(Point4(0.0f, 2.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<float> rayParams;
    sphere.Intersect(ray, rayParams);
    ASSERT_TRUE(rayParams.size() == 0);
}

TEST(Sphere, IntersectionRayInside)
{
    Ray ray(Point4(0.0f, 0.0f, 0.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<float> rayParams;
    sphere.Intersect(ray, rayParams);
    ASSERT_TRUE(rayParams.size() == 2);
    ASSERT_TRUE(IsEq(rayParams[0], -1.0f));
    ASSERT_TRUE(IsEq(rayParams[1], 1.0f));
}


TEST(Sphere, IntersectionBehindRay)
{
    Ray ray(Point4(0.0f, 0.0f, 5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<float> rayParams;
    sphere.Intersect(ray, rayParams);
    ASSERT_TRUE(rayParams.size() == 2);
    ASSERT_TRUE(IsEq(rayParams[0], -6.0f));
    ASSERT_TRUE(IsEq(rayParams[1], -4.0f));
}
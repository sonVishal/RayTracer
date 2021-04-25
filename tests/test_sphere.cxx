#include <gtest/gtest.h>
#include <sphere.hxx>
#include <ray.hxx>
#include <vector>
#include <tolerance.hxx>
#include <matrix4x4.hxx>
#include <transformFactory.hxx>

TEST(Sphere, Intersection2Points)
{
    Ray ray(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 2);
    ASSERT_TRUE(IsEq(ints[0].param, 4.0f));
    ASSERT_TRUE(IsEq(ints[1].param, 6.0f));
}

TEST(Sphere, IntersectionObjects)
{
    Ray ray(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 2);
    ASSERT_TRUE(ints[0].object == &sphere);
    ASSERT_TRUE(ints[1].object == &sphere);
}

TEST(Sphere, IntersectionTangent)
{
    Ray ray(Point4(0.0f, 1.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 2);
    ASSERT_TRUE(IsEq(ints[0].param, 5.0f));
    ASSERT_TRUE(IsEq(ints[1].param, 5.0f));
}

TEST(Sphere, NoIntersection)
{
    Ray ray(Point4(0.0f, 2.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 0);
}

TEST(Sphere, IntersectionRayInside)
{
    Ray ray(Point4(0.0f, 0.0f, 0.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 2);
    ASSERT_TRUE(IsEq(ints[0].param, -1.0f));
    ASSERT_TRUE(IsEq(ints[1].param, 1.0f));
}

TEST(Sphere, IntersectionBehindRay)
{
    Ray ray(Point4(0.0f, 0.0f, 5.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);
    ASSERT_TRUE(ints.size() == 2);
    ASSERT_TRUE(IsEq(ints[0].param, -6.0f));
    ASSERT_TRUE(IsEq(ints[1].param, -4.0f));
}

TEST(Sphere, HitIndex)
{
    Ray ray(Point4(0.0f, 0.0f, 0.0f), Vector4(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    std::vector<Object *> objects{&sphere};
    Intersections ints;
    ray.GetIntersections(objects, ints);

    EXPECT_TRUE(ray.GetHit(ints) == 1);
}

TEST(Sphere, DefaultTransform)
{
    Sphere s;
    EXPECT_TRUE(s.GetTransformation() == Matrix4x4::IdentityMatrix());
}

TEST(Sphere, SetTranslation)
{
    Sphere s;
    auto translate = TransformFactory::Translate(2.0f, 3.0f, 4.0f);
    s.SetTransformation(translate);
    EXPECT_TRUE(s.GetTransformation() == translate);
}

TEST(Sphere, IntersectScaled)
{
    Sphere s;
    Ray r(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    auto scale = TransformFactory::Scale(2.0f, 2.0f, 2.0f);
    s.SetTransformation(scale);
    std::vector<Object*> objects{&s};
    Intersections ints;
    r.GetIntersections(objects, ints);
    EXPECT_TRUE(ints.size() == 2);
    EXPECT_TRUE(IsEq(ints[0].param, 3.0f));
    EXPECT_TRUE(IsEq(ints[1].param, 7.0f));
}

TEST(Sphere, IntersectTranslated)
{
    Sphere s;
    Ray r(Point4(0.0f, 0.0f, -5.0f), Vector4(0.0f, 0.0f, 1.0f));
    auto scale = TransformFactory::Translate(5.0f, 0.0f, 0.0f);
    s.SetTransformation(scale);
    std::vector<Object*> objects{&s};
    Intersections ints;
    r.GetIntersections(objects, ints);
    EXPECT_TRUE(ints.size() == 0);
}
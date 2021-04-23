#include <gtest/gtest.h>
#include <transformFactory.hxx>
#include <point4.hxx>
#include <vector4.hxx>
#include <constants.hxx>

TEST(Transform, TranslatePoint)
{
    Point4 pt(-3.0f, 4.0f, 5.0f);
    Matrix4x4 translation = TransformFactory::Translate(5.0f, -3.0f, 2.0f);

    EXPECT_TRUE((translation * pt) == Point4(2.0f, 1.0f, 7.0f));
}

TEST(Transform, TranslatePointInv)
{
    Point4 pt(-3.0f, 4.0f, 5.0f);
    Matrix4x4 translation = TransformFactory::Translate(5.0f, -3.0f, 2.0f);

    EXPECT_TRUE((translation.Inverse() * pt) == Point4(-8.0f, 7.0f, 3.0f));
}

TEST(Transform, TranslateVector)
{
    Vector4 vec(-3.0f, 4.0f, 5.0f);
    Matrix4x4 translation = TransformFactory::Translate(5.0f, -3.0f, 2.0f);

    EXPECT_TRUE((translation * vec) == Vector4(-3.0f, 4.0f, 5.0f));
}

TEST(Transform, ScalePoint)
{
    Matrix4x4 scale = TransformFactory::Scale(2.0f, 3.0f, 4.0f);
    Point4 pt(-4.0f, 6.0f, 8.0f);

    EXPECT_TRUE((scale * pt) == Point4(-8.0, 18.0f, 32.0f));
}

TEST(Transform, ScalePointInv)
{
    Matrix4x4 scale = TransformFactory::Scale(2.0f, 3.0f, 4.0f);
    Point4 pt(-4.0f, 6.0f, 8.0f);

    EXPECT_TRUE((scale.Inverse() * pt) == Point4(-2.0, 2.0f, 2.0f));
}

TEST(Transform, ScaleVector)
{
    Matrix4x4 scale = TransformFactory::Scale(2.0f, 3.0f, 4.0f);
    Vector4 vec(-4.0f, 6.0f, 8.0f);

    EXPECT_TRUE((scale * vec) == Vector4(-8.0, 18.0f, 32.0f));
}

TEST(Transform, RotationX)
{
    Matrix4x4 rotXHalf = TransformFactory::RotationX(pi_2);
    Matrix4x4 rotXQuarter = TransformFactory::RotationX(pi_4);
    Point4 pt(0.0f, 1.0f, 0.0f);

    EXPECT_TRUE((rotXHalf * pt) == Point4(0.0f, 0.0f, 1.0f));
    EXPECT_TRUE((rotXQuarter * pt) == Point4(0.0f, sqrt_2_inv, sqrt_2_inv));
    EXPECT_TRUE((rotXQuarter.Inverse() * pt) == Point4(0.0f, sqrt_2_inv, -sqrt_2_inv));
}

TEST(Transform, RotationY)
{
    Matrix4x4 rotYHalf = TransformFactory::RotationY(pi_2);
    Matrix4x4 rotYQuarter = TransformFactory::RotationY(pi_4);
    Point4 pt(0.0f, 0.0f, 1.0f);

    EXPECT_TRUE((rotYHalf * pt) == Point4(1.0f, 0.0f, 0.0f));
    EXPECT_TRUE((rotYQuarter * pt) == Point4(sqrt_2_inv, 0.0f, sqrt_2_inv));
}

TEST(Transform, RotationZ)
{
    Matrix4x4 rotZHalf = TransformFactory::RotationZ(pi_2);
    Matrix4x4 rotZQuarter = TransformFactory::RotationZ(pi_4);
    Point4 pt(0.0f, 1.0f, 0.0f);

    EXPECT_TRUE((rotZHalf * pt) == Point4(-1.0f, 0.0f, 0.0f));
    EXPECT_TRUE((rotZQuarter * pt) == Point4(-sqrt_2_inv, sqrt_2_inv, 0.0f));
}

TEST(Transform, SheerXy)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerXy = TransformFactory::Sheer(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    EXPECT_TRUE((sheerXy * pt) == Point4(5.0f, 3.0f, 4.0f));
}

TEST(Transform, SheerXz)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerXz = TransformFactory::Sheer(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    EXPECT_TRUE((sheerXz * pt) == Point4(6.0f, 3.0f, 4.0f));
}

TEST(Transform, SheerYx)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerYx = TransformFactory::Sheer(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);

    EXPECT_TRUE((sheerYx * pt) == Point4(2.0f, 5.0f, 4.0f));
}

TEST(Transform, SheerYz)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerYz = TransformFactory::Sheer(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);

    EXPECT_TRUE((sheerYz * pt) == Point4(2.0f, 7.0f, 4.0f));
}

TEST(Transform, SheerZx)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerZx = TransformFactory::Sheer(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    EXPECT_TRUE((sheerZx * pt) == Point4(2.0f, 3.0f, 6.0f));
}

TEST(Transform, SheerZy)
{
    Point4 pt(2.0f, 3.0f, 4.0f);
    Matrix4x4 sheerZy = TransformFactory::Sheer(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

    EXPECT_TRUE((sheerZy * pt) == Point4(2.0f, 3.0f, 7.0f));
}

TEST(Transform, ChainTransformIndividual)
{
    Point4 pt(1.0f, 0.0f, 1.0f);
    Matrix4x4 A = TransformFactory::RotationX(pi_2);
    Matrix4x4 B = TransformFactory::Scale(5.0f, 5.0f, 5.0f);
    Matrix4x4 C = TransformFactory::Translate(10.0f, 5.0f, 7.0f);

    Point4 p2 = (A * pt);
    EXPECT_TRUE(p2 == Point4(1.0f, -1.0f, 0.0f));
    Point4 p3 = (B * p2);
    EXPECT_TRUE(p3 == Point4(5.0f, -5.0f, 0.0f));
    Point4 p4 = (C * p3);
    EXPECT_TRUE(p4 == Point4(15.0f, 0.0f, 7.0f));
}

TEST(Transform, ChainTransform)
{
    Point4 pt(1.0f, 0.0f, 1.0f);
    Matrix4x4 A = TransformFactory::RotationX(pi_2);
    Matrix4x4 B = TransformFactory::Scale(5.0f, 5.0f, 5.0f);
    Matrix4x4 C = TransformFactory::Translate(10.0f, 5.0f, 7.0f);

    Matrix4x4 T = C * B * A;
    EXPECT_TRUE((T * pt) == Point4(15.0f, 0.0f, 7.0f));
}
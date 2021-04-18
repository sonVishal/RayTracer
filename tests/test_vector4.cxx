#include <gtest/gtest.h>
#include <vector4.hxx>
#include <tolerance.hxx>
#include <point4.hxx>
#include <cmath>

TEST(Vector, VectorCreate)
{
    Vector4 testVec;
    EXPECT_FLOAT_EQ(testVec.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorSetCopy)
{
    Vector4 testVec(1.0f, 1.1f, 0.1f);
    Vector4 copiedVec(testVec);

    EXPECT_FLOAT_EQ(testVec[0], 1.0f);
    EXPECT_FLOAT_EQ(testVec[1], 1.1f);
    EXPECT_FLOAT_EQ(testVec[2], 0.1f);
    EXPECT_FLOAT_EQ(testVec.GetPerspectiveTerm(), 0.0f);

    EXPECT_FLOAT_EQ(copiedVec[0], 1.0f);
    EXPECT_FLOAT_EQ(copiedVec[1], 1.1f);
    EXPECT_FLOAT_EQ(copiedVec[2], 0.1f);
    EXPECT_FLOAT_EQ(copiedVec.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorSetAssign)
{
    Vector4 testVec(1.0f, 1.1f, 0.1f);
    Vector4 copiedVec = testVec;

    EXPECT_FLOAT_EQ(testVec[0], 1.0f);
    EXPECT_FLOAT_EQ(testVec[1], 1.1f);
    EXPECT_FLOAT_EQ(testVec[2], 0.1f);
    EXPECT_FLOAT_EQ(testVec.GetPerspectiveTerm(), 0.0f);

    EXPECT_FLOAT_EQ(copiedVec[0], 1.0f);
    EXPECT_FLOAT_EQ(copiedVec[1], 1.1f);
    EXPECT_FLOAT_EQ(copiedVec[2], 0.1f);
    EXPECT_FLOAT_EQ(copiedVec.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorAdd)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2(2.0f, 1.5f, 1.0f);
    Vector4 v3 = v1 + v2;

    EXPECT_FLOAT_EQ(v3[0], 3.0f);
    EXPECT_FLOAT_EQ(v3[1], 3.5f);
    EXPECT_FLOAT_EQ(v3[2], 3.5f);
    EXPECT_FLOAT_EQ(v3.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorSubtract)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2(2.0f, 1.5f, 1.0f);
    Vector4 v3 = v1 - v2;

    EXPECT_FLOAT_EQ(v3[0], -1.0f);
    EXPECT_FLOAT_EQ(v3[1], 0.5f);
    EXPECT_FLOAT_EQ(v3[2], 1.5f);
    EXPECT_FLOAT_EQ(v3.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorCross)
{
    Vector4 v1(1.0f, 0.0f, 0.0f);
    Vector4 v2(0.0f, 1.0f, 0.0f);
    Vector4 v3 = v1 * v2;

    EXPECT_FLOAT_EQ(v3[0], 0.0f);
    EXPECT_FLOAT_EQ(v3[1], 0.0f);
    EXPECT_FLOAT_EQ(v3[2], 1.0f);
    EXPECT_FLOAT_EQ(v3.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorDot)
{
    Vector4 v1(1.0f, 0.0f, 0.0f);
    Vector4 v2(0.0f, 1.0f, 0.0f);
    float dot = v1 % v2;

    EXPECT_FLOAT_EQ(dot, 0.0f);
}

TEST(Vector, VectorToPoint)
{
    Vector4 testVec(3.0f, 2.0f, 1.0f);
    Point4 testPoint = testVec.ToPoint();

    EXPECT_FLOAT_EQ(testPoint[0], 3.0f);
    EXPECT_FLOAT_EQ(testPoint[1], 2.0f);
    EXPECT_FLOAT_EQ(testPoint[2], 1.0f);
    EXPECT_FLOAT_EQ(testPoint.GetPerspectiveTerm(), 1.0f);
}

TEST(Vector, VectorScale)
{
    const Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2 = v1.Scale(2.0f);

    EXPECT_FLOAT_EQ(v1[0], 1.0f);
    EXPECT_FLOAT_EQ(v1[1], 2.0f);
    EXPECT_FLOAT_EQ(v1[2], 2.5f);
    EXPECT_FLOAT_EQ(v1.GetPerspectiveTerm(), 0.0f);

    EXPECT_FLOAT_EQ(v2[0], 2.0f);
    EXPECT_FLOAT_EQ(v2[1], 4.0f);
    EXPECT_FLOAT_EQ(v2[2], 5.0f);
    EXPECT_FLOAT_EQ(v2.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorScaleInPlace)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);

    EXPECT_FLOAT_EQ(v1[0], 1.0f);
    EXPECT_FLOAT_EQ(v1[1], 2.0f);
    EXPECT_FLOAT_EQ(v1[2], 2.5f);
    EXPECT_FLOAT_EQ(v1.GetPerspectiveTerm(), 0.0f);

    v1.Scale(2.0f);

    EXPECT_FLOAT_EQ(v1[0], 2.0f);
    EXPECT_FLOAT_EQ(v1[1], 4.0f);
    EXPECT_FLOAT_EQ(v1[2], 5.0f);
    EXPECT_FLOAT_EQ(v1.GetPerspectiveTerm(), 0.0f);
}

TEST(Vector, VectorMagnitude)
{
    Vector4 testVec(3.0f, 4.0f, 5.0f);
    EXPECT_TRUE(IsEq(testVec.Magnitude(), sqrt(50.0f)));
}

TEST(Vector, VectorMagnitudeSq)
{
    Vector4 testVec(3.0f, 4.0f, 5.0f);
    EXPECT_TRUE(IsEq(testVec.MagnitudeSq(), 50.0f));
}

TEST(Vector, VectorNormalize)
{
    const Vector4 v1(1.0f, 2.0f, 3.0f);
    Vector4 v2 = v1.Normalize();
    EXPECT_TRUE(IsEq(v2.MagnitudeSq(), 1.0f));
}

TEST(Vector, VectorNormalizeInPlace)
{
    Vector4 v1(1.0f, 2.0f, 3.0f);
    v1.Normalize();
    EXPECT_TRUE(IsEq(v1.MagnitudeSq(), 1.0f));
}

TEST(Vector, VectorAffineCombination)
{
    Vector4 v1(1.0f, 2.0f, 3.0f);
    Vector4 v2(2.0f, 3.0f, 4.0f);
    Vector4 v3 = v1.AffineCombination(0.5f, 0.2f, v2);
    EXPECT_FLOAT_EQ(v3[0], 0.9f);
    EXPECT_FLOAT_EQ(v3[1], 1.6f);
    EXPECT_FLOAT_EQ(v3[2], 2.3f);
    EXPECT_FLOAT_EQ(v3.GetPerspectiveTerm(), 0.0f);
}
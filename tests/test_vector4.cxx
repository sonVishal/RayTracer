#include <gtest/gtest.h>
#include <vector4.hxx>
#include <tolerance.hxx>
#include <point4.hxx>
#include <cmath>

TEST(Vector, VectorCreate)
{
    Vector4 testVec;
    EXPECT_FLOAT_EQ(testVec[3], 0.0f);
}

TEST(Vector, VectorSetCopy)
{
    Vector4 testVec(1.0f, 1.1f, 0.1f);
    Vector4 copiedVec(testVec);

    EXPECT_TRUE(testVec == copiedVec);
}

TEST(Vector, VectorSetAssign)
{
    Vector4 testVec(1.0f, 1.1f, 0.1f);
    Vector4 copiedVec = testVec;

    EXPECT_TRUE(copiedVec == testVec);
}

TEST(Vector, VectorAdd)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2(2.0f, 1.5f, 1.0f);
    Vector4 v3 = v1 + v2;

    EXPECT_TRUE(Vector4(3.0f, 3.5f, 3.5f) == v3);
}

TEST(Vector, VectorSubtract)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2(2.0f, 1.5f, 1.0f);
    Vector4 v3 = v1 - v2;

    EXPECT_TRUE(v3 == Vector4(-1.0f, 0.5f, 1.5f));
}

TEST(Vector, VectorCross)
{
    Vector4 v1(1.0f, 0.0f, 0.0f);
    Vector4 v2(0.0f, 1.0f, 0.0f);
    Vector4 v3 = v1 * v2;

    EXPECT_TRUE(v3 == Vector4(0.0f, 0.0f, 1.0f));
}

TEST(Vector, VectorDotPerpendicular)
{
    Vector4 v1(1.0f, 0.0f, 0.0f);
    Vector4 v2(0.0f, 1.0f, 0.0f);
    float dot = v1 % v2;

    EXPECT_TRUE(IsEq(dot, 0.0f));
}

TEST(Vector, VectorDot)
{
    Vector4 v1(1.0f, 2.0f, 0.0f);
    Vector4 v2(1.0f, 1.0f, 0.0f);
    float dot = v1 % v2;

    EXPECT_TRUE(IsEq(dot, 3.0f));
}

TEST(Vector, VectorToPoint)
{
    Vector4 testVec(3.0f, 2.0f, 1.0f);
    Point4 testPoint = testVec.ToPoint();

    EXPECT_TRUE(testPoint == Point4(3.0f, 2.0f, 1.0f));
}

TEST(Vector, VectorScale)
{
    const Vector4 v1(1.0f, 2.0f, 2.5f);
    Vector4 v2 = (v1 * 2.0f);

    EXPECT_TRUE(v2 == Vector4(2.0f, 4.0f, 5.0f));
}

TEST(Vector, VectorNegate)
{
    Vector4 v1(1.0f, 2.0f, 2.5f);
    v1 = -v1;

    EXPECT_TRUE(v1 == Vector4(-1.0f, -2.0f, -2.5f));
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
    EXPECT_TRUE(v3 == Vector4(0.9f, 1.6f, 2.3f));
}
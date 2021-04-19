#include <gtest/gtest.h>
#include <vector4.hxx>
#include <tolerance.hxx>
#include <point4.hxx>
#include <cmath>

TEST(Point, PointCreate)
{
    Point4 testPt;
    EXPECT_FLOAT_EQ(testPt[3], 1.0f);
}

TEST(Point, PointToVector)
{
    Point4 testPt(3.0f, 2.0f, 1.0f);
    Vector4 testVec = testPt.ToVector();

    EXPECT_TRUE(testVec == Vector4(3.0f, 2.0f, 1.0f));
}
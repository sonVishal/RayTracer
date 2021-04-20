#include <gtest/gtest.h>
#include <matrix4x4.hxx>
#include <vector4.hxx>
#include <point4.hxx>
#include <tolerance.hxx>

TEST(Matrix, Create)
{
    Matrix4x4 mat;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            EXPECT_TRUE(IsEq(mat[i][j], 0.0f));
}

TEST(Matrix, MatMultiply)
{
    float m1Arr[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f},
                         {9.0f, 8.0f, 7.0f, 6.0f}, {5.0f, 4.0f, 3.0f, 2.0f}};
    float m2Arr[4][4] = {{-2.0f, 1.0f, 2.0f, 3.0f}, {3.0f, 2.0f, 1.0f, -1.0f},
                         {4.0f, 3.0f, 6.0f, 5.0f}, {1.0f, 2.0f, 7.0f, 8.0f}};
    float m3Arr[4][4] = {{20.0f, 22.0f, 50.0f, 48.0f}, {44.0f, 54.0f, 114.0f, 108.0f},
                         {40.0f, 58.0f, 110.0f, 102.0f}, {16.0f, 26.0f, 46.0f, 42.0f}};
    Matrix4x4 m1(m1Arr);
    Matrix4x4 m2(m2Arr);
    Matrix4x4 m3(m3Arr);
    Matrix4x4 result = m1 * m2;

    EXPECT_TRUE(result == m3);
}

TEST(Matrix, VecMultiply)
{
    float arr[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f}, {2.0f, 4.0f, 4.0f, 2.0f},
                    {8.0f, 6.0f, 4.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 A(arr);
    Vector4 b(1.0f, 2.0f, 3.0f);

    EXPECT_TRUE((A * b) == Vector4(14.0f, 22.0f, 32.0f));
}

TEST(Matrix, PointMultiply)
{
    float arr[4][4] = {{1.0f, 2.0f, 3.0f, 4.0f}, {2.0f, 4.0f, 4.0f, 2.0f},
                    {8.0f, 6.0f, 4.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 A(arr);
    Point4 b(1.0f, 2.0f, 3.0f);

    EXPECT_TRUE((A * b) == Point4(18.0f, 24.0f, 33.0f));
}
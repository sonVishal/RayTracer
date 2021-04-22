#ifndef _MATRIX_4x4_HXX_
#define _MATRIX_4x4_HXX_

#include <vector4.hxx>
#include <point4.hxx>

class Matrix4x4
{
private:
    float m_elems[4][4] = {};

public:
    Matrix4x4();
    ~Matrix4x4();
    Matrix4x4(const Matrix4x4 &other);
    Matrix4x4(float other[4][4]);

    Matrix4x4 &operator=(const Matrix4x4 &other);
    bool operator==(const Matrix4x4 &other) const;
    float *operator[](int i);
    const float *operator[](int i) const;
    Matrix4x4 operator*(const Matrix4x4 &other) const;
    Vector4 operator*(const Vector4 &vec) const;
    Point4 operator*(const Point4 &point) const;

    static Matrix4x4 IdentityMatrix();
    Matrix4x4 Transpose() const;

    float GetMinorOfSubMatrixAt(int i, int j) const;
    float GetCoFactorOfSubMatrixAt(int i, int j) const;

    bool IsInvertible() const;
    Matrix4x4 Inverse() const;

    float Determinant() const;
};

#endif
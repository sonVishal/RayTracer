#include <matrix4x4.hxx>
#include <tolerance.hxx>

Matrix4x4::Matrix4x4()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            m_elems[i][j] = 0.0f;
}

Matrix4x4::Matrix4x4(const Matrix4x4 &other)
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            m_elems[i][j] = other[i][j];
}

Matrix4x4 &Matrix4x4::operator=(const Matrix4x4 &other)
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            (*this)[i][j] = other[i][j];
    return (*this);
}

Matrix4x4::Matrix4x4(float other[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            m_elems[i][j] = other[i][j];
}

bool Matrix4x4::operator==(const Matrix4x4 &other) const
{
    bool isEq = true;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!IsEq((*this)[i][j], other[i][j]))
            {
                isEq = false;
                break;
            }
        }
        if (!isEq)
            break;
    }
    return isEq;
}

Matrix4x4::~Matrix4x4()
{
}

float *Matrix4x4::operator[](int i)
{
    return m_elems[i];
}

const float *Matrix4x4::operator[](int i) const
{
    return m_elems[i];
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &other) const
{
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result[i][j] = ((*this)[i][0] * other[0][j]) +
                           ((*this)[i][1] * other[1][j]) +
                           ((*this)[i][2] * other[2][j]) +
                           ((*this)[i][3] * other[3][j]);
    return result;
}

Vector4 Matrix4x4::operator*(const Vector4 &vec) const
{
    Vector4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result[i] += (*this)[i][j] * vec[j];
    return result;
}

Point4 Matrix4x4::operator*(const Point4 &point) const
{
    Point4 result;
    for (int i = 0; i < 4; ++i)
        result[i] = ((*this)[i][0] * point[0]) + ((*this)[i][1] * point[1]) +
                ((*this)[i][2] * point[2]) + ((*this)[i][3] * point[3]);
    return result;
}

Matrix4x4 Matrix4x4::IdentityMatrix()
{
    Matrix4x4 id;
    id[0][0] = id[1][1] = id[2][2] = id[3][3] = 1.0f;
    return id;
}

Matrix4x4 Matrix4x4::Transpose() const
{
    Matrix4x4 transpose(*this);

    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            std::swap(transpose[i][j], transpose[j][i]);

    return transpose;
}

static float getDeterminantOf3x3Matrix(const float (&matrix3x3)[3][3])
{
    float det = 0.0f;
    det += matrix3x3[0][0] * (matrix3x3[1][1] * matrix3x3[2][2] - matrix3x3[2][1] * matrix3x3[1][2]);
    det += matrix3x3[0][1] * (matrix3x3[1][2] * matrix3x3[2][0] - matrix3x3[1][0] * matrix3x3[2][2]);
    det += matrix3x3[0][2] * (matrix3x3[1][0] * matrix3x3[2][1] - matrix3x3[2][0] * matrix3x3[1][2]);
    return det;
}

float Matrix4x4::GetMinorOfSubMatrixAt(int x, int y) const
{
    float minorMat[3][3] = {};
    for (int i = 0; i < 4 && i != x; ++i)
    {
        for (int j = 0; j < 4 && j != y; ++j)
        {
            int r = i, c = j;
            if (r > x)
                r--;
            if (c > y)
                c--;
            minorMat[r][c] = (*this)[i][j];
        }
    }

    return getDeterminantOf3x3Matrix(minorMat);
}

float Matrix4x4::GetCoFactorOfSubMatrixAt(int i, int j) const
{
    float cofactor = GetMinorOfSubMatrixAt(i, j);
    if (i + j % 2 == 1)
    {
        cofactor *= -1.0f;
    }
    return cofactor;
}

float Matrix4x4::Determinant() const
{
    float det  = 0.0f;
    for (int i = 0; i < 4; ++i)
        det += GetCoFactorOfSubMatrixAt(0, 0) * (*this)[0][0];
    return det;
}

bool Matrix4x4::IsInvertible() const
{
    float det = Determinant();
    return !IsEq(det, 0.0f);
}

Matrix4x4 Matrix4x4::Inverse() const
{
    if (!IsInvertible())
    {
        throw std::overflow_error("Matrix is not invertible");
    }
    Matrix4x4 inverse;

    return inverse;
}

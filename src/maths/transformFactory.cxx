#include <transformFactory.hxx>
#include <cmath>

TransformFactory::TransformFactory(/* args */)
{
}

TransformFactory::~TransformFactory()
{
}

Matrix4x4 TransformFactory::Translate(float x, float y, float z)
{
    float arr[4][4] = {{1.0f, 0.0f, 0.0f, x},
                       {0.0f, 1.0f, 0.0f, y},
                       {0.0f, 0.0f, 1.0f, z},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 translation(arr);
    return translation;
}

Matrix4x4 TransformFactory::Scale(float x, float y, float z)
{
    float arr[4][4] = {{x, 0.0f, 0.0f, 0.0f},
                       {0.0f, y, 0.0f, 0.0f},
                       {0.0f, 0.0f, z, 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 scale(arr);
    return scale;
}

Matrix4x4 TransformFactory::RotationX(float radians)
{
    float arr[4][4] = {{1.0, 0.0f, 0.0f, 0.0f},
                       {0.0f, cosf(radians), -sinf(radians), 0.0f},
                       {0.0f, sinf(radians), cosf(radians), 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 rotX(arr);
    return rotX;
}

Matrix4x4 TransformFactory::RotationY(float radians)
{
    float arr[4][4] = {{cosf(radians), 0.0f, sinf(radians), 0.0f},
                       {0.0f, 1.0f, 0.0f, 0.0f},
                       {-sinf(radians), 0.0f, cosf(radians), 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 rotY(arr);
    return rotY;
}

Matrix4x4 TransformFactory::RotationZ(float radians)
{
    float arr[4][4] = {{cosf(radians), -sinf(radians), 0.0f, 0.0f},
                       {sinf(radians), cosf(radians), 0.0f, 0.0f},
                       {0.0f, 0.0f, 1.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 rotZ(arr);
    return rotZ;
}

Matrix4x4 TransformFactory::Sheer(float xy, float xz,
                                  float yx, float yz,
                                  float zx, float zy)
{
    float arr[4][4] = {{1.0f, xy, xz, 0.0f},
                       {yx, 1.0f, yz, 0.0f},
                       {zx, zy, 1.0f, 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};
    Matrix4x4 sheer(arr);
    return sheer;
}

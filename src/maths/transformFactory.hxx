#ifndef _TRANSFORM_HXX_
#define _TRANSFORM_HXX_

#include <matrix4x4.hxx>

class TransformFactory
{
private:
    TransformFactory();
public:
    static Matrix4x4 Translate(float x, float y, float z);
    static Matrix4x4 Scale(float x, float y, float z);
    static Matrix4x4 RotationX(float radians);
    static Matrix4x4 RotationY(float radians);
    static Matrix4x4 RotationZ(float radians);
    static Matrix4x4 Sheer(float xy, float xz, float yx, float yz, float zx, float zy);

    ~TransformFactory();
};

#endif
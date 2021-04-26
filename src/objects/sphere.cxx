#include <sphere.hxx>
#include <ray.hxx>
#include <cmath>

void Sphere::Intersect(const Ray &ray, std::vector<float> &rayParams) const
{
    float a = ray.GetDirection() % ray.GetDirection();
    Vector4 sphereToRay = ray.GetOrigin() - this->GetOrigin();
    float b = 2.0f * (ray.GetDirection() % sphereToRay);
    float c = (sphereToRay % sphereToRay) - 1.0f;

    float discriminant = b * b - 4.0f * a * c;
    if (discriminant < 0.0)
    {
        return;
    }
    rayParams.push_back((-b - sqrt(discriminant)) / (2.0f * a));
    rayParams.push_back((-b + sqrt(discriminant)) / (2.0f * a));
}

Vector4 Sphere::Normal(const Point4& point) const
{
    Vector4 normal;
    auto invTransf = m_transformation.Inverse();
    Point4 objectPoint = (invTransf * point);
    normal = (objectPoint - m_origin);

    normal = (invTransf.Transpose() * normal);
    normal.Normalize();

    return normal;
}
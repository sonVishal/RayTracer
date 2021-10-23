#include <ray.hxx>
#include <object.hxx>
#include <algorithm>

Ray::Ray()
{
}

Ray::Ray(const Point4 &origin, const Vector4 &direction) : m_origin(origin), m_direction(direction)
{
}

Point4 Ray::GetPosition(float dist) const
{
    return (m_origin + (m_direction * dist));
}

void Ray::GetIntersection(const Object &obj, std::vector<float> &params) const
{
    return obj.Intersect((*this), params);
}

void Ray::GetIntersections(const std::vector<Object *> &objects, Intersections &intersections) const
{
    intersections.clear();
    for (auto object : objects)
    {
        std::vector<float> params;
        Ray newRay = this->Transform(object->GetTransformation().Inverse());
        newRay.GetIntersection(*object, params);
        for (auto p : params)
        {
            Intersection intersection;
            intersection.object = object;
            intersection.param = p;
            intersections.emplace_back(intersection);
        }
        // Sort the intersections so that it is easier to deal with later
        std::sort(intersections.begin(), intersections.end(),
                  [](const Intersection &i1, const Intersection &i2) { return i1.param < i2.param; });
    }
}

Precomputation Ray::GetPrecomputation(const Intersection& intersection) const
{
    Precomputation preComp = {};
    preComp.param = intersection.param;
    preComp.object = intersection.object;
    preComp.intersectionPoint = this->GetPosition(intersection.param);
    preComp.eyeVector = (-this->GetDirection());
    preComp.normal = intersection.object->Normal(preComp.intersectionPoint);

    if ((preComp.normal % preComp.eyeVector) < 0.0f)
    {
        preComp.inside = true;
        preComp.normal = -preComp.normal;
    }
    else
    {
        preComp.inside = false;
    }

    return preComp;
}

bool operator==(const Intersection &i1, const Intersection &i2)
{
    return IsEq(i1.param, i2.param);
}

bool operator<(const Intersection &i1, const Intersection &i2)
{
    if (i1 == i2)
    {
        return false;
    }
    return (i1.param < i2.param);
}

int Ray::GetHit(const Intersections &intersections) const
{
    Intersections ints(intersections);
    std::sort(ints.begin(), ints.end());

    for (int i = 0; i < ints.size(); ++i)
    {
        if (!IsEq(ints[i].param, 0.0) && (ints[i].param > 0.0))
        {
            return i;
        }
    }
    return -1;
}

Ray Ray::Transform(Matrix4x4 transformation) const
{
    Ray transformedRay((transformation * this->m_origin),
                       (transformation * this->m_direction));

    return transformedRay;
}

Ray::~Ray()
{
}
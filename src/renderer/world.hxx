#ifndef _WORLD_HXX_
#define _WORLD_HXX_

#include <object.hxx>
#include <light.hxx>
#include <vector>
#include <ray.hxx>

class World
{
private:
    std::vector<Object*> m_objects;
    std::vector<Light*> m_lights;
public:
    World();
    ~World();
    int GetNumObjects() { return m_objects.size(); }
    int GetNumLights() { return m_lights.size(); }
    void AddObject(Object* obj) { m_objects.push_back(obj); }
    void AddLight(Light* light) { m_lights.push_back(light); }
    void IntersectRay(const Ray& r, Intersections& ints);
};

#endif
#include <world.hxx>

World::World()
{
}

World::~World()
{
    for (auto o : m_objects)
    {
        delete o;
    }
    for (auto l : m_lights)
    {
        delete l;
    }
}

void World::IntersectRay(const Ray &r, Intersections &ints)
{
    r.GetIntersections(m_objects, ints);
}
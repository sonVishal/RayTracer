#include <RayTracerConfig.h>
#include <iostream>
#include <ray.hxx>
#include <sphere.hxx>
#include <canvas.hxx>
#include <ppmWriter.hxx>
#include <colour.hxx>
#include <material.hxx>
#include <pointLight.hxx>
#include <shader.hxx>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Welcome to RayTracer VERSION " << RayTracer_VERSION_MAJOR;
    cout << "." << RayTracer_VERSION_MINOR << endl;

    Point4 rayOrigin(0.0f, 0.0f, -5.0f);
    float wallZ = 10.0f;
    float wallSize = 7.0f;
    int numPixels = 100;
    Canvas canvas(numPixels, numPixels);
    float pixelSize = wallSize / numPixels;
    float wallSize_2 = wallSize * 0.5f;

    Sphere s;
    Material m;
    m.SetColour(Colour(1.0f, 0.2f, 1.0f));
    s.SetMaterial(m);
    PointLight l(Point4(-10.0, 10.0, -10.0), Colour(1.0f, 1.0f, 1.0f));

    std::vector<Object *> objects{&s};
    Intersections ints;

    for (int y = 0; y < numPixels; y++)
    {
        float worldY = -wallSize_2 + pixelSize * y;
        for (int x = 0; x < numPixels; x++)
        {
            float worldX = -wallSize_2 + pixelSize * x;
            Vector4 rayDir = Point4(worldX, worldY, wallZ) - rayOrigin;
            rayDir.Normalize();
            Ray r(rayOrigin, rayDir);
            Vector4 eyeVec = (-rayDir);
            r.GetIntersections(objects, ints);
            int idx = r.GetHit(ints);
            if (idx >= 0)
            {
                Point4 hitPoint = rayOrigin + (rayDir * ints[0].param);
                Colour hitColour = Shader::Lighting(m, &l, hitPoint, eyeVec, s.Normal(hitPoint));

                canvas.WritePixelAt(x, y, hitColour);
            }
        }
    }

    PpmWriter ppmWriter(&canvas, "./test");
    ppmWriter.WriteData();

    return 0;
}

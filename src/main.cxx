#include <RayTracerConfig.h>
#include <iostream>
#include <ray.hxx>
#include <sphere.hxx>
#include <canvas.hxx>
#include <ppmWriter.hxx>
#include <colour.hxx>

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
    std::vector<Object *> objects{&s};
    Intersections ints;

    for (int y = 0; y < numPixels; y++)
    {
        float worldY = wallSize_2 - pixelSize * y;
        for (int x = 0; x < numPixels; x++)
        {
            float worldX = -wallSize_2 + pixelSize * x;
            Vector4 rayDir = Point4(worldX, worldY, wallZ) - rayOrigin;
            rayDir.Normalize();
            Ray r(rayOrigin, rayDir);

            r.GetIntersections(objects, ints);

            if (r.GetHit(ints) >= 0)
            {
                canvas.WritePixelAt(x, y, Colour(1.0f, 0.0f, 0.0f));
            }
            else
            {
                canvas.WritePixelAt(x, y, Colour(1.0f, 1.0f, 1.0f));
            }
        }
    }

    PpmWriter ppmWriter(&canvas, "./test");
    ppmWriter.WriteData();

    return 0;
}

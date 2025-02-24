#include <iostream>
#include "point3.h"
#include "scene.h"
#include "vector3.h"
#include "color.h"
#include "ray.h"
#include "image.h"
#include "camera.h"
#include "objects/sphere.h"
#include "point_light.h"
#include "outils.h"

int main() {
    const int width = 1000, height = 500;
    Image img(width, height);
    
    // Setup camera
    Camera camera(Point3(0, 0, 0), Point3(0, 0, -1), Vector3(0, 1, 0), 90.0, float(width) / float(height));
    
    // Setup scene
    Scene scene;
    scene.addObject(new Sphere(Point3(0, 0, -5), 1, Color(1, 0, 0)));
    
    // Source limineuse
    scene.addLight(new PointLight(Point3(0, 0, 0), Color(1, 1, 1))); // Lumiere blanche a (0, 0, 0)

    // Raycasting avec lumiere
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float u = float(x) / width;
            float v = float(y) / height;

            Ray ray = camera.getRay(u, v, width, height);
            CastRay(scene, ray, img, x, y);
        }
    }

    img.savePPM("output.ppm");
    std::cout << "Image saved as output.ppm" << std::endl;

    return 0;
}

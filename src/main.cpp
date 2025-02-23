#include <iostream>
#include "scene.h"
#include "vector3.h"
#include "color.h"
#include "ray.h"
#include "image.h"
#include "camera.h"
#include "objects/sphere.h"
#include "light.h"

int main() {
    const int width = 400, height = 200;
    Image img(width, height);
    
    // Setup camera
    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, -1), Vector3(0, 1, 0), 90.0, float(width) / float(height));
    
    // Setup scene
    Scene scene;
    scene.addObject(new Sphere(Vector3(0, 0, -5), 1, Color(1, 0, 0))); // Sphere rouge
    scene.addObject(new Sphere(Vector3(-2, 0, -4), 1, Color(0, 1, 0))); // Sphere verte
    scene.addObject(new Sphere(Vector3(2, 0, -6), 1, Color(0, 0, 1))); // Sphere bleue
    
    // Source limineuse
    scene.addLight(new Light(Vector3(5, 5, 0), Color(1, 1, 1))); // Lumiere blanche a (5, 5, 0)

    // Raycasting avec lumiere
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float u = float(x) / width;
            float v = float(y) / height;

            Ray ray = camera.getRay(u, v);
            float t_min;
            Object* hitObject = nullptr;

            if (scene.intersect(ray, t_min, hitObject)) {
                // Calcul de l'intersection point et de sa normale
                Vector3 hitPoint = ray.at(t_min);
                Vector3 normal = (hitPoint - dynamic_cast<Sphere*>(hitObject)->center).normalize();
                
                // Calcul Lumiere
                Color finalColor(0, 0, 0);
                for (auto light : scene.lights) {
                    Vector3 lightDir = (light->position - hitPoint).normalize();
                    float diff = std::max(normal.dot(lightDir), 0.0f);
                    finalColor = finalColor + (hitObject->color * light->intensity * diff);
                    finalColor = finalColor.clamp();
                }
                
                img.setPixel(x, y, finalColor);
            } else {
                img.setPixel(x, y, Color(0.2, 0.2, 0.2)); // Fond gris clair
            }
        }
    }

    img.savePPM("output.ppm");
    std::cout << "Image saved as output.ppm" << std::endl;

    return 0;
}

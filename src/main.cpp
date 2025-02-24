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

int main() {
    const int width = 1000, height = 500;
    Image img(width, height);
    
    // Setup camera
    Camera camera(Point3(0, 0, 0), Point3(0, 0, -1), Vector3(0, 1, 0), 90.0, float(width) / float(height));
    
    // Setup scene
    Scene scene;
    scene.addObject(new Sphere(Point3(0, 0, -5), 1, Color(1, 0, 0)));
    scene.addObject(new Sphere(Point3(0, -100.5, -5), 10, Color(0, 1, 0)));
    
    // Source limineuse
    scene.addLight(new PointLight(Point3(0, 0, 0), Color(1, 1, 1))); // Lumiere blanche a (0, 0, 0)

    // Raycasting avec lumiere
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float u = float(x) / width;
            float v = float(y) / height;

            Ray ray = camera.getRay(u, v, width, height);
            float t_min;
            Object* hitObject = nullptr;

            if (scene.intersect(ray, t_min, hitObject)) {
                // Calcul de l'intersection point et de sa normale
                Vector3 hitPoint = ray.at(t_min);
                Vector3 normal = (hitPoint - dynamic_cast<Sphere*>(hitObject)->center).normalize();
                
                // Calcul Lumiere
                Color finalColor(0, 0, 0);
                for (Light* light : scene.lights) {
                    Vector3 lightDirection = (light->position - hitPoint).normalize();
                    float lightDistance = (light->position - hitPoint).length();
                    Ray shadowRay = Ray(hitPoint + normal * 0.001f, lightDirection);
                    if (!scene.intersect(shadowRay, t_min, hitObject) && t_min < lightDistance) {
                        finalColor = finalColor + dynamic_cast<PointLight*>(light)->intensity * std::max(0.0f, normal.dot(lightDirection));
                    }
                }

                float shininess;
                Color col1, col2;
                dynamic_cast<Sphere*>(hitObject)->getTextureAt(hitPoint, col1, col2, shininess);
                finalColor = finalColor * col1 * col2 * std::pow(std::max(0.0f, normal.dot(ray.direction)), shininess);

                if (finalColor.r > 1) finalColor.r = 1;
                if (finalColor.g > 1) finalColor.g = 1;
                if (finalColor.b > 1) finalColor.b = 1;

                if (finalColor.r < 0) finalColor.r = 0;
                if (finalColor.g < 0) finalColor.g = 0;
                if (finalColor.b < 0) finalColor.b = 0;
                
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

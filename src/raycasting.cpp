#include "raycasting.h"
#include "color.h"
#include "image.h"
#include "light.h"
#include "scene.h"
#include "vector3.h"
#include "objects/sphere.h"
#include <cmath>
#include <cstdlib>
#include <memory>

Color CastRay(const Scene &scene, Ray &ray){
  Object* hitObject = nullptr;
  float tMin;

  if (scene.intersect(ray, tMin, hitObject)){
    Vector3 hitPoint = ray.at(tMin); // Calcul du point d'impact
    Sphere* sp = (Sphere*) hitObject;
    // std::cout << (hitPoint - sp->getCenter()).length() << std::endl;
    // std::cout << hitPoint << std::endl;

    Vector3 normal = hitObject->getNormal(hitPoint);

    Color kd, ks;
    float shininess;
    hitObject->getMaterialProperties(hitPoint, kd, ks, shininess);

    Color finalColor(0.0, 0.0, 0.0);
    for (Light* light : scene.getLights()){
      Vector3 lightDirection = light->getDirection(hitPoint);
      float diff = std::max(normal.dot(lightDirection), 0.0f);

      // Verifier si la lumiere est bloque par un autre objet
      Ray shadowRay(hitPoint + normal * 0.001f, lightDirection);
      Object* shadowObject = nullptr;
      if (!scene.intersect(shadowRay, tMin, shadowObject)){
        finalColor = finalColor + (kd * light->getIntensity(hitPoint) * diff);
        // Specular
        finalColor = finalColor + (ks * light->getIntensity(hitPoint) * pow(std::max(normal.dot(lightDirection), 0.0f), shininess));
      }
    }


    return finalColor = finalColor.clamp();
  }

  return Color(0.2, 0.2, 0.2); // Fond noir
}

void RenderImage(const Scene& scene, Image& image){
  int width = image.getWidth();
  int height = image.getHeight();
  Camera camera = scene.getCamera();

  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++){

      Ray ray = camera.getRay(x, y, width, height);
      Color color = CastRay(scene, ray);
      image.setPixel(x, y, color);

    }
  }
}

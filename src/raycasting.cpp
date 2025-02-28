#include "raycasting.h"
#include "color.h"
#include "image.h"
#include "light.h"
#include "objects/object.h"
#include "scene.h"
#include "vector3.h"
#include "objects/sphere.h"
#include <cmath>
#include <cstdlib>
#include <memory>

extern Color ambientLight;

Color CastRay(const Scene &scene, Ray &ray, int depth) {
  if (depth <= 0) {
    return Color(0.0, 0.0, 0.0);
  }
  Object* hitObject = nullptr;
  HitRecord record;

  if (scene.intersect(ray, record, hitObject)){
    Vector3 hitPoint = ray.at(record.t); // Calcul du point d'impact
    Vector3 normal = record.normal;

    Color kd, ks;
    float shininess, ka, reflectivity;
    hitObject->getTextureAt(hitPoint, kd, ks, ka, shininess, reflectivity);

    Color finalColor = ambientLight * ka;

    for (Light* light : scene.getLights()){
      Vector3 lightDirection = light->getDirection(hitPoint);
      float diff = std::max(normal.dot(lightDirection), 0.0f);

      // Refléction
      if (reflectivity > 0.0f){
        Vector3 viewDir = (ray.getDirection() * -1.0f).normalize();
        Vector3 reflectDir = ((normal * 2.0f * normal.dot(viewDir)) - viewDir).normalize();

        Ray reflectedRay(hitPoint + normal * 0.001f, reflectDir);
        Color reflectedColor = CastRay(scene, reflectedRay, depth - 1);

        finalColor = finalColor + (reflectedColor * reflectivity);
      }

      // Verifier si la lumiere est bloque par un autre objet
      Ray shadowRay(hitPoint + normal * 0.001f, lightDirection);
      HitRecord shadowRecord;
      Object* shadowObject = nullptr;

      if (!scene.intersect(shadowRay, shadowRecord, shadowObject)){
        finalColor = finalColor + (kd * light->getIntensity(hitPoint) * diff);
        // Speculaires
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
      int depth = 10;
      Color color = CastRay(scene, ray, depth);
      image.setPixel(x, y, color);

    }
  }
}

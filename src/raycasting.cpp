#include "raycasting.h"
#include "color.h"
#include "cube_map.h"
#include "image.h"
#include "light/light.h"
#include "objects/object.h"
#include "scene.h"
#include "vector3.h"
#include "objects/sphere.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <memory>

const Color backgroundColor = Color(0.2, 0.2, 0.2);

Color CastRay(const Scene &scene, Ray &ray, int depth);

Color computeLighting(const Scene &scene, const Ray &ray, const HitRecord &record, const Object *hitObject) {
  Color finalColor = Color(0.0, 0.0, 0.0);
  Vector3 hitPoint = record.point;
  Vector3 normal = record.normal;

  float kd, ks, ka, shininess, transparency, reflectivity, refractionIndex;
  hitObject->getMaterial()->getProperties(kd, ks, ka, shininess, transparency, reflectivity, refractionIndex);

  for (Light* light : scene.getLights()) {
    if (light->isAmbientLight()) {
      finalColor = finalColor + light->getIntensity(hitPoint) * ka;
      continue;
    }

    Vector3 lightDirection = light->getDirection(hitPoint); 
    int numberShadowRays = 16;
    float shadowAmount = 0.0;
    float diff = std::max(normal.dot(lightDirection), 0.0f);

    for (int i = 0; i < numberShadowRays; i++){
      Vector3 jitteredLightDirection = light->getJitteredPosition(hitPoint);

      Ray shadowRay(hitPoint + normal * 0.001f, jitteredLightDirection);
      HitRecord shadowRecord;
      Object* shadowObject = nullptr;

      if (!scene.intersect(shadowRay, shadowRecord, shadowObject)){
        shadowAmount += 1.0f;
      }
    }

    shadowAmount = shadowAmount / numberShadowRays;
    Color textureColor = hitObject->getMaterial()->getTexture()->getTextureAt(hitPoint);
    finalColor = finalColor + (textureColor * light->getIntensity(hitPoint) * diff * shadowAmount);

    // Speculaires
    if (ks > 0.0) {
      Vector3 viewDir = (ray.getDirection() * -1.0f).normalize();
      Vector3 reflectDir = ((normal * 2.0f * normal.dot(viewDir)) - viewDir).normalize();
      float spec = std::pow(std::max(reflectDir.dot(lightDirection), 0.0f), shininess);
      finalColor = finalColor + (light->getIntensity(hitPoint) * ks * spec);
    }

  }

  return finalColor;
}

Color computeReflection(const Scene &scene, const Ray &ray, const HitRecord &record, const float reflectivity, int depth) {
    Vector3 normal = record.normal;
    Vector3 reflectDir = ((normal * 2.0f * normal.dot(ray.getDirection())) - ray.getDirection()).normalize();
    Ray reflectRay(record.point + normal * 0.001f, reflectDir);
    return CastRay(scene, reflectRay, depth - 1) * reflectivity;
}

Color CastRay(const Scene &scene, Ray &ray, int depth) {
  if (depth <= 0) {
    return Color(0.0, 0.0, 0.0);    
  } 

  Object* hitObject = nullptr;
  HitRecord record;

  if (scene.intersect(ray, record, hitObject)){
    Color finalColor = computeLighting(scene, ray, record, hitObject);
    float reflectivity = hitObject->getMaterial()->getReflectivity();
    if (reflectivity > 0.0) {
      finalColor = finalColor + computeReflection(scene, ray, record, reflectivity, depth);
    }
    return finalColor.clamp();
  }

  return backgroundColor;
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

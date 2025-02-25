#include "outils.h"
#include "color.h"
#include "image.h"
#include "light.h"
#include "scene.h"
#include "vector3.h"
#include "objects/sphere.h"

Color CastRay(const Scene &scene, Ray &ray, int& count){
  Object* hitObject = nullptr;
  float tMin;

  if (scene.intersect(ray, tMin, hitObject)){
    Vector3 hitPoint = ray.at(tMin); // Calcul du point d'impact
    Vector3 normal = hitObject->getNormal(hitPoint);
    count += 1;

    Color kd, ks;
    float shininess;
    hitObject->getMaterialProperties(hitPoint, kd, ks, shininess);

    Color finalColor(0.0, 0.0, 0.0);
    for (Light* light : scene.getLights()){
      Vector3 lightDirection = light->getPosition() - hitPoint;
      float diff = std::max(normal.dot(lightDirection), 0.0f);
      finalColor = finalColor + (kd * light->getIntensity(hitPoint) * diff);
      finalColor = finalColor.clamp();
    }

    return kd; // Pour l'instant on ne prends que la lumiere diffuse
  }

  return Color(0.2, 0.2, 0.2); // Fond noir
}

void RenderImage(const Scene& scene, Image& image){
  int width = image.getWidth();
  int height = image.getHeight();
  Camera camera = scene.getCamera();

  int count = 0;
  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++){

      Ray ray = camera.getRay(x, y, width, height);
      Color color = CastRay(scene, ray, count);
      image.setPixel(x, y, color);

    }
  }
  std::cout << count << " rayons" << std::endl;
}

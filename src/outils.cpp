#include "outils.h"
#include "color.h"
#include "image.h"
#include "scene.h"
#include "vector3.h"
#include "objects/sphere.h"

Color CastRay(const Scene &scene, Ray &ray){
  Object* hitObject = nullptr;
  float tMin;

  if (scene.intersect(ray, tMin, hitObject)){
    Vector3 hitPoint = ray.at(tMin); // Calcul du point d'impact

    Color kd, ks;
    float shininess;

    hitObject->getMaterialProperties(hitPoint, kd, ks, shininess);
    return kd; // Pour l'instant on ne prends que la lumiere diffuse
  }

  return Color(220, 220, 220); // Fond noir
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

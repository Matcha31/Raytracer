#include "outils.h"
#include "color.h"
#include "vector3.h"
#include "objects/sphere.h"

void CastRay(Scene &scene, Ray &ray, Image &img, int x, int y){
  float t_min;
  Object* hitObject = nullptr;
  Color finalColor = Color(0, 0, 0);
  if (scene.intersect(ray, t_min, hitObject)) {
    Vector3 hitPoint = ray.at(t_min);
    Vector3 normal = hitObject->getNormal(hitPoint);
    Color col1, col2;
    float shininess;
    hitObject->getTextureAt(hitPoint, col1, col2, shininess);
    finalColor = col1 * col2 * std::pow(std::max(0.0f, normal.dot(ray.direction)), shininess);
    finalColor = finalColor.clamp();
    img.setPixel(x, y, finalColor);
  } else {
    img.setPixel(x, y, Color(0.2, 0.2, 0.2));
  }
}

#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "../uniform_texture.h"

class Sphere : public Object {
  private:
    float radius;
  public:
    Vector3 center; // tmp
    Sphere(const Vector3& center, float radius, UniformTexture* texture) : Object(texture), center(center), radius(radius) {}

    Sphere(const Vector3& center, float radius, const Color& color) : Object(), center(center), radius(radius) {
      textureMaterial = new UniformTexture(color, color, 0.0f);
    }

    bool intersect(const Ray& ray, float& t) const override {
      // Calculer la distance entre le centre de la sphère et le point d'intersection du rayon

      Vector3 oc = center - ray.getOrigin();
      Vector3 dir = ray.getDirection();

      float a = dir.dot(dir);
      float b = 2 * oc.dot(dir);
      float c = oc.dot(oc) - radius * radius;

      float discriminant = b * b - 4 * a * c;

      if (discriminant < 0) {
        return false;
      } else {
        float sqrtDiscriminant = sqrt(discriminant);
        float t1 = (-b - sqrtDiscriminant) / (2 * a);
        float t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 > 0) {
          t = t1;
        } else if (t2 > 0) {
          t = t2;
        } else {
          return false;
        }
        return true;
      }
    }

    Vector3 getNormal(const Vector3& point) const override {
      return Vector3(point.x - center.x, point.y - center.y, point.z - center.z).normalize();
    }

    void getMaterialProperties(const Vector3& position, Color &kd, Color &ks, float &shininess) override {
      if(textureMaterial == nullptr){
        std::cout << "No texture" << std::endl;
        std::exit(1);
      }
      textureMaterial->getProperties(position, kd, ks, shininess);
    }

};

#endif // SPHERE_H

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

    bool intersect(const Ray& ray, HitRecord& record) const override {
      // Calculer la distance entre le centre de la sphère et le point d'intersection du rayon

      Vector3 oc = ray.getOrigin() - center;
      Vector3 dir = ray.getDirection();

      float a = dir.length_squared();
      float h = oc.dot(dir);
      float c = oc.length_squared() - radius * radius;

      float discriminant = h * h - a * c;

      if (discriminant < 0) {
        return false;
      }
      float sqrtdt = sqrt(discriminant);
      float root = (-h - sqrtdt) / a;
      if (root < ray.getTMin() || root > ray.getTMax()) {
        root = (-h + sqrtdt) / a;
        if (root < ray.getTMin() || root > ray.getTMax()) {
          return false;
        }
      }

      record.t = root;
      record.point = ray.at(record.t);
      Vector3 outwardNormal = (record.point - center).normalize();
      record.setFaceNormal(ray, outwardNormal);

      return true;
    }

    Vector3 getNormal(const Vector3& point) const override {
      return (point - center).normalize();
    }

    void getMaterialProperties(const Vector3& position, Color &kd, Color &ks, float &shininess) override {
      if(textureMaterial == nullptr){
        std::cout << "No texture" << std::endl;
        std::exit(1);
      }
      textureMaterial->getProperties(position, kd, ks, shininess);
    }

    const Vector3 getCenter() const override {
      return center;
    }

};

#endif // SPHERE_H

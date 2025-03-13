#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "../textures/uniform_texture.h"

class Sphere : public Object {
  private:
    float radius;
  public:
    Sphere(const Vector3& center, float radius, Texture *texture) : Object(texture, center), radius(radius) {}

    bool intersect(const Ray& ray, HitRecord& record) const override {
      // Calculer la distance entre le centre de la sphère et le point d'intersection du rayon

      Vector3 oc = ray.getOrigin() - center;
      Vector3 dir = ray.getDirection();

      float a = dir.lengthSquared();
      float h = oc.dot(dir);
      float c = oc.lengthSquared() - radius * radius;

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

    const Vector3 getCenter() const override {
      return center;
    }

};

#endif // SPHERE_H

#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "../texture_material.h"
#include <cmath>

class Plane : public Object {
  private:
    Vector3 normal;
    // Distance depuis l'origine
    float d;

  public:
    Plane(const Vector3 &normal, float d, TextureMaterial *texture) : Object(texture), normal(normal.normalize()), d(d) {}

    bool intersect(const Ray &ray, HitRecord &record) const override {
      float denom = normal.dot(ray.getDirection());
      if (std::fabs(denom) > 1e-6) {
        float t = -(normal.dot(ray.getOrigin()) + d) / denom;
        if (t >= ray.getTMin() && t <= ray.getTMax()) {
          record.t = t;
          record.point = ray.at(record.t);
          record.setFaceNormal(ray, normal);
          return true;
        }
        return false;
      }
      return false;
    }

    Vector3 getNormal(const Vector3 &hitPoint) const override {
      return normal;
    }

    const Vector3 getCenter() const override {
      return Vector3(0, 0, 0);
    }
};

#endif // PLANE_H

#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "../textures/texture.h"
#include <cmath>

class Plane : public Object {
  private:
    Vector3 normal;
    float distanceFromOrigin;

  public:
    Plane(const Vector3 &center, std::shared_ptr<Material> material, const Vector3 &normal) : Object(center, material) {
      this->normal = normal.normalize();
      this->distanceFromOrigin = -center.dot(normal);
    }

    bool intersect(const Ray &ray, HitRecord &record) const override {
      float denom = normal.dot(ray.getDirection());

      if (std::fabs(denom) > 1e-6) {
        float t = -(ray.getOrigin().dot(normal) + distanceFromOrigin) / denom;
        if (t >= ray.getTMin() && t <= ray.getTMax()) {
          record.t = t;
          record.point = ray.at(t);
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
};

#endif // PLANE_H

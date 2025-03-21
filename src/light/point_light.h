#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

class PointLight : public Light {
  protected:
    Vector3 position;
public:

  PointLight(const Vector3& position, const Color& intensity) : Light(intensity), position(position) {}

  Color getIntensity(const Vector3& position) const override {
    float distanceSquared = this->getDirection(position).lengthSquared();
    return intensity / distanceSquared;
  }

  Vector3 getPosition() const override {
    return position;
  }

  Vector3 getDirection(const Vector3& position) const override {
    return (this->position - position).normalize();
  }

  bool isPointLight() const override {
    return true;
  }

  Vector3 getJitteredPosition(const Vector3 hitPoint) const override {
    Vector3 jitteredLightPosition = position + Vector3::randomInUnitSphere() * 0.5f;
    return (jitteredLightPosition - hitPoint).normalize();
  }

};

#endif // POINT_LIGHT_H

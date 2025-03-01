#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

class PointLight : public Light {
  protected:
    Vector3 position;
public:

  PointLight(const Vector3& position, const Color& intensity) : Light(intensity), position(position) {}

  Color getIntensity(const Vector3& position) const override {
    float distanceSquared = (this->position - position).length_squared();
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

};

#endif // POINT_LIGHT_H

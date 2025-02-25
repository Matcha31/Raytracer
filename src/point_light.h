#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "color.h"
#include "light.h"

class PointLight : public Light {
public:
  Vector3 position;
  Color intensity;

  PointLight(const Vector3& position, const Color& intensity) : Light(), position(position), intensity(intensity) {}

  Color getIntensity(const Vector3& position) const override {
    return intensity;
  }

  Vector3 getPosition() const override {
    return position;
  }

  Vector3 getDirection(const Vector3& position) const override {
    return (position - this->position).normalize();
  }

};

#endif // POINT_LIGHT_H

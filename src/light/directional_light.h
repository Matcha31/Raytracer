#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DirectionalLight : public Light {
  protected:
    Vector3 direction;

  public:

    DirectionalLight(const Vector3& direction, const Color& intensity) : Light(intensity), direction(direction.normalize()) {}

    Color getIntensity(const Vector3& position) const override {
      return intensity;
    }

    Vector3 getDirection(const Vector3& position) const override {
      return direction;
    }

    Vector3 getPosition() const override {
      return Vector3(0, 0, 0);
    }

  bool isDirectionalLight() const override {
    return true;
  }

  Vector3 getJitteredPosition(const Vector3 hitPoint) const override {
    return (getDirection(hitPoint) + Vector3::randomInUnitSphere() * 0.1f).normalize();
  }

};

#endif // DIRECTIONAL_LIGHT_H

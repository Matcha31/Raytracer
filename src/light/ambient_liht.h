#ifndef AMBIENT_LIGHT_H
#define AMBIENT_LIGHT_H

#include "light.h"

class AmbientLight : public Light {
  public:

    AmbientLight(const Color& intensity) : Light(intensity) {}

    Vector3 getPosition() const override { return Vector3(0.0, 0.0, 0.0); }

    Vector3 getDirection(const Vector3& position) const override {
      return Vector3(0.0, 0.0, 0.0);
    }

    Color getIntensity(const Vector3& position) const override {
      return intensity;
    }

    bool isAmbientLight() const override { return true; }
};

#endif // AMBIENT_LIGHT_H

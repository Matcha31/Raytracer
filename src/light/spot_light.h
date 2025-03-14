#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light {
  private:
    Vector3 position;
    Color intensity;
    float cutOffAngle;

  public:

    SpotLight(const Vector3& position, const Color& intensity, float cutOffAngle) : Light(intensity), position(position), intensity(intensity), cutOffAngle(cutOffAngle) {}

    Vector3 getPosition() const override { return position; }

    Vector3 getDirection(const Vector3& position) const override {
      return (this->position - position).normalize();
    }

    Color getIntensity(const Vector3& position) const override {
      return intensity;
      Vector3 lightDirection = this->getDirection(position);
      float angle = std::acos(lightDirection.dot(this->getDirection(position)));

      if (angle < cutOffAngle) {
        return intensity;
      }

      return Color(0.0, 0.0, 0.0);
    }

    bool isSpotLight() const override { return true; }

    Vector3 getJitteredPosition(const Vector3 hitPoint) const override {
      return (getDirection(hitPoint) + Vector3::randomInUnitSphere() * 0.1f).normalize();
    }
};

#endif // SPOT_LIGHT_H

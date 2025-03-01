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
      return (position - this->position).normalize();
    }

    Color getIntensity(const Vector3& position) const override {
      Vector3 lightDirection = (position - this->position).normalize();
      float angle = std::acos(lightDirection.dot(this->getDirection(position)));

      if (angle < cutOffAngle) {
        return intensity;
      }

      return Color(0.0, 0.0, 0.0);
    }

    bool isSpotLight() const override { return true; }
};

#endif // SPOT_LIGHT_H

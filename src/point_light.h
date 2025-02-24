#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "color.h"
#include "light.h"
#include "point3.h"

class PointLight : public Light {
public:
  Point3 position;
  Color intensity;

  PointLight(const Point3& position, const Color& intensity) : Light(), position(position), intensity(intensity) {}

  Color getIntensity(const Point3& position) const override {
    return intensity;
  }

  Vector3 getDirection(const Point3& position) const override {
    return (position - this->position).normalize();
  }

};

#endif // POINT_LIGHT_H

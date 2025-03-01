#ifndef LIGHT_H
#define LIGHT_H

#include "../vector3.h"
#include "../color.h"

class Light {
  protected:
    Color intensity;

  public:

    Light(const Color& intensity) : intensity(intensity) {}
    virtual ~Light() = default;

    virtual Color getIntensity(const Vector3& position) const = 0;
    virtual Vector3 getDirection(const Vector3& position) const = 0; 
    virtual Vector3 getPosition() const = 0;

    virtual bool isPointLight() const { return false; }
    virtual bool isDirectionalLight() const { return false; }
    virtual bool isSpotLight() const { return false; }
    virtual bool isAmbientLight() const { return false; }
};

#endif // LIGHT_H

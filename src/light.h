#ifndef LIGHT_H
#define LIGHT_H

#include "vector3.h"
#include "color.h"

class Light {
public:
    Vector3 position;
    Color intensity;

    virtual ~Light() = default;

    virtual Color getIntensity(const Vector3& position) const = 0;
    virtual Vector3 getDirection(const Vector3& position) const = 0;
    virtual Vector3 getPosition() const = 0;

};

#endif // LIGHT_H

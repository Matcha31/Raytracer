#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
public:
    Vector3 origin, direction;

    Ray(const Vector3& origin, const Vector3& direction)
        : origin(origin), direction(direction.normalize()) {}

    // Point à t sur le rayon
    Vector3 at(float t) const {
        return origin + direction * t;
    }
};

#endif // RAY_H


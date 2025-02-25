#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
private:
    Vector3 origin, direction;
public:
    Ray(const Vector3& origin, const Vector3& direction)
        : origin(origin), direction(direction.normalize()) {}

    // Direction du rayon
    Vector3 getDirection() const {
        return direction;
    }

    // Point d'origine du rayon
    Vector3 getOrigin() const {
        return origin;
    }

    // Point à t sur le rayon
    Vector3 at(float t) const {
        return origin + direction * t;
    }

    // Verification des ombrages
    Ray shadowRay(const Vector3& point, const Vector3& normal) const {
        return Ray(point + normal * 0.001f, normal);
    }

};

#endif // RAY_H

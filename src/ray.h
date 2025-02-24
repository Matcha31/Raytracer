#ifndef RAY_H
#define RAY_H

#include "vector3.h"
#include "point3.h"

class Ray {
public:
    Vector3 origin, direction;

    Ray(const Vector3& origin, const Vector3& direction)
        : origin(origin), direction(direction.normalize()) {}

    // Point à t sur le rayon
    Vector3 at(float t) const {
        return origin + direction * t;
    }

    // Verification des ombrages
    Ray shadowRay(const Point3& point, const Vector3& normal) const {
        return Ray(point + normal * 0.001f, normal);
    }

};

#endif // RAY_H


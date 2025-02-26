#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
private:
    Vector3 origin, direction;
    static constexpr float tMin = 0.001f;
    static constexpr float tMax = 10000.0f;
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

    // T minimum
    float getTMin() const {
        return tMin;
    }

    // T maximum
    float getTMax() const {
        return tMax;
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

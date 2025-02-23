#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

class Sphere : public Object {
public:
    Vector3 center;
    float radius;

    Sphere(Vector3 c, float r, Color col) : Object(col), center(c), radius(r) {}

    bool intersect(const Ray& ray, float& t) const override {
        // Calculer la distance entre le centre de la sphère et le point d'intersection du rayon
        Vector3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0 * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        // Pas d'intersection
        if (discriminant < 0) return false;

        t = (-b - sqrt(discriminant)) / (2.0 * a);
        return (t > 0);
    }
};

#endif // SPHERE_H

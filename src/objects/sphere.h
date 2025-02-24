#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "../uniform_texture.h"

class Sphere : public Object {
public:
    Vector3 center;
    float radius;

    Sphere(const Vector3& center, float radius, const Color& color) : Object(), center(center), radius(radius) {
        textureMaterial = new UniformTexture(color, color, 0.0f);
    }

    bool intersect(const Ray& ray, float& t) const override {
        // Calculer la distance entre le centre de la sphère et le point d'intersection du rayon
        Vector3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0 * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        // Pas d'intersection
        if (discriminant < 0) return false;

        // Calculer les intersections
        float t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        float t2 = (-b + sqrt(discriminant)) / (2.0 * a);
        
        if (t1 > 0 ) {
            t = t1;
            return true;
        } if (t2 > 0) {
            t = t2;
            return true;
        }
        return false;
    }

    Vector3 getNormal(const Vector3& point) const override {
        return (point - center).normalize();
    }

    void getMaterialProperties(const Vector3& position, Color &kd, Color &ks, float &shininess) override {
        textureMaterial->getProperties(position, kd, ks, shininess);
    }

};

#endif // SPHERE_H

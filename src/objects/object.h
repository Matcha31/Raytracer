#ifndef OBJECT_H
#define OBJECT_H

#include "../ray.h"
#include "../color.h"

class Object {
public:
    Color color;
    
    Object(const Color& c) : color(c) {}

    // Intersecter le rayon avec l'objet
    virtual bool intersect(const Ray& ray, float& t) const = 0;
};

#endif // OBJECT_H

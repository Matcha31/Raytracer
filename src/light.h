#ifndef LIGHT_H
#define LIGHT_H

#include "vector3.h"
#include "color.h"

class Light {
public:
    Vector3 position;
    Color intensity;

    Light(Vector3 pos, Color inten) : position(pos), intensity(inten) {}
};

#endif // LIGHT_H

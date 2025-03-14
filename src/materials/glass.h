#ifndef GLASS_H
#define GLASS_H

#include "material.h"

class Glass : public Material {
public:

  Glass(std::shared_ptr<Texture> texture) : Material(texture) {
    this->kd = 0.6f;
    this->ks = 0.5f;
    this->ka = 0.05f;
    this->shininess = 100.0f;
    this->transparency = 0.9f;
    this->reflectivity = 0.1f;
    this->refractionIndex = 1.5f;
  }
};

#endif // GLASS_H

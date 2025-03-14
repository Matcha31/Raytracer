#ifndef BASE_MATERIAL_H
#define BASE_MATERIAL_H

#include "../color.h"
#include "../textures/texture.h"
#include "material.h"
#include <memory>

class BaseMaterial : public Material {
  public:

    BaseMaterial(std::shared_ptr<Texture> texture, float kd, float ks, float ka, float shininess) : Material(std::move(texture)) {
      this->kd = kd;
      this->ks = ks;
      this->ka = ka;
      this->shininess = shininess;
      this->transparency = 0.0f;
      this->reflectivity = 0.0f;
      this->refractionIndex = 1.0f;
    }
};
#endif // BASE_MATERIAL_H

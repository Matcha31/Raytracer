#ifndef UNIFORM_TEXTURE_H
#define UNIFORM_TEXTURE_H

#include "texture_material.h"

class UniformTexture : public TextureMaterial {
private:
  Color kd, ks;
  float shininess;

public:
  UniformTexture(Color kd, Color ks, float shininess) : kd(kd), ks(ks), shininess(shininess) {}
  
  void getProperties(const Vector3& position, Color &kd, Color &ks, float &shininess) const override {
    kd = this->kd;
    ks = this->ks;
    shininess = this->shininess;
  }
};


#endif // UNIFORM_TEXTURE_H

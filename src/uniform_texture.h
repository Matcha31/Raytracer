#ifndef UNIFORM_TEXTURE_H
#define UNIFORM_TEXTURE_H

#include "texture_material.h"

class UniformTexture : public TextureMaterial {
private:
  Color kd, ks;
  float shininess, reflectivity;
  static constexpr float ka = 0.2f;
  // static constexpr float shininess = 50.0f;
  // static constexpr float reflectivity = 1.0f;

public:
  UniformTexture(Color kd, Color ks, float shininess, float reflectivity) : shininess(shininess), reflectivity(reflectivity), kd(kd), ks(ks) {}
  
  void getProperties(const Vector3& position, Color &kd, Color &ks, float &ka, float &shininess, float &reflectivity) const override {
    kd = this->kd;
    ks = this->ks;
    ka = this->ka;
    shininess = this->shininess;
    reflectivity = this->reflectivity;
  }
};


#endif // UNIFORM_TEXTURE_H

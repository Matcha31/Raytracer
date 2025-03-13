#ifndef MATERIAL_H
#define MATERIAL_H

#include "../color.h"
#include "../textures/texture.h"

class Material {
protected:
  Color kd, ks;
  float ka;
  float shininess;
  float reflectivity;
  float refractionIndex;
  Texture* texture;

public:
  virtual ~Material() = default;
};

#endif // MATERIAL_H

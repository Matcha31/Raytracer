#ifndef TEXTURE_MATERIAL_H
#define TEXTURE_MATERIAL_H

#include "vector3.h"
#include "color.h"

class TextureMaterial {
protected:
  Color kd, ks;
  float ka;
  float shininess;
  float reflectivity;

public:

  virtual ~TextureMaterial() = default;

  virtual void getProperties(const Vector3& position, Color &kd, Color &ks, float &ka, float &shininess, float &reflectivity) const = 0;
};

#endif // TEXTURE_MATERIAL_H

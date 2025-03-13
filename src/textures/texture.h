#ifndef TEXTURE_H
#define TEXTURE_H

#include "../vector3.h"
#include "../color.h"

class Texture {
protected:
  Color kd, ks;
  float ka;
  float shininess;
  float reflectivity;

public:

  virtual ~Texture() = default;

  virtual void getProperties(const Vector3& position, Color &kd, Color &ks, float &ka, float &shininess, float &reflectivity) const = 0;
};

#endif // TEXTURE_H

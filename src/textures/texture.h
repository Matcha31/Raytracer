#ifndef TEXTURE_H
#define TEXTURE_H

#include "../vector3.h"
#include "../color.h"

class Texture {

public:

  virtual ~Texture() = default;

  virtual Color getTextureAt(const Vector3& hitPoint) const = 0;
};

#endif // TEXTURE_H

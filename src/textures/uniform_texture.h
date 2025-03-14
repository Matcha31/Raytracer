#ifndef UNIFORM_TEXTURE_H
#define UNIFORM_TEXTURE_H

#include "texture.h"

class UniformTexture : public Texture {
private:
  Color kd;

public:

  explicit UniformTexture(const Color& kd) : kd(kd) {}

  Color getTextureAt(const Vector3& hitPoint) const {
    return kd;
  }
};


#endif // UNIFORM_TEXTURE_H

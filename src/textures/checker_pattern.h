#ifndef CHECKER_PATTERN_H
#define CHECKER_PATTERN_H

#include "texture.h"

class CheckerPattern : public Texture {
  private:
    Color color1, color2;
    float scale;
public:

  CheckerPattern(Color color1, Color color2, float scale) : color1(color1), color2(color2), scale(scale) {}

  Color getTextureAt(const Vector3& hitPoint) const {
    int check = (int)(hitPoint.x * scale) + (int)(hitPoint.y * scale) + (int)(hitPoint.z * scale);
    if (check % 2 == 0) {
      return color1;
    } else {
      return color2;
    }
  }
  
};

#endif // CHECKER_PATTERN_H

#ifndef CUBE_MAP_H
#define CUBE_MAP_H

#include "image.h"
#include "vector3.h"

class CubeMap {
  private:
public:
  Image faces[6];
  CubeMap(const std::string& path);

  bool loadCubeMap(const std::string& path);
  Color getPixel(const Vector3& direction) const;
};

#endif // CUBE_MAP_H

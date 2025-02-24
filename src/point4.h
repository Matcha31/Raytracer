#ifndef POINT4_H
#define POINT4_H

#include "vector3.h"
#include "vector4.h"
#include "point3.h"

class Point4 {
public:
  float x, y, z, w;

  Point4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f) : x(x), y(y), z(z), w(w) {}

  Point3 toPoint3() const {
    return Point3(x, y, z);
  }

  Point4 operator+(const Vector4& other) const {
    return Point4(x + other.x, y + other.y, z + other.z, w + other.w);
  }
   Point4 operator-(const Vector4& other) const {
    return Point4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  Vector4 operator-(const Point4& other) const {
    return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point4& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ", " << p.w << ")";
    return os;
  }

};

#endif // POINT4_H

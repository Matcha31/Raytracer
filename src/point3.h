#ifndef POINT3_H
#define POINT3_H

#include <iostream>
#include <cmath>

#include "vector3.h"

class Point3 : public Vector3 {
public:
  float x, y, z;
  
  Point3 () : x(0), y(0), z(0) {};
  Point3 (float x, float y, float z) : x(x), y(y), z(z) {};
  
  // Opérateurs
  Point3 operator+(const Vector3& p) const { return Point3(x + p.x, y + p.y, z + p.z); }
  Point3 operator-(const Vector3& p) const { return Point3(x - p.x, y - p.y, z - p.z); }

  Vector3 operator-(const Point3& p) const { return Vector3(x - p.x, y - p.y, z - p.z); }
  
  // Affichage pour le debug
  friend std::ostream& operator<<(std::ostream& out, const Point3& p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
  }
};

#endif // POINT3_H

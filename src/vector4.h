#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <cmath>

class Vector4 {
public:
  float x, y, z, w;

  Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
  Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f) : x(x), y(y), z(z), w(w) {}

  Vector4 operator+(const Vector4& other) const {
    return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  Vector4 operator-(const Vector4& other) const {
    return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
  }

  Vector4 operator*(float scalar) const {
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
  }
   Vector4 operator/(float scalar) const {
    return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
  }

  float dot(const Vector4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
  }

  Vector4 normalize() const {
    float length = std::sqrt(x * x + y * y + z * z + w * w);
    return Vector4(x / length, y / length, z / length, w / length);
  }

  friend std::ostream& operator<<(std::ostream& os, const Vector4& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
  }

};

#endif // VECTOR4_H

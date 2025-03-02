#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3 {
  public:
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Opérations vectorielles
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator/(float s) const { return Vector3(x / s, y / s, z / s); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }

    float operator[](int i) const { return *(&x + i); }
    float& operator[](int i) { return *(&x + i); }

    bool operator==(const Vector3& v) const {
      return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vector3& v) const {
      return !(*this == v);
    }


    // Longueur
    float length() const { return std::sqrt(x * x + y * y + z * z); }

    // Longueur carre
    float lengthSquared() const { return x * x + y * y + z * z; }

    // Produit scalaire et produit vectoriel
    float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vector3 cross(const Vector3& v) const { 
      return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    // Vectuer unitaire
    Vector3 unitVector() const { return (*this) / length(); }

    // Normalisation
    Vector3 normalize() const {
      float norm = std::sqrt(x * x + y * y + z * z);
      return (*this) / norm;
    }

    // Générer un vecteur aléatoire dans une sphère unité
    static Vector3 randomInUnitSphere() {
      Vector3 p;
      do {
        p = Vector3(drand48(), drand48(), drand48()) * 2.0f - Vector3(1.0f, 1.0f, 1.0f); // [-1, 1]
      } while (p.lengthSquared() >= 1.0f); // Assurez-vous que le vecteur est dans la sphère
      return p;
    }

    // Calcul de la réflexion d'un vecteur sur une surface
    static Vector3 reflect(const Vector3& v, const Vector3& normal) {
      return v - normal * (2.0f * v.dot(normal));
    }

    // Calcul de la réfraction (loi de Snell)
    static Vector3 refract(const Vector3& v, const Vector3& normal, float eta) {
      float cos_theta = std::min(v.dot(normal), 1.0f);
      Vector3 r_out_perp = (v + normal * cos_theta) * eta;
      Vector3 r_out_parallel = normal * -std::sqrt(std::abs(1.0f - r_out_perp.lengthSquared()));
      return r_out_perp + r_out_parallel;
    }

    Vector3 scalar_multiply(const Vector3& v) const {
      return Vector3(x * v.x, y * v.y, z * v.z);
    }

    // Affichage pour le debug
    friend std::ostream& operator<<(std::ostream& out, const Vector3& v) {
      out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
      return out;
    }
};

#endif // VECTOR3_H

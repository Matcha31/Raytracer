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

    // Longueur
    float length() const { return std::sqrt(x * x + y * y + z * z); }

    // Longueur carre
    float length_squared() const { return x * x + y * y + z * z; }

    // Produit scalaire et produit vectoriel
    float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vector3 cross(const Vector3& v) const { 
        return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    // Vectuer unitaire
    Vector3 unit_vector() const { return (*this) / length(); }

    // Normalisation
    Vector3 normalize() const {
        float norm = std::sqrt(x * x + y * y + z * z);
        return (*this) / norm;
    }

    // Affichage pour le debug
    friend std::ostream& operator<<(std::ostream& out, const Vector3& v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }
};

#endif // VECTOR3_H

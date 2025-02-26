#ifndef COLOR_H
#define COLOR_H

#include <algorithm>
#include <iostream>

#define std_clamp(x, m, M) std::max(std::min(x, M), m)

class Color {
public:
    float r, g, b;

    Color() : r(0), g(0), b(0) {}
    Color(float r, float g, float b) : r(r), g(g), b(b) {}

    // Multiplication par un scalaire
    Color operator*(float s) const { return Color(r * s, g * s, b * s); }

    // Multiplication de couleurs
    Color operator*(const Color& c) const { return Color(r * c.r, g * c.g, b * c.b); }

    // Addition de couleurs
    Color operator+(const Color& c) const { return Color(r + c.r, g + c.g, b + c.b); }

    // Normalisation de la couleur (renvoie un vecteur de norme 1)
    Color clamp() const { return Color(std_clamp(r, 0.0f, 1.0f), std_clamp(g, 0.0f, 1.0f), std_clamp(b, 0.0f, 1.0f)); }
    // Affichage pour le debug
    friend std::ostream& operator<<(std::ostream& out, const Color& c) {
        out << "(" << c.r << ", " << c.g << ", " << c.b << ")";
        return out;
    }
};

#endif // COLOR_H


#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
public:
    float r, g, b;

    Color() : r(0), g(0), b(0) {}
    Color(float r, float g, float b) : r(r), g(g), b(b) {}

    // Multiplication par un scalaire
    Color operator*(float s) const { return Color(r * s, g * s, b * s); }

    // Addition de couleurs
    Color operator+(const Color& c) const { return Color(r + c.r, g + c.g, b + c.b); }

    // Affichage
    friend std::ostream& operator<<(std::ostream& out, const Color& c) {
        out << "(" << c.r << ", " << c.g << ", " << c.b << ")";
        return out;
    }
};

#endif // COLOR_H


#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <fstream>
#include "color.h"

class Image {
protected:
  int width, height;
  std::vector<Color> pixels;

public:
    Image(int w, int h) : width(w), height(h), pixels(w * h) {}

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void setPixel(int x, int y, const Color& c) {
        pixels[y * width + x] = c;
    }

    // Enregistre l'image dans un fichier PPM
    void savePPM(const std::string& filename) const {
        std::ofstream file(filename, std::ios::out | std::ios::binary);
        file << "P3\n" << width << " " << height << "\n255\n";
        for (const auto& pixel : pixels) {
            file << static_cast<int>(pixel.r * 255) << " "
                 << static_cast<int>(pixel.g * 255) << " "
                 << static_cast<int>(pixel.b * 255) << "\n";
        }
        file.close();
    }
};

#endif // IMAGE_H

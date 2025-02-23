#include <iostream>
#include "vector3.h"
#include "color.h"
#include "ray.h"
#include "image.h"

int main() {
    std::cout << "Test Vector3: " << Vector3(1, 2, 3) + Vector3(4, 5, 6) << std::endl;

    Image img(200, 100);
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 200; x++) {
            float r = float(x) / 200.0;
            float g = float(y) / 100.0;
            img.setPixel(x, y, Color(r, g, 0.2));
        }
    }
    img.savePPM("output.ppm");
    std::cout << "Image saved as output.ppm" << std::endl;

    return 0;
}


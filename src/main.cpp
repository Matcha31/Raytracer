#include <iostream>
#include "point3.h"
#include "scene.h"
#include "uniform_texture.h"
#include "vector3.h"
#include "color.h"
#include "ray.h"
#include "image.h"
#include "camera.h"
#include "objects/sphere.h"
#include "point_light.h"
#include "outils.h"

int main() {
    // Creation de la camera
    Camera camera = Camera(Point3(0, 0, 0), Point3(0, 0, -1), Vector3(0, 1, 0), M_PI/2, M_PI/2, 0.1);

    // Creation de la scene
    Scene scene = Scene(camera);

    // UniformTexture* redMateriel = new UniformTexture(Color(0.8,0.2,0.2), Color(1.0,1.0,1.0), 50);
    // Sphere* sphere = new Sphere(Point3(0,0,-5), 0.5, redMateriel);
    // scene.addObject(sphere);

    UniformTexture* blueMateriel = new UniformTexture(Color(0.2,0.2,0.8), Color(1.0,1.0,1.0), 50);
    Sphere* sphere2 = new Sphere(Point3(0,0,5), 1, blueMateriel);
    scene.addObject(sphere2);
    
    int width = 800, height = 600;
    Image image = Image(width, height);

    RenderImage(scene, image);
    image.savePPM("output.ppm");

    return 0;
    
}

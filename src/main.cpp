#include <iostream>

#include "uniform_texture.h"
#include "vector3.h"
#include "camera.h"
#include "objects/sphere.h"
#include "point_light.h"
#include "raycasting.h"

int main() {
    // Creation de la camera
    Camera camera = Camera(Vector3(0, 0, 0), Vector3(0, 0, -1), Vector3(0, 1, 0), M_PI/2, M_PI/2, 0.1);
    std::cout << camera.getForward() << std::endl;

    // Creation de la scene
    Scene scene = Scene(camera);

    PointLight* light1 = new PointLight(Vector3(0, 10, 0), Color(1.0, 1.0, 1.0));
    scene.addLight(light1);
    // PointLight* light2 = new PointLight(Vector3(1, 0, 0), Color(1.0, 1.0, 1.0));
    // scene.addLight(light2);


    UniformTexture* redMateriel = new UniformTexture(Color(0.8,0.2,0.2), Color(1.0,1.0,1.0), 50);
    Sphere* sphere = new Sphere(Vector3(0,0,-5), 1, redMateriel);
    scene.addObject(sphere);

    UniformTexture* blueMateriel = new UniformTexture(Color(0.2,0.2,0.8), Color(1.0,1.0,1.0), 50);
    Sphere* sphere2 = new Sphere(Vector3(3,0,-8), 1, blueMateriel);
    scene.addObject(sphere2);
    
    int width = 800, height = 800;
    Image image = Image(width, height);

    RenderImage(scene, image);
    image.savePPM("output.ppm");

    return 0;
    
}

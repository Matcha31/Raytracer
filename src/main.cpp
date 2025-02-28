#include <iostream>

#include "uniform_texture.h"
#include "vector3.h"
#include "camera.h"
#include "objects/sphere.h"
#include "objects/plane.h"
#include "point_light.h"
#include "raycasting.h"

Color ambientLight = Color(0.1, 0.1, 0.1);

int main() {
    // Creation de la camera
    Camera camera = Camera(Vector3(0, 0, 0.5), Vector3(0, 0, -1), Vector3(0, 1, 0), M_PI/2, M_PI/2, 0.1);

    // Creation de la scene
    Scene scene = Scene(camera);

    // PointLight* light1 = new PointLight(Vector3(20, 10, 0), Color(1.0, 1.0, 1.0));
    // scene.addLight(light1);
    PointLight* light2 = new PointLight(Vector3(7, 2, 0), Color(1.0, 1.0, 1.0));
    scene.addLight(light2);

    // Création d'un plan horizontal sous les sphères
    UniformTexture* groundMaterial = new UniformTexture(Color(0.5, 0.5, 0.5), Color(0.2, 0.2, 0.2), 100, 1.0); 
    Plane* ground = new Plane(Vector3(0, 1, 0), 2, groundMaterial);
    scene.addObject(ground);



    // Creation des objets
    UniformTexture* redMateriel = new UniformTexture(Color(0.8,0.2,0.2), Color(1.0,1.0,1.0), 10, 0.5);
    Sphere* sphere = new Sphere(Vector3(0,0,-5), 1.7, redMateriel);
    scene.addObject(sphere);

    UniformTexture* blueMateriel = new UniformTexture(Color(0.2,0.2,0.8), Color(1.0,1.0,1.0), 60, 0.1);
    Sphere* sphere2 = new Sphere(Vector3(5,0,-7), 1, blueMateriel);
    scene.addObject(sphere2);
    
    UniformTexture* greenMateriel = new UniformTexture(Color(0.2,0.8,0.2), Color(1.0,1.0,1.0), 50, 0.7);
    Sphere* sphere3 = new Sphere(Vector3(-2,4,-4), 0.7, greenMateriel);
    scene.addObject(sphere3);

    UniformTexture* pinkMateriel = new UniformTexture(Color(0.8,0.2,0.8), Color(1.0,1.0,1.0), 100, 0.5);    
    Sphere* sphere4 = new Sphere(Vector3(-2.5,2,-4), 0.7, pinkMateriel);
    scene.addObject(sphere4);


    int width = 800, height = 800;
    Image image = Image(width, height);

    RenderImage(scene, image);
    image.savePPM("output.ppm");

    return 0;
    
}

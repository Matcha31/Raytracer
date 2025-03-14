#include <iostream>
#include <memory>

#include "light/ambient_liht.h"
#include "light/directional_light.h"
#include "light/spot_light.h"
#include "materials/base_material.h"
#include "materials/material.h"
#include "textures/uniform_texture.h"
#include "vector3.h"
#include "camera.h"
#include "objects/sphere.h"
#include "objects/plane.h"
#include "light/point_light.h"
#include "raycasting.h"


int main() {
    // Creation de la camera
    Camera camera = Camera(Vector3(0, 1, 2), Vector3(0, 1, -1), Vector3(0, 1, 0), M_PI/2, M_PI/2, 0.1);

    // Creation de la scene
    Scene scene = Scene(camera);

    // Ajout de la lumière
    PointLight* point_light = new PointLight(Vector3(20, 10, 0), Color(1.0, 1.0, 1.0));
    scene.addLight(point_light);
    // DirectionalLight* directional_light = new DirectionalLight(Vector3(3,2,0), Color(1.0, 1.0, 0.8));
    // scene.addLight(directional_light);
    // SpotLight* spot_light = new SpotLight(Vector3(0, 10, 0), Color(1.0, 1.0, 1.0), M_PI/2);
    // scene.addLight(spot_light);
    AmbientLight* ambientLight = new AmbientLight(Color(0.05, 0.05, 0.04));
    scene.addLight(ambientLight);

    // Création d'un plan horizontal sous les sphères
    std::shared_ptr<UniformTexture> groundTexture = std::make_shared<UniformTexture>(Color(0.1, 0.1, 0.1));
    std::shared_ptr<BaseMaterial> groundMaterial = std::make_shared<BaseMaterial>(groundTexture, 0.0, 0.0, 1.0, 1.0);
    Plane* ground = new Plane(Vector3(0, -2, 0), groundMaterial, Vector3(0, 1, 0));
    scene.addObject(ground);


    // UniformTexture* groundMaterial = new UniformTexture(Color(0.2, 0.2, 0.2), Color(1, 1, 1), 100, 0.1);
    // Plane* ground = new Plane(groundMaterial, Vector3(0, -2, 0), Vector3(0, 1, 0));


    // Creation des objets
    // UniformTexture* redMateriel = new UniformTexture(Color(1,0,0), Color(1.0,1.0,1.0), 10, 0.5);
    // Sphere* sphere = new Sphere(Vector3(0,0,-5), 2, redMateriel);
    // scene.addObject(sphere);
    //
    // UniformTexture* blueMateriel = new UniformTexture(Color(0,0,1), Color(1.0,1.0,1.0), 60, 0.1);
    // Sphere* sphere2 = new Sphere(Vector3(5,0,-7), 1, blueMateriel);
    // scene.addObject(sphere2);
    // 
    // UniformTexture* greenMateriel = new UniformTexture(Color(0,1,0), Color(1.0,1.0,1.0), 50, 0.7);
    // Sphere* sphere3 = new Sphere(Vector3(-2,4,-4), 0.7, greenMateriel);
    // scene.addObject(sphere3);
    //
    // UniformTexture* pinkMateriel = new UniformTexture(Color(0.9,0.2,0.7), Color(1.0,1.0,1.0), 100, 0.5);    
    // Sphere* sphere4 = new Sphere(Vector3(-2.5,2,-4), 0.7, pinkMateriel);
    // scene.addObject(sphere4);
    //
    //
    int width = 800, height = 800;
    Image image = Image(width, height);

    RenderImage(scene, image);
    image.savePPM("output.ppm");

    return 0;

}

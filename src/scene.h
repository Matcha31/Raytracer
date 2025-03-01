#ifndef SCENE_H
#define SCENE_H

#include <limits>
#include <vector>
#include "cube_map.h"
#include "light/light.h"
#include "camera.h"
#include "objects/object.h"

class Scene {
  protected:
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Camera camera;
    // Optional cube_map
    CubeMap* cubeMap = nullptr;

  public:
    Scene(const Camera& camera) : camera(camera) {}
    Scene(const Camera& camera, CubeMap* cubeMap) : camera(camera), cubeMap(cubeMap) {}
    Scene(const Camera& camera, const std::string &pathToCubeMap) : camera(camera) {
      cubeMap = new CubeMap(pathToCubeMap); 
    }

    const Object& getObject(int index) const { return *objects[index]; }
    const Light& getLight(int index) const { return *lights[index]; }
    const Camera& getCamera() const { return camera; }
    const std::vector<Light*>& getLights() const { return lights; }
    const std::vector<Object*>& getObjects() const { return objects; }

    // Méthodes pour ajouter des objets et des lumières
    void addLight(Light* light) { lights.push_back(light); }
    void addObject(Object* obj) { objects.push_back(obj); }

    // Teste l'intersection avec tous les objets et retourne l'objet le plus proche
    bool intersect(const Ray& ray, HitRecord& record, Object*& hitObject) const {
      float t_min = std::numeric_limits<float>::max();
      bool hit = false;

      for (Object* obj : objects) {
        HitRecord tmpRecord;
        if (obj->intersect(ray, tmpRecord) && tmpRecord.t < t_min) {
          t_min = tmpRecord.t;
          record = tmpRecord;
          hitObject = obj;
          hit = true;
        }
      }
      return hit;
    }

    CubeMap* getCubeMap() const { return cubeMap; }

};

#endif // SCENE_H

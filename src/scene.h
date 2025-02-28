#ifndef SCENE_H
#define SCENE_H

#include <limits>
#include <vector>
#include "light.h"
#include "camera.h"
#include "objects/object.h"

class Scene {
  protected:
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Camera camera;

  public:
    // Constructeur avec une caméra
    Scene(const Camera& camera) : camera(camera) {}

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
      HitRecord tmpRecord;
      bool hit = false;

      for (Object* obj : objects) {
        if (obj->intersect(ray, tmpRecord) && tmpRecord.t < t_min) {
          t_min = tmpRecord.t;
          record = tmpRecord;
          hitObject = obj;
          hit = true;
        }
      }
      return hit;
    }


};

#endif // SCENE_H

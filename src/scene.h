#ifndef SCENE_H
#define SCENE_H

#include <limits>
#include <vector>
#include "light.h"
#include "objects/object.h"

class Scene {
public:
    std::vector<Object*> objects;
    std::vector<Light*> lights;


    void addLight(Light* light) {
        objects.push_back(light);
    }

    void addObject(Object* obj) {
        objects.push_back(obj);
    }

    // Teste l'intersection avec tous les objets et retourne l'objet le plus proche
    bool intersect(const Ray& ray, float& t_min, Object*& hitObject) const {
        t_min = std::numeric_limits<float>::max();
        bool hit = false;
        for (auto obj : objects) {
            float t;
            if (obj->intersect(ray, t) && t < t_min) {
                t_min = t;
                hitObject = obj;
                hit = true;
            }
        }
        return hit;
    }

};

#endif // SCENE_H

#ifndef OBJECT_H
#define OBJECT_H

#include "../color.h"
#include "../light.h"
#include "../ray.h"
#include "../texture_material.h"

class Object {
protected:
    TextureMaterial* textureMaterial;

public:

    Object(TextureMaterial* textureMaterial = nullptr) : textureMaterial(textureMaterial) {}
    virtual ~Object() = default;
    
    // Intersecter le rayon avec l'objet
    virtual bool intersect(const Ray& ray, float& t) const = 0;

    // Récupérer la normale
    virtual Vector3 getNormal(const Vector3& point) const = 0;

    // Récupérer les propriétés du matériau
    virtual void getMaterialProperties(const Vector3& position, Color &kd, Color &ks, float &shininess){
        if(textureMaterial != nullptr){
            textureMaterial->getProperties(position, kd, ks, shininess);
        }
    }

    virtual void getTextureAt(const Vector3& position, Color &kd, Color &ks, float &shininess) const {
        textureMaterial->getProperties(position, kd, ks, shininess);
    }
};

#endif // OBJECT_H

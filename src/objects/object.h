#ifndef OBJECT_H
#define OBJECT_H

#include "../color.h"
#include "../light/light.h"
#include "../ray.h"
#include "../textures/texture.h"

class HitRecord {
  public:
    Vector3 point;
    Vector3 normal;
    float t;
    bool frontFace;

    void setFaceNormal(const Ray& ray, const Vector3& outwardNormal) {
      // Determine si le point est devant le rayon
      frontFace = ray.getDirection().dot(outwardNormal) < 0;
      normal = frontFace ? outwardNormal : outwardNormal * -1.0f;
    }
};

class Object {
protected:
    Vector3 center;
    Texture* texture;

public:
    Object(Texture* texture = nullptr, const Vector3& center = Vector3(0, 0, 0)) : texture(texture), center(center) {}
    virtual ~Object() = default;
    
    // Intersecter le rayon avec l'objet
    virtual bool intersect(const Ray& ray, HitRecord& record) const = 0;

    // Récupérer la normale
    virtual Vector3 getNormal(const Vector3& point) const = 0;

    virtual const Vector3 getCenter() const = 0;

    // Récupérer les propriétés du matériau
    void getTextureAt(const Vector3& position, Color &kd, Color &ks, float &ka, float &shininess, float &reflectivity) const {
        texture->getProperties(position, kd, ks, ka, shininess, reflectivity);
    }
};

#endif // OBJECT_H

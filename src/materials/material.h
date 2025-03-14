#ifndef MATERIAL_H
#define MATERIAL_H

#include "../color.h"
#include "../textures/texture.h"
#include <memory>

class Material {
protected:
  std::shared_ptr<Texture> texture; // Texture de la surface
  float kd;                         // Coefficient de reflexion diffuse
  float ks;                         // Coefficient de reflexion speculaire
  float ka;                         // Coefficient de reflexion ambiante
  float shininess;                  // Brillance
  float transparency;               // Transparence
  float reflectivity;               // Reflexion
  float refractionIndex;            // Indice de refraction

public:
  explicit Material (std::shared_ptr<Texture> texture) : texture(texture) {}
  virtual ~Material() = default;

  // Getters
  float getKd() const { return kd; }
  float getKs() const { return ks; }
  float getKa() const { return ka; }
  float getShininess() const { return shininess; }
  float getTransparency() const { return transparency; }
  float getReflectivity() const { return reflectivity; }
  float getRefractionIndex() const { return refractionIndex; }
  std::shared_ptr<Texture> getTexture() const { return texture; }

  void getProperties(float& kd, float& ks, float& ka, float& shininess, float& transparency, float& reflectivity, float& refractionIndex) const {
    kd = this->kd;
    ks = this->ks;
    ka = this->ka;
    shininess = this->shininess;
    transparency = this->transparency;
    reflectivity = this->reflectivity;
    refractionIndex = this->refractionIndex;
  }

  Color getTextureAt(const Vector3& hitPoint) const {
    return texture->getTextureAt(hitPoint);    
  };
};

#endif // MATERIAL_H

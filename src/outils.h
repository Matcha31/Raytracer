#ifndef OUTILS_H
#define OUTILS_H

#include "image.h"
#include "color.h"
#include "ray.h"
#include "scene.h"
#include "camera.h"

Color CastRay(Scene &scene, Ray &ray, int count);
void RenderImage(const Scene& scene, Image& image);

#endif

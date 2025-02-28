#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "image.h"
#include "color.h"
#include "ray.h"
#include "scene.h"

Color CastRay(Scene &scene, Ray &ray, int depth);
void RenderImage(const Scene& scene, Image& image);

#endif // RAYCASTING_H

#ifndef OUTILS_H
#define OUTILS_H

#include "image.h"
#include "point3.h"
#include "color.h"
#include "ray.h"
#include "scene.h"
#include "camera.h"

Color CastRay(Scene &scene, Ray &ray, Image &img, int x, int y);
void RenderImage(const Scene& scene, Image& image);

#endif

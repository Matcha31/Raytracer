#ifndef OUTILS_H
#define OUTILS_H

#include "image.h"
#include "point3.h"
#include "color.h"
#include "ray.h"
#include "scene.h"
#include "camera.h"

void CastRay(Scene &scene, Ray &ray, Image &img, int x, int y);

#endif

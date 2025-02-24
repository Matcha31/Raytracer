#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include "point3.h"
#include "ray.h"

class Camera {
public:
    Point3 position, target;
    Vector3  up, forward, right, upVector;
    float fovx, fovy, zmin;

    Camera(const Point3& position, const Point3& target, const Vector3& upVector, float fovx, float fovy) : position(position), target(target), upVector(upVector), fovx(fovx), fovy(fovy) {
        forward = (target - position).normalize();
        right = forward.cross(upVector).normalize();
        up = right.cross(forward).normalize();
    }

    Ray getRay(float x, float y, int width, int height) const {
        float aspectRation = static_cast<float>(width) / static_cast<float>(height);
        float px = (2 * (x + 0.5) / width - 1) * tan(fovx / 2) * aspectRation;
        float py = (1 - 2 * (y + 0.5) / height) * tan(fovy / 2);

        Vector3 direction = (forward + right * px + up * py).normalize();
        return Ray(position, direction);
    }

};

#endif // CAMERA_H


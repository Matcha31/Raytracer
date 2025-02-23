#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include "ray.h"

class Camera {
public:
    Vector3 position, lookAt, up;
    float fov, aspectRatio;

    Camera(Vector3 pos, Vector3 lookAt, Vector3 up, float fov, float aspectRatio)
        : position(pos), lookAt(lookAt), up(up), fov(fov), aspectRatio(aspectRatio) {}

    // Retourne un rayon dans la camera
    Ray getRay(float u, float v) const {
        Vector3 forward = (lookAt - position).normalize();
        Vector3 right = forward.cross(up).normalize();
        Vector3 upCorrected = right.cross(forward);

        float scale = tan(fov * 0.5);
        Vector3 direction = forward + right * ((2 * u - 1) * aspectRatio * scale) + upCorrected * ((1 - 2 * v) * scale);
        return Ray(position, direction.normalize());
    }
};

#endif // CAMERA_H


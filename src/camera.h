#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include "ray.h"

class Camera {
protected:
    Vector3 position, target;
    Vector3  up, forward, right, upVector;
    float fovx, fovy, zmin;
    
public:
    Camera(const Vector3& position, const Vector3& target, const Vector3& upVector, float fovx, float fovy, float zmin) : position(position), target(target), upVector(upVector), fovx(fovx), fovy(fovy), zmin(zmin){
        forward = (target - position).normalize();
        right = forward.cross(upVector).normalize();
        up = right.cross(forward).normalize();
    }

    Vector3 getPosition() const { return position; }
    Vector3 getForward() const { return forward; }
    Vector3 getRight() const { return right; }
    Vector3 getUp() const { return up; }
    float getFovx() const { return fovx; }
    float getFovy() const { return fovy; }
    
    Ray getRay(float x, float y, int width, int height) const {
        float aspectRation = static_cast<float>(width) / static_cast<float>(height);
        float px = (2 * ((x + 0.5) / width) - 1) * aspectRation * tan(fovx / 2);
        float py = (1 - 2 * ((y + 0.5) / height)) * tan(fovy / 2);

        Vector3 direction = (forward + right * px + up * py).normalize();
        return Ray(position, direction);
    }

};

#endif // CAMERA_H


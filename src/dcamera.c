#include "dcamera.h"

// Camera movement/updates
void DUpdateCamera(DCamera *dCamera, Vector3 target)
{
    //Register mouse delta and mouse position.
    Vector2 mousePositionDelta = {0.0f, 0.0f};
    Vector2 mousePosistion = GetMousePosition();

    mousePositionDelta.x = mousePosistion.x - dCamera->previousMousePosition.x;
    mousePositionDelta.y = mousePosistion.y - dCamera->previousMousePosition.y;

    dCamera->previousMousePosition = mousePosistion;

    // Change camera position
    dCamera->mainCamera.target = target;
    dCamera->mainCamera.position.x = sinf(dCamera->angle.x) * dCamera->targetDistance * cosf(dCamera->angle.y) + dCamera->mainCamera.target.x;
    dCamera->mainCamera.position.y = ((dCamera->angle.y <= 0.0f)? 1 : -1) * sinf(dCamera->angle.y) * dCamera->targetDistance * sinf(dCamera->angle.y) + dCamera->mainCamera.target.y;
    dCamera->mainCamera.position.z = cosf(dCamera->angle.x) * dCamera->targetDistance * cosf(dCamera->angle.y) + dCamera->mainCamera.target.z;

    // Uses mouse to change camera angles
    dCamera->angle.x += (mousePositionDelta.x * -0.005f);
    dCamera->angle.y += (mousePositionDelta.y * -0.005f);
    
    //Slightly changes angle when A or D are pressed. 
    dCamera->angle.x += (IsKeyDown(KEY_A)-IsKeyDown(KEY_D)) * 0.02f;


    // Clamp y angle
    if (dCamera->angle.y > 89.0f * DEG2RAD)
    {
        dCamera->angle.y = 89.0f * DEG2RAD;
    }
    else if (dCamera->angle.y < 10.0f * DEG2RAD)
    {
        dCamera->angle.y = 10.0f * DEG2RAD;
    }
}
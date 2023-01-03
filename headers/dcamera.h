#pragma once
#include "raylib.h"
#include "raymath.h"

typedef struct{
    Camera3D mainCamera;
    float targetDistance;
    Vector2 angle;
    Vector2 previousMousePosition;
} DCamera;

// Camera movement/updates
void DUpdateCamera(DCamera *dCamera, Vector3 target);


//Simple third person controller with raylib.
//Uses a custom camera and player controller. 
//There's no collision, jumping or sprinting this is just basic movement. 
//Everything with a D prefix is from my header files all other functions are from raylib.
#include "raylib.h"
#include <stddef.h>
#include "dlib.h"
#include "player.h"
#include "dcamera.h"


int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Third Person Demo");

    //Init player
    Player player1 = {
        .playerTransform = {0.0f},
        .playerModel = LoadModel("resources/models/robot.glb"),
        .animsCount = 0,
        .animIndex = 0,
        .animCurrentFrame = 0,
        .playerAnimations = LoadModelAnimations("resources/models/robot.glb", &player1.animsCount)
        };

    //Init camera
    DCamera camera = {
        .mainCamera = (Camera3D){
            .position = (Vector3){0.0f, 4.0f, 0.0f},
            .target = player1.playerTransform.translation,
            .up = (Vector3){0.0f, 1.0f, 0.0f},
            .fovy = 69.0f,
            .projection = CAMERA_PERSPECTIVE
        },
        .angle = 0.0f,
        .targetDistance = -15.0f,
        .previousMousePosition = GetMousePosition()
    };

    //Optional
    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {   
        //Update player, camera and animation
        UpdatePlayer(&player1, camera.angle);
        DUpdateCamera(&camera, player1.playerTransform.translation);

        UpdateModelAnimation(player1.playerModel, player1.currentAnimation, player1.animCurrentFrame);
        
        // Draw
        BeginDrawing();
            ClearBackground((Color){150, 150, 150, 0});

            BeginMode3D(camera.mainCamera);
                DrawGrid(20.0f, 1.0f);
                DrawModel(player1.playerModel, player1.playerTransform.translation, 1.0f, WHITE);
            EndMode3D();

            DrawFPS(10,10);
        EndDrawing();
    }

    // Clean up
    UnloadModel(player1.playerModel);
    CloseWindow();

    return 0;
}
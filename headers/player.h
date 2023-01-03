#pragma once
#include "raylib.h"
#include "raymath.h"
#include "dlib.h"

//Base player struct.
typedef struct{
    //Rendering
    Transform playerTransform;
    Model playerModel;
    
    //Animation
    unsigned int animsCount;
    unsigned int animIndex;
    unsigned int animCurrentFrame;
    
    ModelAnimation* playerAnimations;
    ModelAnimation currentAnimation;
    
    //Movement
    float speed;
    float targetHeight;
    bool isMoving;
} Player;

// Player movement
void UpdatePlayer(Player *player, Vector2 angle);

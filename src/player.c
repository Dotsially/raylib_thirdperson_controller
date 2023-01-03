#include "player.h"


// Player movement
void UpdatePlayer(Player* player, Vector2 angle)
{
    //Vector rotation angle coordinates. Allows to rotate the inputDirection vector with the camera angle.
    Vector2 vraCoordinates = {0.0f, 0.0f};
    Vector2 inputDirection = {0.0f, 0.0f};
    vraCoordinates.x = sinf(angle.x);
    vraCoordinates.y = cosf(angle.x);
    
    //Bool to check if button is pressed
    player->isMoving = false;
    
    //Vector rotation angle matrix. Matrix to rotate the x,y of inputDirection. 
    DMatrix2x2 vraMatrix = (DMatrix2x2){vraCoordinates.y, -vraCoordinates.x, vraCoordinates.x, vraCoordinates.y};
    

    inputDirection.x = IsKeyDown(KEY_A) - IsKeyDown(KEY_D);
    inputDirection.y = IsKeyDown(KEY_W) - IsKeyDown(KEY_S);

    inputDirection = DVector2MultiplyByMatrix2x2(inputDirection, vraMatrix);

    inputDirection = Vector2Normalize(inputDirection);

    //Check wether a button is pressed.
    if(inputDirection.x != 0 || inputDirection.y != 0){
        player->isMoving = true;
    }

    //Move, rotate and animate player when its moving.
    if(player->isMoving){
        player->playerTransform.rotation = QuaternionFromAxisAngle((Vector3){0.0f, 1.0f, 0.0f}, (atan2f(inputDirection.x, inputDirection.y)));
        player->playerTransform.translation.x += inputDirection.x*0.1f;
        player->playerTransform.translation.z += inputDirection.y*0.1f;
        player->animIndex = 6;
    }else{
        player->animIndex = 2;
    }
    

    player->playerModel.transform = QuaternionToMatrix(player->playerTransform.rotation);
    
    player->currentAnimation = player->playerAnimations[player->animIndex];
    player->animCurrentFrame = (player->animCurrentFrame + 1)%player->currentAnimation.frameCount;
}

#pragma once
#include "raymath.h"


//Matrix, 2x2 components, column mayor, OpenGL style, right handed.
typedef struct{
    float m0, m2;
    float m1, m3;
} DMatrix2x2;

//Multiply 2x2 DMatrix by Vector2
Vector2 DVector2MultiplyByMatrix2x2(Vector2 vector, DMatrix2x2 matrix);
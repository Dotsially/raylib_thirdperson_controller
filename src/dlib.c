#include "dlib.h"


Vector2 DVector2MultiplyByMatrix2x2(Vector2 vector, DMatrix2x2 matrix){
    Vector2 result = (Vector2){
            matrix.m0 * vector.x + matrix.m1 * vector.y, 
            matrix.m2 * vector.x + matrix.m3 * vector.y
        };
        return result;
}
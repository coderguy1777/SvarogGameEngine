#include "translatevec2.h"
#include "core/Point.h"
float Translate2D::findDeltaX() {
    float delt_x = translateVec2d.getPosX() - translateVec2d.getPosY();
    return delt_x;
}

float Translate2D::findDeltaY() {
    float delt_y = translateVec2d.getPosY() - translateVec2d.getPosX();
    return delt_y;
}

float Translate2D::findDeltaTime(float time, float fps) {
    return time/fps;
}

Vector2 Translate2D::calculateDirection(int units) {
    float vecmag = translateVec2d.vec2Mag();
    Point2D newPoint;
    newPoint.x = translateVec2d.getPosX() / vecmag;
    newPoint.y = translateVec2d.getPosY() / vecmag;
    Vector2 newPos(newPoint);
    newPos.setPosX(newPos.getPosX() * units);
    newPos.setPosY(newPos.getPosY() * units);
    float newmag = newPos.vec2Mag();
    return newPos;
}

Vector2 Translate2D::calculateVectorVelocity(int directionam, float rate) {
    Vector2 directionVec(calculateDirection(directionam));
    return Vector2(directionVec * rate);
}

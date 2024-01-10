//
// Created by Juan Hurtado on 6/01/24.
//

#include "Physics.h"
#include <cmath>

Vec2 Physics::_getActualPosition(Vec2 entityPos, CBoundingBox boundingBox) {
    auto center = boundingBox.center;
    auto size = boundingBox.size;
    auto actualPos = entityPos + center - size / 2;
    return actualPos;
}

bool Physics::areColliding(Entity *a, Entity *b) {
    return Physics::getOverlap(a, b) != Vec2(0, 0);
}

Vec2 Physics::getOverlap(Entity *a, Entity *b) {
    if (!a->hasComponent<CBoundingBox>() || !b->hasComponent<CBoundingBox>())
        return {0, 0};
    // get the actual position of the bounding boxes
    auto boundingBoxA = a->getComponent<CBoundingBox>();
    auto boundingBoxB = b->getComponent<CBoundingBox>();
    auto posA = Physics::_getActualPosition(a->getComponent<CTransform>().pos, boundingBoxA);
    auto posB = Physics::_getActualPosition(b->getComponent<CTransform>().pos, boundingBoxB);
    auto widthA = boundingBoxA.size.x;
    auto widthB = boundingBoxB.size.x;
    auto heightA = boundingBoxA.size.y;
    auto heightB = boundingBoxB.size.y;
    // get the distance between the centers of the boxes
    auto distance = Vec2(std::abs(posA.x - posB.x), std::abs(posA.y - posB.y));
    auto overlapX = widthA / 2 + widthB / 2 - distance.x;
    // if overlapX is > 0, it means that we have an x overlap
    auto overlapY = heightA / 2 + heightB / 2 - distance.y;
    // and the same with the y direction
    return {overlapX, overlapY};
}
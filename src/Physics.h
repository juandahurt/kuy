//
// Created by Juan Hurtado on 6/01/24.
//

#ifndef KUY_PHYSICS_H
#define KUY_PHYSICS_H


#include "Entity.h"

class Physics {
    static Vec2 _getActualPosition(Vec2 entityPos, CBoundingBox boundingBox);
public:
    static bool areColliding(Entity* a, Entity* b);
    static Vec2 getOverlap(Entity* a, Entity* b);
};


#endif //KUY_PHYSICS_H

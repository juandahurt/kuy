//
// Created by Juan Hurtado on 18/12/23.
//

#ifndef KUY_ENTITY_H
#define KUY_ENTITY_H

#include <iostream>
#include "Components.h"

class Entity {
    friend class EntityManager;
    bool _active;
    size_t _id;
    std::string _tag;
public:
    Entity(const size_t i, std::string &t)
        : _id (i), _tag (t) {
    }

    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CCollision> cCollision;
    std::shared_ptr<CInput> cInput;
    std::shared_ptr<CScore> cScore;
    std::shared_ptr<CLifespan> cLifespan;

    size_t id() const;
    std::string& tag() const;
    void isActive() const;
    void destroy();
};

#endif //KUY_ENTITY_H

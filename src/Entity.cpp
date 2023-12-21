//
// Created by Juan Hurtado on 21/12/23.
//

#include "Entity.h"

void Entity::destroy() {
    _active = false;
}

bool Entity::isActive() const {
    return _active;
}

std::string &Entity::tag() {
    return _tag;
}

size_t Entity::id() const {
    return _id;
}
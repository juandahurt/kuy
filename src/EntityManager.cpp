//
// Created by Juan Hurtado on 19/12/23.
//

#include "EntityManager.h"

EntityManager::EntityManager() {}

void EntityManager::init() {
    _totalEntities = 0;
}

void EntityManager::update() {
    // TODO: check for entities to delete / add
}

EntityVec &EntityManager::entities() {
    return _entities;
}

std::shared_ptr<Entity> EntityManager::addEntity(std::string &tag) {
    auto entity = std::make_shared<Entity>(_totalEntities++, tag);
    _entities.push_back(entity);
    _entitiesMap[tag].push_back(entity);
    return entity;
}

EntityVec &EntityManager::entities(std::string &tag) {
    return _entitiesMap[tag];
}

EntityMap &EntityManager::entitiesMap() {
    return _entitiesMap;
}
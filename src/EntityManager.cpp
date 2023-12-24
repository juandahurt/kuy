//
// Created by Juan Hurtado on 19/12/23.
//

#include "EntityManager.h"

EntityManager::EntityManager() {
    _totalEntities = 0;
}

void EntityManager::init() {
    _totalEntities = 0;
}

void EntityManager::_addNewEntities() {
    for (auto &e : _entitiesToAdd) {
        _entities.push_back(e);
        _entitiesMap[e->tag()].push_back(e);
    }
    _entitiesToAdd.clear();
}

void EntityManager::_deleteDeadEntities() {
    auto entitiesPos = _entities.begin();
    for (auto &e: _entities) {
        if (e == nullptr) continue;
        if (!e->isActive()) {
            _entities.erase(entitiesPos);
        }
        entitiesPos++;
    }

    for (auto &map : _entitiesMap) {
        auto vectorPos = map.second.begin();
        for (auto &e: map.second) {
            if (e == nullptr) continue;
            if (!e->isActive()) {
                map.second.erase(vectorPos);
            }
            vectorPos++;
        }
    }
}

void EntityManager::update() {
    _deleteDeadEntities();
    _addNewEntities();
}


EntityVec &EntityManager::entities() {
    return _entities;
}


std::shared_ptr<Entity> EntityManager::addEntity(std::string &tag) {
    auto entity = std::make_shared<Entity>(_totalEntities++, tag);
    _entitiesToAdd.push_back(entity);
    return entity;
}

EntityVec &EntityManager::entities(std::string &tag) {
    return _entitiesMap[tag];
}

EntityMap &EntityManager::entitiesMap() {
    return _entitiesMap;
}
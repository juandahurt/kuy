//
// Created by Juan Hurtado on 19/12/23.
//

#ifndef KUY_ENTITYMANAGER_H
#define KUY_ENTITYMANAGER_H

#include "Entity.h"
#include <vector>
#include <map>

typedef std::vector<Entity*> EntityVec;
typedef std::map<std::string, EntityVec>     EntityMap;

class EntityManager {
    EntityVec _entities;
    EntityVec _entitiesToAdd;
    EntityMap _entitiesMap;
    size_t    _totalEntities;

    void init();
    void _addNewEntities();
    void _deleteDeadEntities();
public:
    EntityManager();

    void update();
    Entity* addEntity(const std::string &tag);
    EntityVec& entities();
    EntityVec& entities(const std::string &tag);
    EntityMap& entitiesMap();
};


#endif //KUY_ENTITYMANAGER_H

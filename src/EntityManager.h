//
// Created by Juan Hurtado on 19/12/23.
//

#ifndef KUY_ENTITYMANAGER_H
#define KUY_ENTITYMANAGER_H

#include "Entity.h"
#include <vector>
#include <map>

typedef std::vector<std::shared_ptr<Entity> > EntityVec;
typedef std::map<std::string, EntityVec>     EntityMap;

class EntityManager {
    EntityVec _entities;
    EntityVec _entitiesToAdd;
    EntityMap _entitiesMap;
    size_t    _totalEntities;

    void init();
public:
    EntityManager();

    void update();
    std::shared_ptr<Entity> addEntity(std::string &tag);
    EntityVec& entities();
    EntityVec& entities(std::string &tag);
    EntityMap& entitiesMap();
};


#endif //KUY_ENTITYMANAGER_H

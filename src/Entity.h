//
// Created by Juan Hurtado on 18/12/23.
//

#ifndef KUY_ENTITY_H
#define KUY_ENTITY_H

#include <iostream>
#include <tuple>
#include "Components.h"

typedef std::tuple<
        CTransform,
        CLifespan
        > ComponentTuple;

class EntityManager;

class Entity {
    friend class EntityManager;

    bool _active;
    size_t _id;
    std::string _tag;
    ComponentTuple _components;

    Entity(const size_t &id, std::string &tag, ComponentTuple &components) : _components(components) {
        _active = true;
        _id = id;
        _tag = tag;
    }
public:
    size_t id() const;
    std::string& tag();
    bool isActive() const;
    void destroy();

    template <typename T>
    bool hasComponent() {
        return getComponent<T>().exists;
    }

    template <typename T, typename... TArgs>
    void addComponent(TArgs&&... args) {
        auto& component = getComponent<T>();
        component = T(std::forward<TArgs>(args)...);
        component.exists = true;
    }

    template <typename T>
    T& getComponent() {
        return std::get<T>(_components);
    }

    template <typename T>
    void removeComponent() {
        auto &component = std::get<T>();
        component.exists = false;
    }
};

#endif //KUY_ENTITY_H

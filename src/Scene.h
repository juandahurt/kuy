//
// Created by Juan Hurtado on 30/12/23.
//

#ifndef KUY_SCENE_H
#define KUY_SCENE_H

#include "EntityManager.h"
#include "Kuy.h"
#include <map>
#include <string>

// TODO: add getters for width, height, currentFrame

typedef std::map<int, std::string> ActionMap;

class Scene {
protected:
//    Kuy*            _engine;
    EntityManager   _entityManager;
    bool            _paused;
    size_t          _currentFrame;
    ActionMap       _actionMap;

    virtual void onEnd() = 0;

public:
    Scene();
//    Scene(Kuy* engine);

    virtual void update() = 0;
    virtual void executeAction() = 0; // TODO: create action class
    virtual void render() = 0;

    void registerAction(int inputKey, const std::string &name);
};


#endif //KUY_SCENE_H

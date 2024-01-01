//
// Created by Juan Hurtado on 30/12/23.
//

#include "Scene.h"

Scene::Scene(Kuy *engine) {
    _paused = false;
    _currentFrame = 0;
    _engine = engine;
}

Scene::~Scene() {
    _actionMap.clear();
}

void Scene::registerAction(int inputKey, const std::string &name) {
    _actionMap[inputKey] = name;
}

const std::string* Scene::action(int inputKey) {
    if (_actionMap.find(inputKey) == _actionMap.end()) {
        return nullptr;
    }
    return &_actionMap[inputKey];
}

void Scene::onEnd() {
    // TODO: add end logic
}
//
// Created by Juan Hurtado on 30/12/23.
//

#include "Scene.h"

void Scene::registerAction(int inputKey, const std::string &name) {
    _actionMap[inputKey] = name;
}
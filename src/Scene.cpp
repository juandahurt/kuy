//
// Created by Juan Hurtado on 30/12/23.
//

#include "Scene.h"
#include "Kuy.h"
#include "Plugin.h"

Scene::Scene(Kuy *engine) {
    _paused = false;
    _currentFrame = 0;
    _engine = engine;
}

Scene::~Scene() {
    _actionMap.clear();
    _plugins.clear();
}

float Scene::width() {
    return (float)_engine->window()->getSize().x;
}

float Scene::height() {
    return (float)_engine->window()->getSize().y;
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

void Scene::addPlugin(const std::string& id, Plugin* plugin) {
    _plugins[id] = plugin;
    plugin->scene = this;
}

Plugin* Scene::getPlugin(const std::string &id) {
    auto plugin = _plugins.find(id);
    if (plugin == _plugins.end())
        return nullptr;
    return plugin->second;
}

void Scene::render(const sf::Drawable& element) {
    _engine->window()->draw(element);
}

void Scene::onEnd() {
    // TODO: add end logic
}
//
// Created by Juan Hurtado on 30/12/23.
//

#include "Kuy.h"

Kuy::Kuy() {
    // TODO: set window values from config file
    _assets = Assets();
    _running = true;
    _window.create(sf::VideoMode(1080, 720), "Test");
    _window.setFramerateLimit(60);
    _simulationSpeed = 1;
}

sf::RenderWindow* Kuy::window() {
    return &_window;
}

void Kuy::registerScene(const std::string &name, Scene *scene) {
    _scenes[name] = scene;
    _currScene = name;
    _currentScene()->init();
}

void Kuy::changeScene(const std::string &name, bool endCurrent) {
    _currScene = name;
    // TODO: implement end current logic
}

Scene *Kuy::_currentScene() {
    return _scenes[_currScene];
}

void Kuy::_checkUserInput() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            std::string type = event.type == sf::Event::KeyPressed ? "START" : "END";
            auto name = _currentScene()->action(event.key.code);
            // if name is not null, the action is registered
            if (name) _currentScene()->executeAction(Action(*name, type));
        }
    }
}

void Kuy::run() {
    while (_running) {
        _currentScene()->update();
        _window.clear();
        _checkUserInput();
        _currentScene()->render();
        _window.display();
    }
}

void Kuy::quit() {
    _running = false;
}

Assets Kuy::getAssets() {
    return
    _assets;
}

Kuy::~Kuy() {
    for (auto &s : _scenes) {
        delete s.second;
    }
}

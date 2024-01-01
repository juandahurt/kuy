//
// Created by Juan Hurtado on 30/12/23.
//

#include "Kuy.h"

Kuy::Kuy() {
    // TODO: set window values from config file
    _running = true;
    _window.create(sf::VideoMode(1080, 720), "Test");
    _window.setFramerateLimit(60);
    _simulationSpeed = 1;
}

sf::RenderWindow* Kuy::window() {
    return &_window;
}

void Kuy::changeScene(const std::string &name, Scene *scene, bool endCurrent) {
    _scenes[name] = scene;
    _currentScene = name;
    // TODO: implement end current logic
}

Scene *Kuy::currentScene() {
    return _scenes[_currentScene];
}

void Kuy::_checkUserInput() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _running = false;
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            std::string type = event.type == sf::Event::KeyPressed ? "START" : "END";
            auto name = currentScene()->action(event.key.code);
            // if name is not null, the action is registered
            if (name) currentScene()->executeAction(Action(*name, type));
        }
    }
}

void Kuy::run() {
    while (_running) {
        currentScene()->update();
        _window.clear();
        _checkUserInput();
        currentScene()->render();
        _window.display();
    }
}

Kuy::~Kuy() {
    for (auto &s : _scenes) {
        delete s.second;
    }
}

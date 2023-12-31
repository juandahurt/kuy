//
// Created by Juan Hurtado on 30/12/23.
//

#include "Kuy.h"

Kuy::Kuy() {
    _running = true;
    _window.create(sf::VideoMode(100, 200), "Test");
    _window.setFramerateLimit(60);
    _simulationSpeed = 1;
}

Scene *Kuy::currentScene() {
    return _scenes[_currentScene];
}

void Kuy::_checkUserInput() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        // TODO: call executeAction to the current scene.
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
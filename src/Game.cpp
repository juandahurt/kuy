//
// Created by Juan Hurtado on 19/12/23.
//

#include "Game.h"

Game::Game() {
    _running = true;
    _paused = false;
    _init();
}

void Game::_init() {
    _window.create(sf::VideoMode(500, 500), "Test");
    _window.setFramerateLimit(60);
    _spawnPlayer();
}

void Game::_spawnPlayer() {
    std::string tag = "player";
    auto entity = _entityManager.addEntity(tag);
    // transform component
    entity->cTransform = std::make_shared<CTransform>(Vec2(100, 50), Vec2(0, 0), 5);
    auto bgColor = sf::Color(100, 150, 100);
    auto outlineColor = sf::Color(100, 100, 200);
    // shape component
    entity->cShape = std::make_shared<CShape>(10.0f, 5, bgColor, outlineColor, 2.0f);
    // input component
    entity->cInput = std::make_shared<CInput>();
    _player = entity;
}

void Game::run() {
    while (_running) {
        _sUserInput();
        _sMovement();
        _sRender();
    }
}

void Game::_sRender() {
    _window.clear();
    for (const auto &e : _entityManager.entities()) {
        if (e->cTransform != nullptr && e->cShape != nullptr) {
            auto circle = e->cShape->circle;
            auto position = e->cTransform->pos;
            circle.setPosition(position.x, position.y);
            circle.setRotation(e->cTransform->angle++);
            _window.draw(circle);
        }
    }
    _window.display();
}


void Game::_sUserInput() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                _running = false;
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    _player->cInput->up = true;
                    _player->cTransform->vel.y = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    _player->cInput->down = true;
                    _player->cTransform->vel.y = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    _player->cInput->left = true;
                    _player->cTransform->vel.x = -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    _player->cInput->right = true;
                    _player->cTransform->vel.x = 1;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::W) {
                    _player->cInput->up = false;
                    _player->cTransform->vel.y = 0;
                }
                if (event.key.code == sf::Keyboard::S) {
                    _player->cInput->down = false;
                    _player->cTransform->vel.y = 0;
                }
                if (event.key.code == sf::Keyboard::A) {
                    _player->cInput->left = false;
                    _player->cTransform->vel.x = 0;
                }
                if (event.key.code == sf::Keyboard::D) {
                    _player->cInput->right = false;
                    _player->cTransform->vel.x = 0;
                }
                break;
        }
    }
}

void Game::_sMovement() {
    _player->cTransform->pos += _player->cTransform->vel;
}
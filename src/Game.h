//
// Created by Juan Hurtado on 19/12/23.
//

#ifndef KUY_GAME_H
#define KUY_GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "EntityManager.h"

class Game {
    sf::RenderWindow            _window;
    bool                        _running;
    bool                        _paused;
    std::shared_ptr<Entity>     _player;
    EntityManager               _entityManager;

    void _init();
    void _spawnPlayer();
    void _spawnBullet();
    void _sMovement();
    void _sUserInput();
    void _sRender();
    void _sEnemySpawner();
    void _sCollision();
public:
    Game();

    void run();
};

#endif //KUY_GAME_H

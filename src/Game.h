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
    bool                        _running                = true;
    bool                        _paused                 = false;
    std::shared_ptr<Entity>     _player;
    EntityManager               _entityManager;
    int                         _frameCount             = 0;
    int                         _lastFrameEnemySpawned  = 0;

    void _init();
    void _spawnPlayer();
    void _spawnBullet(std::shared_ptr<Entity> entity, Vec2 target);
    void _sMovement();
    void _sUserInput();
    void _sRender();
    void _spawnEnemy();
    void _sEnemySpawner();
    void _sCollision();
public:
    Game();

    void run();
};

#endif //KUY_GAME_H

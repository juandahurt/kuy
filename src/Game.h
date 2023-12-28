//
// Created by Juan Hurtado on 19/12/23.
//

#ifndef KUY_GAME_H
#define KUY_GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "EntityManager.h"
#include "imgui/imgui.h"
#include "imgui-SFML/imgui-SFML.h"

struct {
    int width;
    int height;
} typedef WindowConfig;

struct {
    float vel;
    float radius;
} typedef BulletConfig;

struct {
    int spawnRate;
    float radius;
    float collisionRadius;
    float smallEnemiesProportion;
    float smallEnemyVelocity;
} typedef EnemyConfig;

class Game {
    sf::RenderWindow            _window;
    bool                        _running                = true;
    bool                        _paused                 = false;
    std::shared_ptr<Entity>     _player;
    EntityManager               _entityManager;
    int                         _frameCount             = 0;
    int                         _lastFrameEnemySpawned  = 0;
    sf::Clock                   _deltaClock;
    WindowConfig                _windowConfig;
    BulletConfig                _bulletConfig;
    EnemyConfig                 _enemyConfig;
    bool                        _collisionEnabled       = true;
    bool                        _enemySpawnerEnabled   = true;

    void _init();
    void _spawnPlayer();
    void _spawnBullet(std::shared_ptr<Entity> entity, Vec2 target);
    void _sMovement();
    void _sUserInput();
    void _sRender();
    void _spawnEnemy();
    void _spawnSmallEnemies(std::shared_ptr<Entity> &enemy);
    void _sEnemySpawner();
    void _sCollision();
    void _sGUI();
public:
    Game();

    void run();
};

#endif //KUY_GAME_H

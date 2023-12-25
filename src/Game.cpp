//
// Created by Juan Hurtado on 19/12/23.
//

#include "Game.h"

#include <cstdlib>

Game::Game() {
    _entityManager = EntityManager();
    _init();
}

void Game::_init() {
    // TODO: read window config from config file
    _windowConfig = {
      .width = 1080,
      .height = 720
    };
    _bulletConfig = {
        .vel = 4,
        .radius = 5
    };

    _window.create(sf::VideoMode(_windowConfig.width, _windowConfig.height), "Test");
    _window.setFramerateLimit(60);
    ImGui::SFML::Init(_window);
    _spawnPlayer();
}

void Game::_spawnPlayer() {
    std::string tag = "player";
    auto entity = _entityManager.addEntity(tag);
    // transform component
    entity->cTransform = std::make_shared<CTransform>(Vec2(100, 50), Vec2(0, 0), 5);
    auto bgColor = sf::Color(100, 150, 100);
    auto outlineColor = sf::Color(100, 100, 200, 0);
    // shape component
    entity->cShape = std::make_shared<CShape>(10.0f, 5, bgColor, outlineColor, 2.0f);
    // input component
    entity->cInput = std::make_shared<CInput>();
    _player = entity;
}

void Game::run() {
    while (_running) {
        _entityManager.update();
        _sUserInput();
        _sEnemySpawner();
        _sMovement();
        _sCollision();
        _sGUI();
        _sRender();
        _frameCount++;
    }
}

void Game::_sRender() {
    _window.clear();
    for (const auto &e : _entityManager.entities()) {
        if (e->cTransform != nullptr && e->cShape != nullptr) {
            auto circle = e->cShape->circle;
            auto position = e->cTransform->pos;
            circle.setPosition(position.x, position.y);
            circle.setRotation(e->cTransform->angle);
            _window.draw(circle);
        }
    }
    ImGui::SFML::Render(_window);
    _window.display();
}


void Game::_sUserInput() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(_window, event);
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
            case sf::Event::MouseButtonPressed:
                _spawnBullet(_player, Vec2((float) event.mouseButton.x, (float) event.mouseButton.y));
                break;
        }
    }
}

void Game::_spawnBullet(std::shared_ptr<Entity> entity, Vec2 target) {
    std::string tag = "bullet";
    auto bullet = _entityManager.addEntity(tag);
    // transform component
    auto pos = entity->cTransform->pos;
    auto vel = target - pos;
    vel.normalize();
    vel *= _bulletConfig.vel;
    bullet->cTransform = std::make_shared<CTransform>(pos, vel, 0);
    auto bgColor = sf::Color(255, 255, 255);
    auto outlineColor = sf::Color(100, 100, 200, 0);
    // shape component
    bullet->cShape = std::make_shared<CShape>(_bulletConfig.radius, 9, bgColor, outlineColor, 0.0f);
    // lifespan component
    bullet->cLifespan = std::make_shared<CLifespan>(90);
}

void Game::_sMovement() {
    for (auto &e : _entityManager.entities()) {
        if (e->cTransform == nullptr) continue;
        e->cTransform->pos += e->cTransform->vel;
        e->cTransform->angle++;
        if (e->cLifespan == nullptr) continue;
        auto color = e->cShape->circle.getFillColor();
        color.a = ((float) e->cLifespan->remaining) / (float) e->cLifespan->total * 255.f;
        e->cShape->circle.setFillColor(color);
        if (e->cLifespan->remaining > 0) e->cLifespan->remaining--;
        else e->destroy();
    }
}

void Game::_sEnemySpawner() {
    if (_frameCount - _lastFrameEnemySpawned == 90) {
        _lastFrameEnemySpawned = _frameCount;
        _spawnEnemy();
    }
}

void Game::_spawnEnemy() {
    std::string tag = "enemy";
    auto entity = _entityManager.addEntity(tag);
    int radius = 35;
    auto randPoints = rand() % (6 + 3);
    auto randX = rand() % (500 + 1 - radius * 2) + radius;
    auto randY = rand() % (500 + 1 - radius * 2) + radius;
    // transform component
    entity->cTransform = std::make_shared<CTransform>(Vec2(randX, randY), Vec2(1, 2.3), 5);
    auto bgColor = sf::Color(100, rand() % (255 + 1) , 100);
    auto outlineColor = sf::Color(100, 100, 200, 0);
    // shape component
    entity->cShape = std::make_shared<CShape>(10.0f, randPoints, bgColor, outlineColor, 2.0f);
}

void Game::_sCollision() {
    std::string enemyTag = "enemy";
    // iterate through all enemies
    for (auto &e : _entityManager.entities(enemyTag)) {
        if (e->cTransform == nullptr) continue;
        auto pos = e->cTransform->pos;
        //.TODO: use the collision radius to check the collision, not only its position
        if (pos.x > (float)_windowConfig.width || pos.x < 0) {
            e->cTransform->vel.x *= -1;
        }
        if (pos.y < 0 || pos.y > (float)_windowConfig.height) {
            e->cTransform->vel.y *= -1;
        }
    }
}

void Game::_sGUI() {
    ImGui::SFML::Update(_window, _deltaClock.restart());
    ImGui::Begin("Test");
    ImGui::BeginTabBar("");
    ImGui::BeginTabItem("Entities");
    if (ImGui::CollapsingHeader("All")) {
        for (auto &e: _entityManager.entities()) {
            ImGui::BeginGroup();
            auto color = e->cShape->circle.getFillColor();
            auto r = (float) color.r / 255;
            auto g = (float) color.g / 255;
            auto b = (float) color.b / 255;
            ImGui::ColorButton("test", ImVec4(r,g,b,1));
            ImGui::SameLine();
            ImGui::Text("%zu", e->id());
            ImGui::SameLine();
            ImGui::Text("%s", e->tag().c_str());
            ImGui::SameLine();
            ImGui::Text("%.f %.f", e->cTransform->pos.x, e->cTransform->pos.y);
            ImGui::EndGroup();
        }
    }
    if (ImGui::CollapsingHeader("Bullets")) {
        std::string bulletTag = "bullet";
        for (auto &e: _entityManager.entities(bulletTag)) {
            ImGui::BeginGroup();
            auto color = e->cShape->circle.getFillColor();
            auto r = (float) color.r / 255;
            auto g = (float) color.g / 255;
            auto b = (float) color.b / 255;
            ImGui::ColorButton("test", ImVec4(r,g,b,1));
            ImGui::SameLine();
            ImGui::Text("%zu", e->id());
            ImGui::SameLine();
            ImGui::Text("%s", e->tag().c_str());
            ImGui::SameLine();
            ImGui::Text("%.f %.f", e->cTransform->pos.x, e->cTransform->pos.y);
            ImGui::EndGroup();
        }
    }
    if (ImGui::CollapsingHeader("Player")) {
        std::string playerTag = "player";
        for (auto &e: _entityManager.entities(playerTag)) {
            ImGui::BeginGroup();
            auto color = e->cShape->circle.getFillColor();
            auto r = (float) color.r / 255;
            auto g = (float) color.g / 255;
            auto b = (float) color.b / 255;
            ImGui::ColorButton("test", ImVec4(r,g,b,1));
            ImGui::SameLine();
            ImGui::Text("%zu", e->id());
            ImGui::SameLine();
            ImGui::Text("%s", e->tag().c_str());
            ImGui::SameLine();
            ImGui::Text("%.f %.f", e->cTransform->pos.x, e->cTransform->pos.y);
            ImGui::EndGroup();
        }
    }
    if (ImGui::CollapsingHeader("Enemies")) {
        std::string enemyTag = "enemy";
        for (auto &e: _entityManager.entities(enemyTag)) {
            ImGui::BeginGroup();
            auto color = e->cShape->circle.getFillColor();
            auto r = (float) color.r / 255;
            auto g = (float) color.g / 255;
            auto b = (float) color.b / 255;
            ImGui::ColorButton("test", ImVec4(r,g,b,1));
            ImGui::SameLine();
            ImGui::Text("%zu", e->id());
            ImGui::SameLine();
            ImGui::Text("%s", e->tag().c_str());
            ImGui::SameLine();
            ImGui::Text("%.f %.f", e->cTransform->pos.x, e->cTransform->pos.y);
            ImGui::EndGroup();
        }
    }
    ImGui::EndTabItem();
    ImGui::EndTabBar();
    ImGui::End();
}
//
// Created by Juan Hurtado on 30/12/23.
//

#ifndef KUY_KUY_H
#define KUY_KUY_H

#include "Scene.h"
#include "Assets.h"

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

// TODO: add assets

typedef std::map<std::string, Scene*> SceneMap;

class Kuy {
protected:
    sf::RenderWindow    _window;
    std::string         _currScene;
    size_t              _simulationSpeed;
    bool                _running;
    SceneMap            _scenes;
    Assets              _assets;

    Scene* _currentScene();
    void _checkUserInput();
public:
    Kuy();
    virtual ~Kuy();

    sf::RenderWindow* window();

    void registerScene(const std::string &name, Scene *scene);
    void changeScene(const std::string &name, bool endCurrent = false);
    void quit();
    void run();
    Assets getAssets();
//    bool isRunning();
};


#endif //KUY_KUY_H

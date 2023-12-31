//
// Created by Juan Hurtado on 30/12/23.
//

#ifndef KUY_KUY_H
#define KUY_KUY_H

#include "Scene.h"
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

// TODO: add assets

typedef std::map<std::string, Scene*> SceneMap;

class Kuy {
protected:
    sf::RenderWindow    _window;
    std::string         _currentScene;
    size_t              _simulationSpeed;
    bool                _running;
    SceneMap            _scenes;

    Scene* currentScene();
//    void _update();
    void _checkUserInput();
public:
    Kuy();

//    void change_scene(const std::string & name, Scene &scene, bool endCurrent = false);
//    void quit();
    void run();
//    bool isRunning();
};


#endif //KUY_KUY_H

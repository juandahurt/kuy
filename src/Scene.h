//
// Created by Juan Hurtado on 30/12/23.
//

#ifndef KUY_SCENE_H
#define KUY_SCENE_H

#include "EntityManager.h"
#include "Action.h"
#include <map>
#include <string>
#include <vector>

class Plugin;
class Kuy;

typedef std::map<int, std::string> ActionMap;
typedef std::map<std::string, Plugin*> PluginVec;


class Scene {
protected:
    Kuy*            _engine;
    EntityManager   _entityManager;
    bool            _paused;
    size_t          _currentFrame;
    ActionMap       _actionMap;
    PluginVec       _plugins;

public:
    Scene(Kuy* engine);
    virtual ~Scene();

    float width();
    float height();

    /// All the initialization code must be implemented in this function
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void executeAction(const Action &action) = 0;
    virtual void render() = 0;

    void registerAction(int inputKey, const std::string &name);
    const std::string* action(int inputKey);
    void addPlugin(const std::string& id, Plugin* plugin);
    void render(const sf::Drawable& element);
    Plugin* getPlugin(const std::string &id);
    void onEnd();
};


#endif //KUY_SCENE_H

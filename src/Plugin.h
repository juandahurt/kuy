//
// Created by Juan Hurtado on 6/01/24.
//

#ifndef KUY_PLUGIN_H
#define KUY_PLUGIN_H

#include <string>
#include "Scene.h"

class Plugin {
public:
    bool            active;
    Scene*          scene;

    Plugin();
    ~Plugin();

    virtual void update();
};

// TODO: move grid plugin to other file (?)
class GridPlugin : public Plugin {
public:
    float cellHeight;
    float cellWidth;

    GridPlugin(float cellHeight, float cellWidth) : Plugin(), cellHeight(cellHeight),
                                                                           cellWidth(cellWidth) {}
    void update() override;
    Vec2 getLocationFromGridPos(int x, int y);
};

#endif //KUY_PLUGIN_H

//
// Created by Juan Hurtado on 3/01/24.
//

#ifndef KUY_ASSETS_H
#define KUY_ASSETS_H

#include "Animation.h"
#include <map>

typedef std::map<int, Animation*> AnimationMap;

class Assets {
    AnimationMap _animations;
public:
    Assets();
    void addAnimation(int id, Animation *animation);
    Animation& getAnimation(int id);
};


#endif //KUY_ASSETS_H

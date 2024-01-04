//
// Created by Juan Hurtado on 3/01/24.
//

#ifndef KUY_ASSETS_H
#define KUY_ASSETS_H

#include "Animation.h"
#include <map>

typedef std::map<int, Animation*> AnimationMap;
typedef std::map<int, sf::Texture*> TextureMap;

class Assets {
    AnimationMap    _animations;
    TextureMap      _textures;
public:
    Assets();
    void addAnimation(int id, Animation *animation);
    Animation& getAnimation(int id);
    void addTexture(int id, std::string path);
    sf::Texture& texture(int id);
};


#endif //KUY_ASSETS_H

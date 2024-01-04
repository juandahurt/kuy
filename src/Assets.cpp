//
// Created by Juan Hurtado on 3/01/24.
//

#include "Assets.h"

Assets::Assets() {}

void Assets::addAnimation(int id, Animation *animation) {
    _animations[id] = animation;
}

Animation& Assets::getAnimation(int id) {
    return *_animations[id];
}

void Assets::addTexture(int id, std::string path) {
    _textures[id] = new sf::Texture();
    _textures[id]->loadFromFile(path);
}

sf::Texture &Assets::texture(int id) {
    return *_textures[id];
}
//
// Created by Juan Hurtado on 2/01/24.
//

#include "Animation.h"
#include <iostream>

Animation::Animation(std::string pathToTexture, int duration, int frames) {
    _duration = duration;
    _frames = frames;
    _framesAlive = 0;
    if (!pathToTexture.empty()) {
        if (_texture.loadFromFile(pathToTexture)) {
            sprite.setTexture(_texture);
        }
    }
}

Animation::~Animation() {
    std::cout << "called";
}

void Animation::update() {
    int currentFrame = (_framesAlive / _duration) % _frames;
    sprite.setTextureRect(sf::IntRect(currentFrame * 32, 0, 32, 32));
    _framesAlive++;
}
//
// Created by Juan Hurtado on 2/01/24.
//

#include "Animation.h"

Animation::Animation(sf::Texture &texture, int duration, int frames, Vec2 size) {
    _duration = duration;
    _frames = frames;
    _framesAlive = 0;
    _size = size;
    sprite.setTexture(texture);
}

Animation::~Animation() {

}

void Animation::update() {
    int currentFrame = (_framesAlive / _duration) % _frames;
    sprite.setTextureRect(
            sf::IntRect(
                    currentFrame * _size.x,
                    0,
                    _size.x,
                    _size.y)
            );
    _framesAlive++;
}
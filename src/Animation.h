//
// Created by Juan Hurtado on 2/01/24.
//

#ifndef KUY_ANIMATION_H
#define KUY_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Vec2.h"

class Animation {
    /// How long the animation will take
    int _duration;
    /// Number of frames the animation has
    int _frames;
    /// Number of frame on which the animation has been alive
    int _framesAlive;
    /// The animation size
    Vec2 _size = {0, 0};
public:
    /// The actual sprite
    sf::Sprite sprite;

    Animation(sf::Texture &texture, int duration, int frames, Vec2 size);
    ~Animation();

    void update();
    sf::Sprite& getSprite();
};


#endif //KUY_ANIMATION_H

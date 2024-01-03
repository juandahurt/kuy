//
// Created by Juan Hurtado on 2/01/24.
//

#ifndef KUY_ANIMATION_H
#define KUY_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Animation {
    /// How long the animation will take
    int _duration;
    /// Number of frames the animation has
    int _frames;
    /// Number of frame on which the animation has been alive
    int _framesAlive;
    /// The texture which in which the animation is
    sf::Texture _texture;
public:
    /// The actual sprite
    sf::Sprite sprite;

    Animation(std::string pathToTexture, int duration, int frames);
    ~Animation();

    void update();
};


#endif //KUY_ANIMATION_H

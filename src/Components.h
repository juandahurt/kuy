//
// Created by Juan Hurtado on 18/12/23.
//

#include <SFML/Graphics.hpp>

#include "Vec2.h"
#include "Animation.h"

#ifndef KUY_COMPONENTS_H
#define KUY_COMPONENTS_H

// TODO: implement bounding box, animation, etc

/// Base Component class
class Component {
public:
    bool exists = false;
};

class CTransform : public Component {
public:
    Vec2 pos;
    Vec2 vel;
    float angle;

    CTransform(const Vec2 &p, const Vec2 &v = Vec2(0, 0), float a = 0)
        : pos (p), vel (v), angle (a) {}
};

class CAnimation : public Component {
    bool        repeats;

public:
    Animation*   animation;

    CAnimation(Animation*  animation, bool repeats) : animation(animation), repeats(repeats) {}
};

// TODO: remove unnecessary ones
class CShape {
public:
    sf::CircleShape circle;

    CShape(float radius, int points, sf::Color &fill, sf::Color &outline, float thickness) {
        circle = sf::CircleShape(radius, points);
        circle.setRadius(radius);
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(radius, radius);
    }
};

class CCollision {
public:
    float radius;

    CCollision(float r)
        : radius (r) {}
};

class CScore {
public:
    int score = 0;

    CScore(int s)
        : score (s) {}
};

/// The lifespan unit represents one frame.
class CLifespan : public Component {
public:
    int remaining = 0;
    int total     = 0;

    CLifespan(int total)
        : remaining (total), total (total) {}
};

class CInput {
public:
    bool up     = false;
    bool left   = false;
    bool right  = false;
    bool down   = false;
    bool shoot  = false;

    CInput() {}
};

#endif //KUY_COMPONENTS_H
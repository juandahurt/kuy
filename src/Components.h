//
// Created by Juan Hurtado on 18/12/23.
//

#include <SFML/Graphics.hpp>

#include "Vec2.h"

#ifndef KUY_COMPONENTS_H
#define KUY_COMPONENTS_H

class CTransform {
public:
    Vec2 pos    = { 0.0, 0.0 };
    Vec2 vel    = { 0.0, 0.0 };
    float angle = 0.0;

    CTransform(const Vec2 &p, const Vec2 &v, float a)
        : pos (p), vel (v), angle (a) {}
};

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

class CColission {
public:
    float radius;

    CColission(float r)
        : radius (r) {}
};

class CScore {
public:
    int score = 0;

    CScore(int s)
        : score (s) {}
};

/// The lifespan unit represents one frame.
class CLifespan {
public:
    int remaining = 0;
    int total     = 0;

    CLifespan(int total)
        : remaining (total), total (total) {}
};

class CInput {
public:
    bool up    = false;
    bool left  = false;
    bool right = false;
    bool down  = false;
    bool shoot  = false;

    CInput() {}
};

#endif //KUY_COMPONENTS_H
//
// Created by Juan Hurtado on 18/12/23.
//

#include <SFML/Graphics.hpp>

#include "Vec2.h"
#include "Animation.h"

#ifndef KUY_COMPONENTS_H
#define KUY_COMPONENTS_H

/// Base Component class
class Component {
public:
    bool exists = false;
};

class CTransform : public Component {
public:
    Vec2 pos;
    Vec2 lastPos;
    Vec2 vel;
    Vec2 scale;
    float angle;

    CTransform(const Vec2 &p, const Vec2 &lp = Vec2(0, 0), const Vec2 &v = Vec2(0, 0), const Vec2 &sc = Vec2(1, 1), float a = 0)
        : pos (p), lastPos(lp), vel (v), scale(sc), angle (a) {}
};

class CAnimation : public Component {
    bool repeats;

public:
    Animation animation;

    CAnimation(Animation &animation, bool repeats) : animation(animation), repeats(repeats) {}
    ~CAnimation() {

    }
};

class CBoundingBox : public Component {
public:
    Vec2 size;
    Vec2 center;

    CBoundingBox(Vec2 size) : size(size), center(size / 2) {}
};

// TODO: remove unnecessary ones

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
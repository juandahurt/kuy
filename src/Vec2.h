//
// Created by Juan Hurtado on 15/12/23.
//

#ifndef KUY_VEC2_H
#define KUY_VEC2_H

class Vec2 {
public:
    float x = 0;
    float y = 0;

    Vec2(float x, float y);

    bool operator == (const Vec2 &rhs) const;
    bool operator != (const Vec2 &rhs) const;

    Vec2 operator + (const Vec2 &rhs) const;
    Vec2 operator - (const Vec2 &rhs) const;
    Vec2 operator / (const float val) const;
    Vec2 operator * (const float val) const;

    void operator += (const Vec2 &rhs);
    void operator -= (const Vec2 &rhs);
    void operator *= (const float val);
    void operator /= (const float val);

    float dist(const Vec2 &rhs) const;
    void normalize();
    float length();
};

#endif //KUY_VEC2_H

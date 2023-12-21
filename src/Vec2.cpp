//
// Created by Juan Hurtado on 15/12/23.
//

#include "Vec2.h"
#include <math.h>

Vec2::Vec2(float x, float y) : x (x), y (y) {}

bool Vec2::operator == (const Vec2 &rhs) const {
    return x == rhs.x && y == rhs.y;
}

bool Vec2::operator != (const Vec2 &rhs) const {
    return x != rhs.x || y != rhs.y;
}

Vec2 Vec2::operator + (const Vec2 &v) const {
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator - (const Vec2 &v) const {
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator / (const float val) const {
    return Vec2(x / val, y / val);
}

Vec2 Vec2::operator * (const float val) const {
    return Vec2(x * val, y * val);
}

void Vec2::operator += (const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator -= (const Vec2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
}

void Vec2::operator *= (const float val) {
    x *= val;
    y *= val;
}

void Vec2::operator /= (const float val) {
    x /= val;
    y /= val;
}

float Vec2::dist(const Vec2 &rhs) const {
    float dx = rhs.x - x;
    float dy = rhs.y - y;
    return sqrtf(dx * dx + dy * dy);
}

float Vec2::length() {
    return sqrtf(x * x + y * y);
}

void Vec2::normalize() {
    float l = length();
    x = x / l;
    y = y / l;
}
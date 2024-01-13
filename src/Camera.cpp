//
// Created by Juan Hurtado on 10/01/24.
//

#include "Camera.h"
#include "Kuy.h"

void XAxisCamera::update() {
    auto size = _engine->window()->getSize();
    auto floatSize = sf::Vector2((float)size.x, (float)size.y);
    auto center = sf::Vector2(x, (float)size.y / (float)2);
    auto view = sf::View(center, floatSize);
    _engine->window()->setView(view);

    if (showIndicator) {
        auto rect = sf::RectangleShape(sf::Vector2(1.f, (float)size.y));
        rect.setPosition(x, 0);
        rect.setOutlineColor(sf::Color(255, 255, 255));
        _engine->window()->draw(rect);
    }
}
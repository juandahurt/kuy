//
// Created by Juan Hurtado on 6/01/24.
//

#include "Plugin.h"
#include <SFML/Graphics.hpp>

Plugin::Plugin() {
    this->active = false;
}

Plugin::~Plugin() {

}

void Plugin::update() {}

void GridPlugin::update() {
    auto cellW = cellWidth;
    auto cellH = cellHeight;
    int colIndex = 0;
    while (colIndex * cellW < scene->width()) {
        sf::RectangleShape rect(sf::Vector2(1.f, scene->height()));
        rect.setPosition(colIndex * cellW, 0);
        rect.setOutlineColor(sf::Color(255, 255, 255));
        rect.setOutlineThickness(0.5);
        rect.setFillColor(sf::Color(0, 0, 0, 0));
        scene->render(rect);
        colIndex++;
    }
    float currentY = scene->height();
    int rowIndex = 0;
    while (currentY > 0) {
        sf::RectangleShape rect(sf::Vector2(scene->width(), 1.f));
        rect.setPosition(0, currentY);
        rect.setOutlineColor(sf::Color(255, 255, 255));
        rect.setOutlineThickness(0.5);
        rect.setFillColor(sf::Color(0, 0, 0, 0));
        scene->render(rect);
        rowIndex++;
        currentY -= cellH;
    }
}

Vec2 GridPlugin::getLocationFromGridPos(int x, int y) {
    return Vec2((float)x * cellWidth, scene->height() - cellHeight - (float)y * cellHeight);
}

#include "./sfml/include/SFML/Graphics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "");
    window.setFramerateLimit(60);
    sf::CircleShape circle(30, 70);

    circle.setPosition(50, 50);
    circle.setFillColor(sf::Color(100, 200, 30));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}

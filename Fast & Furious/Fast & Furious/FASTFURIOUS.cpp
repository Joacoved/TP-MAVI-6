#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight), "Fast & Furoius");
    App.setFramerateLimit(60);


    sf::CircleShape circle(50.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(0, windowHeight / 2 - circle.getRadius());


    float v0 = 300.0f;
    float vIncrement = 50.0f;
    float vFinal = 1000.0f;
    float currentSpeed = v0;


    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();
        }


        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();


        circle.move(currentSpeed * deltaTime, 0);


        if (circle.getPosition().x > windowWidth) {
            circle.setPosition(-circle.getRadius() * 2, circle.getPosition().y);
            currentSpeed += vIncrement;
            if (currentSpeed > vFinal) {
                currentSpeed = vFinal;
            }
        }


        App.clear();
        App.draw(circle);
        App.display();
    }

    return 0;
}

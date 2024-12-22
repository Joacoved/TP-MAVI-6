#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main() {
    
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight), "SPACE");
    App.setFramerateLimit(60);

    
    sf::CircleShape circle(50.0f); 
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(windowWidth / 2, windowHeight / 2);

    
    sf::Vector2f velocity(0.0f, 0.0f); 
    sf::Vector2f acceleration(0.0f, 0.0f); 
    const float maxSpeed = 500.0f; 
    const float friction = 0.95f; 
    const float accelerationRate = 200.0f; 

    
    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();
        }

        
        acceleration = sf::Vector2f(0.0f, 0.0f); 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            acceleration.x = -accelerationRate;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            acceleration.x = accelerationRate;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            acceleration.y = -accelerationRate;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            acceleration.y = accelerationRate;
        }

        
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

       
        velocity += acceleration * deltaTime;

        
        if (std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y) > maxSpeed) {
            float scale = maxSpeed / std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
            velocity *= scale;
        }

        
        velocity *= friction;

        
        circle.move(velocity * deltaTime);

        
        sf::Vector2f position = circle.getPosition();
        if (position.x < 0) position.x = 0;
        if (position.x + circle.getRadius() * 2 > windowWidth) position.x = windowWidth - circle.getRadius() * 2;
        if (position.y < 0) position.y = 0;
        if (position.y + circle.getRadius() * 2 > windowHeight) position.y = windowHeight - circle.getRadius() * 2;
        circle.setPosition(position);

        
        App.clear();
        App.draw(circle);
        App.display();
    }

    return 0;
}

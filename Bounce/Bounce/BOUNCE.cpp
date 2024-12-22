#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main() {
    
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight), "BOUNCE");
    App.setFramerateLimit(60);

    
    sf::CircleShape ball(50.0f); 
    ball.setFillColor(sf::Color::Green);
    ball.setPosition(windowWidth / 2 - ball.getRadius(), 0); 

   
    const float gravity = 980.f; 
    const float suelo = windowHeight - ball.getRadius() * 2; 
    float velocity = 0.0f; 
    const float rebote = 0.7f; 

    
    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();
        }

        
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        
        velocity += gravity * deltaTime;

        
        sf::Vector2f position = ball.getPosition();
        position.y += velocity * deltaTime;

        
        if (position.y >= suelo) {
            position.y = suelo; 
            velocity = -velocity * rebote; 

            
            if (std::abs(velocity) < 10.0f) {
                velocity = 0.0f;
            }
        }

        
        ball.setPosition(position);

        
        App.clear();
        App.draw(ball);
        App.display();
    }

    return 0;
}
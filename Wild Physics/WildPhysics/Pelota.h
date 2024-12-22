#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
private:
    sf::CircleShape ball;
    sf::Vector2f velocity;
    sf::Vector2f initialVelocity; // Velocidad inicial
    float gravity;
    sf::Vector2f initialPosition;

public:
    Pelota(float radius, sf::Color color, const sf::Vector2f& position, const sf::Vector2f& initialVelocity, float gravity = 0.0f);

    void move(float deltaTime);
    void reset(); // Restaura posición y velocidad inicial
    void handleBounds(const sf::Vector2u& windowSize);
    bool isHit(const sf::Vector2f& mousePos) const;

    const sf::CircleShape& getShape() const;
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);
};
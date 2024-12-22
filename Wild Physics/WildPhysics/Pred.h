#pragma once
#include <SFML/Graphics.hpp>

class RedBall {
public:
    RedBall(float radius, const sf::Vector2f& position);

    void update(float deltaTime, float windowWidth, float windowHeight, float speed);
    void reset(float windowHeight, float radius);

    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    float speed;
};
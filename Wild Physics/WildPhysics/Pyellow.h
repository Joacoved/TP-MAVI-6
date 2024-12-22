#pragma once
#include <SFML/Graphics.hpp>

class YellowBall {
public:
    YellowBall(float radius, const sf::Vector2f& position);

    void update(float deltaTime, float windowWidth, float windowHeight, float gravity);
    void reset(float windowHeight);
    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    float speedX, speedY;
};

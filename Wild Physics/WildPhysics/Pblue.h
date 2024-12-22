#pragma once
#include <SFML/Graphics.hpp>

class BlueBall {
public:
    BlueBall(float radius, const sf::Vector2f& position);

    void update(float deltaTime, float windowWidth, float windowHeight, float gravity);
    void reset(float windowHeight, float radius);

    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    float speedY;
};
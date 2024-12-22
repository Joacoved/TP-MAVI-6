#include "stdafx.h"
#include "Pred.h"

RedBall::RedBall(float radius, const sf::Vector2f& position) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    speed = 300.0f;
}

void RedBall::update(float deltaTime, float windowWidth, float windowHeight, float speed) {
    shape.move(0, speed * deltaTime);
    if (shape.getPosition().y > windowHeight) {
        reset(windowHeight, shape.getRadius());
    }
}

void RedBall::reset(float windowHeight, float radius) {
    shape.setPosition(shape.getPosition().x, -radius * 2);
}

sf::CircleShape RedBall::getShape() const {
    return shape;
}
#include "stdafx.h"
#include "Pgreen.h"

GreenBall::GreenBall(float radius, const sf::Vector2f& position) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
    speed = 200.0f;
}

void GreenBall::update(float deltaTime, float windowWidth, float windowHeight, float speed) {
    shape.move(speed * deltaTime, 0);
    if (shape.getPosition().x > windowWidth) {
        reset(windowHeight, shape.getRadius());
    }
}

void GreenBall::reset(float windowHeight, float radius) {
    shape.setPosition(-radius * 2, windowHeight / 4);
}

sf::CircleShape GreenBall::getShape() const {
    return shape;
}
#include "stdafx.h"
#include "Pyellow.h"

YellowBall::YellowBall(float radius, const sf::Vector2f& position) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
    speedX = 150.0f;
    speedY = -300.0f;
}

void YellowBall::update(float deltaTime, float windowWidth, float windowHeight, float gravity) {
    shape.move(speedX * deltaTime, speedY * deltaTime);
    speedY += gravity * deltaTime;

    
    if (shape.getPosition().x > windowWidth - shape.getRadius() * 2) {
        shape.setPosition(windowWidth - shape.getRadius() * 2, shape.getPosition().y);
        speedX = -std::abs(speedX);
    }
    if (shape.getPosition().x < 0) {
        shape.setPosition(0, shape.getPosition().y);
        speedX = std::abs(speedX);
    }
    if (shape.getPosition().y > windowHeight - shape.getRadius() * 2) {
        shape.setPosition(shape.getPosition().x, windowHeight - shape.getRadius() * 2);
        speedY = -std::abs(speedY);
    }
}

void YellowBall::reset(float windowHeight) {
    shape.setPosition(0, windowHeight / 2);
    speedX = 150.0f;
    speedY = -300.0f;
}

sf::CircleShape YellowBall::getShape() const {
    return shape;
}


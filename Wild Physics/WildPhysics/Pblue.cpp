#include "stdafx.h"
#include "Pblue.h"

BlueBall::BlueBall(float radius, const sf::Vector2f& position) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(position);
    speedY = -400.0f;
}

void BlueBall::update(float deltaTime, float windowWidth, float windowHeight, float gravity) {
    shape.move(0, speedY * deltaTime);
    speedY += gravity * deltaTime; 
    if (shape.getPosition().y > windowHeight - shape.getRadius() * 2) {
        reset(windowHeight, shape.getRadius());
    }
}

void BlueBall::reset(float windowHeight, float radius) {
    shape.setPosition(shape.getPosition().x, windowHeight - radius * 2);
    speedY = -400.0f;
}

sf::CircleShape BlueBall::getShape() const {
    return shape;
}
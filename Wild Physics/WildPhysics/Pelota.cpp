#include "Pelota.h"
#include <cmath>

Pelota::Pelota(float radius, sf::Color color, const sf::Vector2f& position, const sf::Vector2f& initialVelocity, float gravity)
    : ball(radius), velocity(initialVelocity), initialVelocity(initialVelocity), gravity(gravity), initialPosition(position) {
    ball.setFillColor(color);
    ball.setPosition(position);
}

void Pelota::move(float deltaTime) {
    velocity.y += gravity * deltaTime;
    ball.move(velocity * deltaTime);
}

void Pelota::reset() {
    ball.setPosition(initialPosition);
    velocity = initialVelocity; // Restaurar velocidad inicial
}

void Pelota::handleBounds(const sf::Vector2u& windowSize) {
    if (ball.getPosition().y > windowSize.y - ball.getRadius() * 2) {
        ball.setPosition(ball.getPosition().x, windowSize.y - ball.getRadius() * 2);
        velocity.y = -std::abs(velocity.y); // Rebote
    }
    if (ball.getPosition().x < 0 || ball.getPosition().x > windowSize.x - ball.getRadius() * 2) {
        velocity.x = -velocity.x;
    }
}

bool Pelota::isHit(const sf::Vector2f& mousePos) const {
    sf::Vector2f ballCenter = ball.getPosition() + sf::Vector2f(ball.getRadius(), ball.getRadius());
    return std::hypot(ballCenter.x - mousePos.x, ballCenter.y - mousePos.y) <= ball.getRadius();
}

const sf::CircleShape& Pelota::getShape() const {
    return ball;
}

void Pelota::setPosition(const sf::Vector2f& position) {
    ball.setPosition(position);
}

void Pelota::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}
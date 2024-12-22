#include "stdafx.h"
#include "Pgreen.h"
#include "Pred.h"
#include "Pblue.h"
#include "Pyellow.h"


bool isHit(const sf::CircleShape& ball, const sf::Vector2f& mousePos) {
    sf::Vector2f ballCenter = ball.getPosition() + sf::Vector2f(ball.getRadius(), ball.getRadius());
    return std::hypot(ballCenter.x - mousePos.x, ballCenter.y - mousePos.y) <= ball.getRadius();
}

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow App(sf::VideoMode(windowWidth, windowHeight), "WILDPHYSICS");
    App.setFramerateLimit(60);

    const float radius = 20.0f;
    sf::CircleShape greenBall(radius);
    greenBall.setFillColor(sf::Color::Green);
    greenBall.setPosition(0, windowHeight / 4);

    sf::CircleShape redBall(radius);
    redBall.setFillColor(sf::Color::Red);
    redBall.setPosition(windowWidth / 2, 0);

    sf::CircleShape blueBall(radius);
    blueBall.setFillColor(sf::Color::Blue);
    blueBall.setPosition(windowWidth / 4, windowHeight - 2 * radius);

    YellowBall yellowBall(radius, sf::Vector2f(0, windowHeight / 2));

    float greenSpeed = 200.0f;
    float redSpeed = 300.0f;
    float blueSpeedY = -400.0f;
    float yellowSpeedX = 150.0f, yellowSpeedY = -300.0f;

    const float gravity = 980.0f;

    App.setMouseCursorVisible(false);

    int score = 0;
    sf::Font font;
    if (!font.loadFromFile("Tiny5-Regular.ttf")) {
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo1.jpg")) {
        return -1;
    }
    sf::Sprite fondoSprite;
    fondoSprite.setTexture(fondoTexture);

    fondoSprite.setScale(
        static_cast<float>(windowWidth) / fondoTexture.getSize().x,
        static_cast<float>(windowHeight) / fondoTexture.getSize().y
    );

    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        return -1;
    }
    sf::Sprite crosshairSprite;
    crosshairSprite.setTexture(crosshairTexture);
    crosshairSprite.setOrigin(crosshairTexture.getSize().x / 2.0f, crosshairTexture.getSize().y / 2.0f);
    crosshairSprite.setScale(0.40f, 0.40f);

    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();

            if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(evt.mouseButton.x, evt.mouseButton.y);

                if (isHit(greenBall, mousePos)) {
                    greenBall.setPosition(0, windowHeight / 4);
                    score++;
                }
                if (isHit(redBall, mousePos)) {
                    redBall.setPosition(windowWidth / 2, 0);
                    score++;
                }
                if (isHit(blueBall, mousePos)) {
                    blueBall.setPosition(windowWidth / 4, windowHeight - 2 * radius);
                    blueSpeedY = -400.0f;
                    score++;
                }
                if (isHit(yellowBall.getShape(), mousePos)) {
                    yellowBall.reset(windowHeight);
                    score++;
                }
            }
        }

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        greenBall.move(greenSpeed * deltaTime, 0);
        if (greenBall.getPosition().x > windowWidth)
            greenBall.setPosition(-radius * 2, greenBall.getPosition().y);

        redBall.move(0, redSpeed * deltaTime);
        if (redBall.getPosition().y > windowHeight)
            redBall.setPosition(redBall.getPosition().x, -radius * 2);

        blueBall.move(0, blueSpeedY * deltaTime);
        blueSpeedY += gravity * deltaTime;
        if (blueBall.getPosition().y > windowHeight - radius * 2) {
            blueBall.setPosition(blueBall.getPosition().x, windowHeight - radius * 2);
            blueSpeedY = -400.0f;
        }

        yellowBall.update(deltaTime, windowWidth, windowHeight, gravity);

        std::stringstream ss;
        ss << "Puntuacion: " << score;
        scoreText.setString(ss.str());

        sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
        crosshairSprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        App.clear();
        App.draw(fondoSprite);
        App.draw(greenBall);
        App.draw(redBall);
        App.draw(blueBall);
        App.draw(yellowBall.getShape());
        App.draw(scoreText);
        App.draw(crosshairSprite);
        App.display();
    }

    return 0;
}



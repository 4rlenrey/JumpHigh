#include "Player/Player.h"

Player::Player()
    : Physical{20}, _rec{sf::RectangleShape{sf::Vector2f{20,20}}}
{
    _rec.setFillColor(sf::Color::White);
}

void Player::update(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        applyForce(sf::Vector2f{-1.0f, 0.0f});
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        applyForce(sf::Vector2f{1.0f, 0.0f});
    }
    else
    {
        applyForce(sf::Vector2f{0.0f, 0.0f});
    }

    Physical::update(deltaTime);
    _rec.setPosition(_position);
}
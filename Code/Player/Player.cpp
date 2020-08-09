#include "Player/Player.h"
#include "VectorFunctions/VectorFunctions.h"

const float Player::MAX_VELOCITY = 500.0f;
const float Player::RECTANGLE_SIZE = 20.0f;

Player::Player()
    : _rec{sf::RectangleShape{sf::Vector2f{RECTANGLE_SIZE, RECTANGLE_SIZE}}}
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
    _rec.setPosition(getPosition());
}

void Player::updateVelocity(float deltaTime)
{
    Physical::updateVelocity(deltaTime);
    
    if(length(getVelocity()) >= MAX_VELOCITY)
    {   
        setVelocity(normalized(getVelocity()) * MAX_VELOCITY); //setting velocity to max speed
    }
}
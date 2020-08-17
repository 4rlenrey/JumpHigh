#include "Player/Player.h"
#include "VectorFunctions/VectorFunctions.h"

const float Player::MAX_VELOCITY = 500.0f;
const float Player::RECTANGLE_SIZE = 20.0f;

Player::Player()
{

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        jump();
        jumping = true;
    }
    else
    {
        jumping = false;
    }

    Physical::update(deltaTime);
}

void Player::jump()
{
    setVelocity(sf::Vector2f{getVelocity().x, -1000.0f});
}

void Player::updateVelocity(float deltaTime)
{
    Physical::updateVelocity(deltaTime);
    
    if(std::abs(getVelocity().x) >= MAX_VELOCITY)
    {   
        if(getVelocity().x > 0.0f)
        {
            setVelocity(sf::Vector2f{MAX_VELOCITY, getVelocity().y}); //setting velocity to max speed
        }
        else
        {
            setVelocity(sf::Vector2f{-MAX_VELOCITY, getVelocity().y}); //setting velocity to max speed
        }
    }
    if(getPosition().y >= 600 && !jumping)
    {
        setVelocity(sf::Vector2f{getVelocity().x, 0.0f});
    }
}
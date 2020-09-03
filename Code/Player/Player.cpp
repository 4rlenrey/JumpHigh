#include "Player/Player.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Input/Input.h"

const float Player::MAX_VELOCITY = 500.0f;
const float Player::RECTANGLE_SIZE = 20.0f;
const float Player::JUMP_VELOCITY = 1200.0f;

Player::Player()
{

}

void Player::update(float deltaTime)
{
    if(Input::A.isPressed())
    {
        applyForce(sf::Vector2f{-1.0f, 0.0f});
    }
    else if(Input::D.isPressed())
    {
        applyForce(sf::Vector2f{1.0f, 0.0f});
    }
    else
    {
        applyForce(sf::Vector2f{0.0f, 0.0f});
    }

    if(Input::Space.justPressed() & !jumping)
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
    float jumpSpeed = -(JUMP_VELOCITY * (1 + abs(getVelocity().x)/MAX_VELOCITY)); //when moving fast in x axis then jumping higher
    setVelocity(sf::Vector2f{getVelocity().x, jumpSpeed});
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
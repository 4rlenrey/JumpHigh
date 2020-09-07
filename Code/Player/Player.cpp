#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Input/Input.h"
#include <iostream>

const float Player::MAX_VELOCITY = 500.0f;
const float Player::RECTANGLE_SIZE = 20.0f;
const float Player::JUMP_VELOCITY = 1200.0f;

#define vecRight sf::Vector2f{1.0f, 0.0f}
#define vecLeft sf::Vector2f{-1.0f, 0.0f}
#define vecUp sf::Vector2f{0.0f, -1.0f}
#define vecDown sf::Vector2f{0.0f, 1.0f}
#define vecZero sf::Vector2f{0.0f, 0.0f}


Player::Player()
{

}

void Player::update(float deltaTime)
{
    applyCollisionForces();
    if(Input::A.isPressed())
    {
        applyForce(vecLeft);
    }
    else if(Input::D.isPressed())
    {
        applyForce(vecRight);
    }
    else
    {
        applyForce(vecZero);
    }

    if(Input::Space.justPressed() & !jumping)
    {
        jump();
    }

    Physical::update(deltaTime);
}

void Player::jump()
{
    float jumpSpeed = -(JUMP_VELOCITY * (1 + abs(getVelocity().x)/MAX_VELOCITY)); //when moving fast in x axis then jumping higher
    setVelocity(sf::Vector2f{getVelocity().x, jumpSpeed});
    jumping = true;
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

void Player::applyForce(const sf::Vector2f& force)
{
    if(_collisionInfo.bottom)
    {
        _force = force;
    }
    else
    {
        Physical::applyForce(force);
    }
}
void Player::applyCollisionForces()
{
    // if(_collisionInfo.left)
    // {
    //     // if(getVelocity().x <= 0)
    //     // {
    //     //     setVelocity(sf::Vector2f{0.0f, getVelocity().y});
    //     // }
    // }
    
    // if(_collisionInfo.right)
    // {
    //     // if(getVelocity().x >= 0)
    //     // {
    //     //     setVelocity(sf::Vector2f{0.0f, getVelocity().y});
    //     // }
    // }
    
    if(_collisionInfo.bottom)
    {
        standing = true;
        if(getVelocity().y >= 0.0f)
        {
            jumping = false;
            setVelocity(sf::Vector2f{getVelocity().x, 0.0f});
        }
        if(getAcceleration().y > 0.0f)
        {
            setAcceleration(sf::Vector2f{getAcceleration().x, 0.0f} - Physical::GRAVITY_FORCE);
        }
        for(auto objPtr : _collisionInfo.collided)
        {
            _position.y = objPtr->getPosition().y - _box.getSize().y;
        }
    }
    
    // if(_collisionInfo.top)
    // {
    //     //we want to be able to jump over the platforms so nothing here...
    // }
}
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "VectorFunctions/VectorFunctions.h"
#include "Input/Input.h"
#include <iostream>

const float Player::MAX_VELOCITY = 1000.0f;
const float Player::RECTANGLE_SIZE = 20.0f;
const float Player::JUMP_VELOCITY = 800.0f;
const float Player::HIGH_JUMP_THRESHOLD = 0.8f;

const sf::Vector2f vecRight = sf::Vector2f{1.0f, 0.0f};
const sf::Vector2f vecLeft  = sf::Vector2f{-1.0f, 0.0f};
const sf::Vector2f vecUp    = sf::Vector2f{0.0f, -1.0f};
const sf::Vector2f vecDown  = sf::Vector2f{0.0f, 1.0f};
const sf::Vector2f vecZero  = sf::Vector2f{0.0f, 0.0f};


Player::Player()
{
    _animationSystem.selectAnimation("Idle");
    _sprite.setTexture(_animationSystem.getAnimation()->getImages()[0]);
    sf::Vector2u textureSize = _sprite.getTexture()->getSize();
    _sprite.setOrigin(textureSize.x/3.0f, textureSize.y/3.0f); //No idea why division by 3 suits it but now negative scale doesn't teleport hero
}

void Player::update(float deltaTime)
{
    applyCollisionForces();
    reactToInput();
    animationSelectionBasedOnState();

    Physical::update(deltaTime);

    _jumping ? _animationSystem.animate(_sprite, true) : _animationSystem.animate(_sprite);
    _prevJumping = _jumping;
}

void Player::jump()
{
    float jumpSpeed = -(JUMP_VELOCITY * (0.9f + (abs(getVelocity().x)/MAX_VELOCITY))); //when moving fast in x axis then jumping higher
    setVelocity(sf::Vector2f{getVelocity().x, jumpSpeed});
    _jumping = true;
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

    if(getPosition().x < 200 && getVelocity().x < 0 && _jumping)
    {
        _velocity.x = -_velocity.x;
    }
    if(getPosition().x > 1000 && getVelocity().x > 0 && _jumping)
    {
        _velocity.x = -_velocity.x;
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
    //     if(isHighSpeed() && getVelocity().x < 0)
    //     {
    //         setVelocity(sf::Vector2f{-getVelocity().x, getVelocity().y});
    //     }
    // }
    
    // if(_collisionInfo.right)
    // {
    //     if(isHighSpeed() && getVelocity().x > 0)
    //     {
    //         setVelocity(sf::Vector2f{-getVelocity().x, getVelocity().y});
    //     }
    // }
    
    if(_collisionInfo.bottom)
    {
        _standing = true;
        if(getVelocity().y >= 0.0f)
        {
            _jumping = false;
            setVelocity(sf::Vector2f{getVelocity().x, 0.0f});
        }

        setAcceleration(sf::Vector2f{getAcceleration().x, 0.0f} - Physical::GRAVITY_FORCE);
    }
    else
    {
        _standing = false;
        _jumping = true;
    }
    
    // if(_collisionInfo.top)
    // {
    //     //we want to be able to jump over the platforms so nothing here...
    // }
}

void Player::reactToInput()
{
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

    if(Input::Space.justPressed() & !_jumping)
    {
        jump();
    }
}

void Player::animationSelectionBasedOnState()
{
    if(Input::A.isPressed())
    {
        _sprite.setScale(sf::Vector2f{-1.0f, 1.0f});
    }
    else if(Input::D.isPressed())
    {
        _sprite.setScale(sf::Vector2f{1.0f, 1.0f});
    }

    if(!_jumping)
    {
        if(Input::A.isPressed())
        {
            _animationSystem.selectAnimation("Run");
        }
        else if(Input::D.isPressed())
        {
            _animationSystem.selectAnimation("Run");
        }
        else
        {
            _animationSystem.selectAnimation("Idle");
        }
    }

    if(justJumped() && getVelocity().y <= 0)
    {
        if(Input::Space.justPressed() && _jumping && isHighSpeed())
        {
            _animationSystem.selectAnimation("High_Jump");
        }
        else if(Input::Space.justPressed() && _jumping)
        {
            _animationSystem.selectAnimation("Jump");
        }
    }
}

bool Player::justJumped()
{
    if(!_prevJumping && _jumping)
    {
        return true;
    }
    return false;
}

bool Player::isHighSpeed()
{
    if(std::abs(_velocity.x) > HIGH_JUMP_THRESHOLD * MAX_VELOCITY)
    {
        return true;
    }
    return false;
}

void Player::updateSprite()
{
    _sprite.setPosition(_position + sf::Vector2f{_sprite.getTexture()->getSize().x/6.0f, 0.0f}); 
}

void Player::updateBox()
{
    _box.setPosition(_position);
    
    sf::Vector2f size{_sprite.getTexture()->getSize().x/3.0f, _sprite.getTexture()->getSize().y/2.0f};

    _box.setSize(size);
}

void Player::reset()
{
    _position = sf::Vector2f{600.0f, 500.0f};
    _box.setPosition(_position);
    _collisionInfo = collisionInfo{};
}
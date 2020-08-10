#include "Physical.h"
#include "VectorFunctions/VectorFunctions.h"
#include <iostream>


const float Physical::DEFAULT_MASS = 1.0f;
const float Physical::ACCELERATION_SCALE = 5000.0f; 
const float Physical::GENERAL_FRICTION_FORCE_VALUE = 0.3f;
const float Physical::MIN_SPEED_THRESHOLD = 1e-6;
const sf::Vector2f Physical::GRAVITY_FORCE = sf::Vector2f{0.0f, 0.6f};

Physical::Physical(float mass)
    : _mass{mass}, _decelerationValue{(GENERAL_FRICTION_FORCE_VALUE / _mass) * ACCELERATION_SCALE}
{
}

void Physical::applyForce(sf::Vector2f force)
{
    _force = force + GRAVITY_FORCE; 
}

void Physical::updateAcceleration()
{
    _acceleration = (_force/_mass) * ACCELERATION_SCALE;
}

void Physical::updateVelocity(float deltaTime)
{   
    _velocity += _acceleration * deltaTime;

    if(std::abs(_velocity.x) < MIN_SPEED_THRESHOLD)
    {
        _velocity.x = 0.0f; //stop object's horizontal movement (no sliding)
    }
    
    if(length(_velocity))
    {
        _velocity -= normalized(_velocity) * _decelerationValue * deltaTime;  //slow down object when moving
    }
}

void Physical::updatePosition(float deltaTime)
{
    _position += _velocity * deltaTime;
}

void Physical::update(float deltaTime)
{
    updateAcceleration();
    updateVelocity(deltaTime);
    updatePosition(deltaTime);
}

float Physical::getMass() const
{
    return _mass;
}

const sf::Vector2f& Physical::getPosition() const
{
    return _position;
}

const sf::Vector2f& Physical::getVelocity() const
{
    return _velocity;
}

void Physical::setVelocity(sf::Vector2f&& vec)
{
    _velocity = vec;
}

std::ostream& operator<<(std::ostream& out, const Physical& obj)
{
    out << "Physical Object Debug Info--------------------" << std::endl 
        << "Position " << obj._position << std::endl
        << "Velocity " << obj._velocity << std::endl
        << "Force " << obj._force << std::endl;

    return out;
}


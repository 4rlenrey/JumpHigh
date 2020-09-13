#include "Physical.h"
#include "VectorFunctions/VectorFunctions.h"
#include <iostream>


const float Physical::DEFAULT_MASS = 1.0f;
const float Physical::ACCELERATION_SCALE = 7000.0f; 
const float Physical::GENERAL_FRICTION_FORCE_VALUE = 0.2f;
const float Physical::MIN_SPEED_THRESHOLD = 1e-4;
const sf::Vector2f Physical::GRAVITY_FORCE = sf::Vector2f{0.0f, 1.0f};

Physical::Physical(float mass)
    : _mass{mass}, _decelerationValue{(GENERAL_FRICTION_FORCE_VALUE / _mass) * ACCELERATION_SCALE}
{
}

Physical::~Physical(){}

void Physical::applyForce(const sf::Vector2f& force)
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
    
    if(std::abs(_velocity.x))
    {
        _velocity -= normalized(sf::Vector2f{_velocity.x, 0.0f}) * _decelerationValue * deltaTime;  //slow down object when moving
    }
}

void Physical::updatePosition(float deltaTime)
{
    _position += _velocity * deltaTime;
}

void Physical::update(float deltaTime)
{
    GameObject::update(deltaTime);
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

const sf::Vector2f& Physical::getAppliedForce() const
{
    return _force;
}

const sf::Vector2f& Physical::getAcceleration() const
{
    return _acceleration;
}

void Physical::setMass(float mass)
{
    _mass = mass;
}
void Physical::setVelocity(const sf::Vector2f& vec)
{
    _velocity = vec;
}

void Physical::setAcceleration(const sf::Vector2f& accel)
{
    _acceleration = accel;
}

std::ostream& operator<<(std::ostream& out, const Physical& obj)
{
    out << "Physical Object Debug Info--------------------" << std::endl 
        << "Position " << obj._position << std::endl
        << "Velocity " << obj._velocity << std::endl
        << "Force " << obj._force << std::endl;

    return out;
}


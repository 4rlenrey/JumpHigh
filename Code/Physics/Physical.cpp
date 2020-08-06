#include "Physical.h"

Physical::Physical(float mass = 2.0f)
    : _mass{mass}, _force{sf::Vector2f{0.0f,0.0f}}, _velocity{sf::Vector2f{0.0f, 0.0f}}
{
    //nothing yet
}

void Physical::addForce(sf::Vector2f force)
{
    _force += force;
}

void Physical::updateAcceleration()
{
    _acceleration = _force/_mass;
}

void Physical::updateVelocity(float deltaTime)
{   
    _velocity += _acceleration * deltaTime; 
}

void Physical::update(float deltaTime)
{
    updateAcceleration();
    updateVelocity(deltaTime);
}

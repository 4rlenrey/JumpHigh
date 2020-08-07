#include "Physical.h"
#include "VectorFunctions/VectorFunctions.h"
#include <iostream>

Physical::Physical(float mass = 1.0f)
    : _mass{mass}
{
    //nothing yet
}

void Physical::applyForce(sf::Vector2f force)
{
    _force = force;
}

void Physical::updateAcceleration()
{
    _acceleration = (_force/_mass) * 10000.0f;
}

void Physical::updateVelocity(float deltaTime)
{   
    _velocity += _acceleration * deltaTime; 
}

void Physical::updatePosition(float deltaTime)
{
    //std::cout << deltaTime << std::endl;
    _position += _velocity * deltaTime;
}

void Physical::update(float deltaTime)
{
    updateAcceleration();
    updateVelocity(deltaTime);
    updatePosition(deltaTime);
}

std::ostream& operator<<(std::ostream& out, const Physical& obj)
{
    out << "Physical Object Debug Info--------------------" << std::endl 
        << "Position " << obj._position << std::endl
        << "Velocity " << obj._velocity << std::endl
        << "Force " << obj._force << std::endl;

    return out;
}
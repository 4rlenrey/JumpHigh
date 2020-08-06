#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <SFML/Graphics.hpp>

class Physical
{
    public:
    Physical(float mass);
    void addForce(sf::Vector2f force);
    void update(float deltaTime);
    void updateVelocity(float deltaTime);
    void updateAcceleration();

    private:
    float _mass;
    sf::Vector2f _force;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
};

#endif
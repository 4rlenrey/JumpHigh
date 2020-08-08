#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <ostream>
#include <SFML/Graphics.hpp>

class Physical
{
    friend std::ostream& operator<<(std::ostream& out, const Physical& obj);

    public:
    static const float DEFAULT_MASS;
    static const float ACCELERATION_SCALE;

    Physical(float mass = DEFAULT_MASS);
    void applyForce(sf::Vector2f force);
    void update(float deltaTime);
    void updateAcceleration();
    void updatePosition(float deltaTIme);
    
    virtual void updateVelocity(float deltaTime);

    protected:
    float _mass;
    sf::Vector2f _force;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
    sf::Vector2f _position;
};

std::ostream& operator<<(std::ostream& out, const Physical& obj);

#endif
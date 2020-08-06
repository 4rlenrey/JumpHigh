#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <SFML/Graphics.hpp>

class Physical
{
    public:

    void addForce();
    void calculateVelocity();
    void update();

    private:
    float mass;
    sf::Vector2f velocity;
};

#endif
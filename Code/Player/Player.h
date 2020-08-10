#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Physics/Physical.h"

class Player : public Physical
{
    public:
    static const float MAX_VELOCITY;
    static const float RECTANGLE_SIZE; //We can get rid of it later when collision system is finnished
    
    Player();

    void update(float deltaTime);
    void jump();
    
    sf::RectangleShape _rec;

    private:
    void updateVelocity(float deltaTime) override;
    bool jumping;
};

#endif
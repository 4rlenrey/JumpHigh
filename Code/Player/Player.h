#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Physics/Physical.h"

class Player : public Physical
{
    public:
    Player();

    void update(float deltaTime);
    void jump();
    sf::RectangleShape _rec;
    private:
    
};

#endif
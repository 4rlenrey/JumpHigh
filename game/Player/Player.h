#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    public:

    void update();
    void jump();
    
    private:
    sf::Vector2f pos;
};

#endif
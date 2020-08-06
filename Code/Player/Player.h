#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <Physics/Physical.h>

class Player : public Physical
{
    public:

    void update();
    void jump();
};

#endif
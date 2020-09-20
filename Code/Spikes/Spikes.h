#ifndef SPIKES_H
#define SPIKES_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

class Spikes
{
    public: 
    Spikes();
    void update(float);
    void reset();
    sf::Vector2f position;
    static sf::Texture spikesTexture;
    sf::Sprite _sprite;

};

#endif

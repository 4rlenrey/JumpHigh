#ifndef SPIKES_H
#define SPIKES_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

class Spikes : public GameObject
{
public:
    static sf::Texture spikesTexture;
    Spikes();

    void update(float);
    void reset();

    sf::Sprite &getSprite();
};

#endif

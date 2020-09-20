#include "Spikes/Spikes.h"
#include <SFML/Graphics.hpp>

sf::Texture Spikes::spikesTexture;

Spikes::Spikes()
{
    position = sf::Vector2f{0.0f, 700.0f};
    _sprite.setTexture(spikesTexture);
    _sprite.setPosition(position);
    _sprite.setScale(5,5);
}

void Spikes::update(float deltaTime)
{
    _sprite.move(sf::Vector2f{0.0f, -150*deltaTime});
}

void Spikes::reset()
{
    position = sf::Vector2f{0.0f, 700.0f};
    _sprite.setPosition(position);
}
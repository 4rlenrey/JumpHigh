#include "Spikes/Spikes.h"
#include <SFML/Graphics.hpp>

sf::Texture Spikes::spikesTexture;

Spikes::Spikes()
{
    _position = sf::Vector2f{0.0f, 700.0f};
    _sprite.setTexture(spikesTexture);
    _sprite.setPosition(_position);
    _sprite.setScale(5,5);
}

void Spikes::update(float deltaTime)
{
    _position.y -= 100 * deltaTime;
    _sprite.setPosition(_position);
}

void Spikes::reset()
{
    _position = sf::Vector2f{0.0f, 700.0f};
    _sprite.setPosition(_position);
}

sf::Sprite& Spikes::getSprite()
{
    return _sprite;
}
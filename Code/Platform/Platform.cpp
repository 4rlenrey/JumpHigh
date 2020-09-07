#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture Platform::TEXTURE;

void Platform::loadTexture(const std::string& path)
{
    TEXTURE.loadFromFile(path);
}

Platform::Platform(const sf::Vector2f& pos, const sf::Vector2f& boxSize)
    : GameObject(pos, boxSize)
{
    _sprite.setTexture(TEXTURE);
    
    update();    
}

void Platform::updateBox()
{
    _box.setPosition(_position);
    _box.setSize(sf::Vector2f{static_cast<float>(TEXTURE.getSize().x), static_cast<float>(TEXTURE.getSize().y)});
}

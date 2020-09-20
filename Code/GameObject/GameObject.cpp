#include "GameObject/GameObject.hpp"
#include <algorithm>
#include <iostream>

std::vector<GameObject*> GameObject::gameObjects = {};

GameObject::GameObject()
    : _box{sf::RectangleShape{sf::Vector2f{10,10}}}
{
    //gameObjects.push_back(this);
}

GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& boxSize)
    : _position{pos}, _box{sf::RectangleShape{boxSize}}
{
    //gameObjects.push_back(this);
}

GameObject::~GameObject()
{
    gameObjects.erase(std::remove(begin(gameObjects), end(gameObjects), this), end(gameObjects));
}

void GameObject::reset()
{
    _position = sf::Vector2f{};
    _box.setPosition(_position);
    _collisionInfo = collisionInfo{};
}

const sf::Vector2f& GameObject::getPosition() const
{
    return _position;
}

const sf::RectangleShape& GameObject::getRectangleShape() const
{
    return _box;
}

const sf::Sprite& GameObject::getSprite() const
{
    return _sprite;
}

void GameObject::update(float deltaTime)
{
    updateBox();
    updateSprite();
}

void GameObject::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(_sprite);
}

void GameObject::updateSprite()
{
    _sprite.setPosition(_position);
}

void GameObject::updateBox()
{
    _box.setPosition(_position);
}

void GameObject::updateCollisionInfo(const collisionInfo& info)
{
    for(auto objPtr : info.collided)
    {
        _collisionInfo.collided.push_back(objPtr);
    }

    if(!_collisionInfo.left && info.left)
    {
        _collisionInfo.left = true;
    }
    
    if(!_collisionInfo.right && info.right)
    {
        _collisionInfo.right = true;
    }
    
    if(!_collisionInfo.top && info.top)
    {
        _collisionInfo.top = true;
    }
    
    if(!_collisionInfo.bottom && info.bottom)
    {
        _collisionInfo.bottom = true;
    }

}

void GameObject::resetCollisionInfo()
{
    _collisionInfo.collided.clear();
    _collisionInfo = collisionInfo{};
}

void GameObject::setPosition(const sf::Vector2f& pos)
{
    _position = pos;
}
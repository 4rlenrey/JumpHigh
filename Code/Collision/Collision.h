#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

struct hitbox 
{
  hitbox(const GameObject& obj);
  const sf::Vector2f& _position;
  const sf::Vector2f& _size;
  float left;
  float right;
  float top;
  float bottom;
};

bool checkCollision(const GameObject& Obj1, const GameObject& Obj2);


#endif

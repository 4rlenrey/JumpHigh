#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

struct hitbox {
  sf::Vector2f Position;
  sf::Vector2f Size;
};

bool checkCollision(sf::RectangleShape Obj1, sf::RectangleShape Obj2);


#endif

#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

struct hitbox {
  sf::Vector2f Position;
  sf::Vector2f Size;
};

class Collision
{
  public:
   Collision(sf::RectangleShape Obj1, sf::RectangleShape Obj2)
   {
      _hitbox1.Position = Obj1.getPosition();
      _hitbox1.Size = Obj1.getSize();

      _hitbox2.Position = Obj2.getPosition();
      _hitbox2.Size = Obj2.getSize();
    }

  private:
    hitbox _hitbox1;
    hitbox _hitbox2;
    bool checkCollision();
};

#endif

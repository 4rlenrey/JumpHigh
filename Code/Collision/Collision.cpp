#include "Collision.h"
#include "iostream"

// Size.x == width
// Size.y == height

bool checkCollision(sf::RectangleShape Obj1, sf::RectangleShape Obj2)
{
  hitbox _hitbox1;
  hitbox _hitbox2;

  _hitbox1.Size = Obj1.getSize();
  _hitbox1.Position = Obj1.getPosition();

  _hitbox2.Size = Obj2.getSize();
  _hitbox2.Position = Obj2.getPosition();

  if(
    _hitbox1.Position.x < (_hitbox2.Size.x + _hitbox2.Position.x) &&
    (_hitbox1.Position.x + _hitbox1.Size.x) > _hitbox2.Position.x &&
    _hitbox1.Position.y < (_hitbox2.Size.y + _hitbox2.Position.y) &&
    (_hitbox1.Position.y + _hitbox1.Size.y) > _hitbox2.Position.y
    )
      {
        return true;
      }

    return false;
}

#include "Collision.h"

// Size.x == width
// Size.y == height

bool Collision::checkCollision()
{
  if(
    (_hitbox1.Position.x + _hitbox1.Size.x) >= _hitbox2.Position.x &&
    (_hitbox2.Position.x + _hitbox2.Size.x) >= _hitbox1.Position.x &&
    (_hitbox1.Position.y + _hitbox1.Size.y) >= _hitbox2.Position.y &&
    (_hitbox2.Position.y + _hitbox2.Size.y) >= _hitbox1.Position.y
    )
      {
        return true;
      }

    return false;
}

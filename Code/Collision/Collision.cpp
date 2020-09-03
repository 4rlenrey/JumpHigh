#include "Collision.h"
#include "iostream"
#include "GameObject/GameObject.hpp"

hitbox::hitbox(const GameObject& obj)
  : _position{obj.getPosition()}, _size{obj.getRectangleShape().getSize()},
  right{_position.x + _size.x}, left{_position.x - _size.x},
  top{_position.y - _size.y}, bottom{_position.y + _size.y}
{
}

bool checkCollision(const GameObject& obj1, const GameObject& obj2)
{
  hitbox hitbox1{obj1};
  hitbox hitbox2{obj2};

  if(
    (
    hitbox1.left <= hitbox2.left && hitbox1.right >= hitbox2.left ||
    hitbox1.right >= hitbox2.right && hitbox1.left <= hitbox2.right )&&(
    hitbox1.bottom >= hitbox2.bottom && hitbox1.top <= hitbox2.bottom ||
    hitbox1.top <= hitbox2.top && hitbox1.bottom >= hitbox2.top
    ))
  {
    return true;
  }

  return false;

}

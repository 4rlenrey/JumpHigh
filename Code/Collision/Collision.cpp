#include "Collision.h"
#include <iostream>
#include "GameObject/GameObject.hpp"

hitbox::hitbox(const GameObject& obj)
  : _position{obj.getPosition()}, _size{obj.getRectangleShape().getSize()},
  right{_position.x + _size.x}, left{_position.x},
  top{_position.y}, bottom{_position.y + _size.y}
{
}

std::ostream& operator<<(std::ostream& out, hitbox& hit)
{
  out << "{ " << hit.left << ", " << hit.right << ", " << hit.top << ", " << hit.bottom << " }";
  return out;
}

void collisionInfo::setMirroredInfo()
{
  if(left || right)
  {
    left = !left;
    right = !right;
  }

  if(top || bottom)
  {
    top = !top;
    bottom = !bottom;  
  }

}

void collisionInfo::setLeft()
{
  left = true;
}

void collisionInfo::setRight()
{
  right = true;
}

void collisionInfo::setTop()
{
  top = true;
}

void collisionInfo::setBottom()
{
  bottom = true;
}

bool checkCollision(GameObject& obj1, GameObject& obj2)
{
  hitbox hitbox1{obj1};
  hitbox hitbox2{obj2};
  collisionInfo info;

  if(
    (hitbox1.left >= hitbox2.left && hitbox1.left <= hitbox2.right ||
    hitbox1.right >= hitbox2.left && hitbox1.right <= hitbox2.right) &&
    (hitbox1.top >= hitbox2.top && hitbox1.top <= hitbox2.bottom ||
    hitbox1.bottom >= hitbox2.top && hitbox1.bottom <= hitbox2.bottom)
    )
  {
    if(hitbox1.top <= hitbox2.top && hitbox1.bottom >= hitbox2.top)       {info.setBottom();}
    if(hitbox1.bottom >= hitbox2.bottom && hitbox1.top <= hitbox2.bottom) {info.setTop();}
    if(hitbox1.left <= hitbox2.left && hitbox1.right >= hitbox2.left)     {info.setRight();}
    if(hitbox1.right >= hitbox2.right && hitbox1.left <= hitbox2.right)   {info.setLeft();}
    
    info.collided.push_back(&obj2);
    obj1.updateCollisionInfo(info);
    info.setMirroredInfo();
    info.collided.push_back(&obj1);
    obj2.updateCollisionInfo(info);
    return true;
  }

  return false;
}

void checkAllCollisions()
{
  for(auto it = std::begin(GameObject::gameObjects); it != std::end(GameObject::gameObjects); it++)
  {
    for(auto yeet = it + 1; yeet != std::end(GameObject::gameObjects); yeet++)
    {
      checkCollision(*(*it), *(*yeet));
    }
  }
}

void resetAllCollisions()
{
  for(auto it = std::begin(GameObject::gameObjects); it != std::end(GameObject::gameObjects); it++)
  {
    (*it)->resetCollisionInfo();
  }
}
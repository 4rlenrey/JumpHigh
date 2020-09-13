#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

class GameObject; //forward declaration... basically bad code structure but lets just ommit it for now...

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

struct collisionInfo
{
  bool left   = false;
  bool right  = false;
  bool top    = false;
  bool bottom = false;
  std::vector<GameObject*> collided;

  void setLeft();
  void setRight();
  void setTop();
  void setBottom();
  void setMirroredInfo();

  bool operator!=(const collisionInfo& test)
  {
    if(left != test.left || right != test.right || top != test.top || bottom != test.bottom)
    {
      return true;
    }
    return false;
  }

};

void drawHitbox(sf::RenderTarget& window,GameObject& obj);
bool checkCollision(GameObject& Obj1, GameObject& Obj2);
void checkAllCollisions(const GameObject&);
void resetAllCollisions();

#endif

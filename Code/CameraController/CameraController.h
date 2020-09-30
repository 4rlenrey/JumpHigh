#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

class CameraController
{
    public:
    CameraController(GameObject& objToFollow);
    void update(float deltaTime);
    void reset(const sf::Vector2f& pos);
    
    sf::View& getView();

    private:
    GameObject* _obj;
    sf::View _view;

};

#endif
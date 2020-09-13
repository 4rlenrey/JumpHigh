#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

class CameraController
{
    public:
    CameraController(GameObject& objToFollow)
        : _obj{objToFollow}, _view{sf::Vector2f{1280.0f/2.0f, 720.0f/2.0f}, sf::Vector2f{1280, 720}}
    {
    }

    void update(float deltaTime)
    {
        const float distance = _obj.getPosition().y - _view.getCenter().y;
    
        if(distance < -20)
        {
            _view.move(sf::Vector2f{0.0f, 2*distance*deltaTime});
        }
    }

    sf::View& getView()
    {
        return _view;
    }
    private:
    GameObject& _obj;
    sf::View _view;

};

#endif
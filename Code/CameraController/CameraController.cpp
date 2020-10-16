#include "CameraController.h"

CameraController::CameraController(GameObject &objToFollow)
    : _obj{&objToFollow}, _view{sf::Vector2f{1280.0f / 2.0f, 720.0f / 2.0f}, sf::Vector2f{1280, 720}}
{
}

void CameraController::update(float deltaTime)
{
    const float distance = _obj->getPosition().y - _view.getCenter().y;

    if (distance < -20)
    {
        _view.move(sf::Vector2f{0.0f, 2 * distance * deltaTime});
    }
}

void CameraController::reset(const sf::Vector2f &pos)
{
    _view.setCenter(pos);
}

sf::View &CameraController::getView()
{
    return _view;
}
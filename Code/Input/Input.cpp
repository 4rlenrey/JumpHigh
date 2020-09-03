#include <SFML/Graphics.hpp>
#include "Input.h"

void ButtonStates::operator=(bool val)
{
    _previousState = _currentState;
    _currentState = val;
    checkButtonJustPressed();
    checkButtonJustReleased();
}

void ButtonStates::checkButtonJustPressed()
{
    (!_previousState && _currentState) ? _justPressed = true : _justPressed = false;
}

void ButtonStates::checkButtonJustReleased()
{
    (_previousState && !_currentState) ? _justReleased = true : _justReleased = false;
}

bool ButtonStates::isPressed()
{
    return _currentState;
}

bool ButtonStates::justPressed()
{
    return _justPressed;
}

bool ButtonStates::justReleased()
{
    return _justReleased;
}

ButtonStates Input::W;
ButtonStates Input::A;
ButtonStates Input::S;
ButtonStates Input::D;
ButtonStates Input::Space;
ButtonStates Input::Escape;

void Input::update()
{
    sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? Input::W = true : Input::W = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::A) ? Input::A = true : Input::A = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? Input::S = true : Input::S = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::D) ? Input::D = true : Input::D = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ? Input::Space = true : Input::Space = false;
    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ? Input::Escape = true : Input::Escape = false;
}
#include "Score/Score.h"
#include "GameObject/GameObject.hpp"
#include <string>
#include <SFML/Graphics.hpp>

sf::Font Score::font;

Score::Score(GameObject &player, sf::View &view)
    : _player{player}, _view{view}
{
    _score = 0;
    _text.setString("0");
    _text.setFont(font);
    _text.setPosition(100, 500);
    _text.setCharacterSize(35);
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(10, _view.getCenter().y - 350);
}

void Score::update()
{
    if (_score < -(_player.getPosition().y))
    {
        _score = -(_player.getPosition().y);
    }

    _text.setString(SCORE + std::to_string(_score));
    _text.setPosition(10, _view.getCenter().y - 350);
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_text);
}

void Score::reset()
{
    _score = 0;
}

sf::Text &Score::getText()
{
    return _text;
}
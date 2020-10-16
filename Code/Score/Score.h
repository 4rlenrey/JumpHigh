#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"
#include <string>

class Score : public GameObject
{
public:
    static sf::Font font;

    Score(GameObject &player, sf::View &viev);

    void update();
    void reset();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Text &getText();

private:
    const std::string SCORE = "Score:";
    long long _score;
    sf::Text _text;
    GameObject &_player;
    sf::View &_view;
};

#endif
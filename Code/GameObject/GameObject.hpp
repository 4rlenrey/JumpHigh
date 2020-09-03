#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <SFML/Graphics.hpp>

class GameObject
{
    public:
    GameObject()
        : _box{sf::RectangleShape{sf::Vector2f{10,10}}}
    {
    };

    const sf::Vector2f& getPosition() const
    {
        return _position;
    }
    
    const sf::RectangleShape& getRectangleShape() const
    {
        return _box;
    }

    virtual void update(float deltaTime)
    {
        updateBox();
    }

    void updateBox()
    {
        _box.setPosition(_position);
    }

    protected:
    sf::Vector2f _position;
    sf::RectangleShape _box;
};

#endif
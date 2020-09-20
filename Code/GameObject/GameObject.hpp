#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <SFML/Graphics.hpp>
#include "Collision/Collision.h"
#include <vector>

class GameObject : public sf::Drawable
{
    public:
    static std::vector<GameObject*> gameObjects;
    GameObject();
    GameObject(const sf::Vector2f&, const sf::Vector2f& boxSize = sf::Vector2f{});

    virtual ~GameObject();

    virtual void update(float deltaTime = 0.0f);
    virtual void reset(); 
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void registerThisInStaticVector()
    {
        gameObjects.push_back(this);
    }
    
    void updateCollisionInfo(const collisionInfo& info = collisionInfo{});
    void resetCollisionInfo();

    const sf::Vector2f& getPosition() const;
    const sf::RectangleShape& getRectangleShape() const;
    const sf::Sprite& getSprite() const;

    void setPosition(const sf::Vector2f& pos);
    
    protected:
    sf::Vector2f _position;
    sf::RectangleShape _box;
    sf::Sprite _sprite;
    collisionInfo _collisionInfo;

    private:
    virtual void updateBox();
    virtual void updateSprite();
    
};

#endif
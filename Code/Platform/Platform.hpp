#ifndef PLATFORM_H
#define PLATFORM_H

#include "GameObject/GameObject.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class Platform : public GameObject
{
    public: 
    static sf::Texture TEXTURE;
    static void loadTexture(const std::string&);

    Platform() = default;
    Platform(const sf::Vector2f&, const sf::Vector2f&);

    private:
    virtual void updateBox() override;
};


#endif
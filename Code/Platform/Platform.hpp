#ifndef PLATFORM_H
#define PLATFORM_H

#include "GameObject/GameObject.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class Platform : public GameObject
{
    public: 
    static std::vector<sf::Texture> PLATFORM_DATABASE;
    static void loadTextures(const std::string&);

    Platform() = default;
    Platform(const sf::Vector2f&, int index = 0);
    Platform(const sf::Vector2f&, const sf::Vector2f&);

    private:
    virtual void updateBox() override;
    int _index;
};


#endif
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;

class Animation
{
public:
    Animation() = default;
    Animation(const filesystem::path &path);

    void loadImages(const filesystem::path &path);
    std::vector<sf::Texture> &getImages();
    std::string &getName();

private:
    std::string _name;
    std::vector<sf::Texture> _images;
};

#endif
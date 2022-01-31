#include "Animation/Animation.h"
#include <string>
#include <iostream>
#include <cstdlib>

std::string searchForNumbers(const std::string& filename)
{
    std::string number;
    for(char ch : filename)
    {
        if(ch >= '0' && ch <= '9')
        {
            number += ch;
        }
    }
    return std::move(number);
}

Animation::Animation(const filesystem::path& path)
    :_name{path.filename().string()}
{
    loadImages(path);
    // _it = std::begin(_images);
}

// void Animation::animate(sf::Sprite& sprite, bool shouldStopOnLastFrame)
// {
//     if(_timer.getElapsedTime().asMilliseconds() > ANIMATION_DURATION)
//     {
//         if(shouldStopOnLastFrame)
//         {
//             _it < std::end(_images) - 2 ? _it++ : _it = std::end(_images) - 2;
//         }
//         else
//         {
//             _it < std::end(_images) - 1 ? _it++ : _it = std::begin(_images);
//         }
        
//         std::cout << sprite.getTexture() << std::endl;

//         sprite.setTexture(*_it);

//         _timer.restart();
//     }
// }

void Animation::loadImages(const filesystem::path& path)
{
    for(const filesystem::directory_entry& entry : filesystem::directory_iterator(path))
    {
        _images.push_back(sf::Texture{});
    }

    for(const filesystem::directory_entry& entry : filesystem::directory_iterator(path))
    {
        std::string index = searchForNumbers(entry.path().filename().string());        

        _images[atoi(index.c_str()) - 1].loadFromFile(entry.path().string());
    }
}

std::vector<sf::Texture>& Animation::getImages()
{
    return _images;
}

std::string& Animation::getName()
{
    return _name;
}

// sf::Texture& Animation::getCurrentTexture()
// {
//     return *_it;
// }

// Animation& Animation::operator=(const Animation& animation)
// {
//     if(&animation != this)
//     {
//         _images = animation._images;
//         _name = animation._name;
//         _it = std::begin(_images);
//     }

//     return *this;
// }
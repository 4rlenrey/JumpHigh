#include "World.hpp"
#include <random>
#include <iostream>

void World::generateWorld()
{
    for(int i = 0; i < 10; i++)
    {
        _platforms.push_back(Platform{sf::Vector2f{150.0f*i,600}});
    }
    for(int i = 0; i < 20; i++)
    {
        addPlatform();
    }
}

void World::addPlatform()
{
    float randVal = static_cast<float>(random())/RAND_MAX;
    float x = randVal * 1200;
    float y = (_platforms.size()-10) * _platformDistance + randVal * 40; 
    sf::Vector2f pos{x,y};

    _platforms.push_back(Platform{pos});
}

std::vector<Platform>& World::getPlatforms()
{
    return _platforms;
}
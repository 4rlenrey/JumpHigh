#include "World.hpp"
#include <random>
#include <iostream>

void World::generateWorld()
{
    _platforms.push_back(Platform{sf::Vector2f{0.0f, 600.0f}, sf::Vector2f{1200,30}});
    
    for(int i = 0; i < 400; i++)
    {
        addPlatform();
    }
}

void World::addPlatform()
{

    if(_platforms.size() > nextThreshold && maxIndex <= Platform::PLATFORM_DATABASE.size())
    {
        maxIndex++;
        nextThreshold += 50;
    }
    if(_platforms.size() > prevThreshold+25 && minIndex <= Platform::PLATFORM_DATABASE.size())
    {
        prevThreshold = nextThreshold;
        minIndex+=2;
    }

    float randVal = static_cast<float>(std::rand())/RAND_MAX;
    float x = 200 + randVal * 800;
    float y = (10 - static_cast<float>(_platforms.size())) * _platformDistance + randVal * 40; 
    sf::Vector2f pos{x,y};


    randVal = static_cast<float>(std::rand())/RAND_MAX;
    _platforms.push_back(Platform{pos,static_cast<int>(randVal*(2)) + minIndex});
}

void World::destroyWorld()
{
    _platforms.clear();
    maxIndex = 1;
    nextThreshold = 50;
    prevThreshold = 50;
    minIndex = 0;
}

std::vector<Platform>& World::getPlatforms()
{
    return _platforms;
}


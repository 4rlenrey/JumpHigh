#ifndef WORLD_H
#define WORLD_H

#include "Platform/Platform.hpp"

#include <vector>

class World
{
    public:
    void generateWorld();
    void addPlatform();

    void destroyWorld();

    std::vector<Platform>& getPlatforms();
    
    private:
    std::vector<Platform> _platforms;
    float _platformDistance = 50.0f;
    int maxIndex = 1;
    int nextThreshold = 50;
    int prevThreshold = 50;
    int minIndex = 0;

};

#endif
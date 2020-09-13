#ifndef WORLD_H
#define WORLD_H

#include "Platform/Platform.hpp"

#include <vector>

class World
{
    public:
    void generateWorld();
    void addPlatform();

    std::vector<Platform>& getPlatforms();
    
    private:
    std::vector<Platform> _platforms;
    float _platformDistance = 50.0f;
};

#endif
#ifndef ANIMATION_SYSTEM_H
#define ANIMATION_SYSTEM_H

#include "Animation/Animation.h"
#include <SFML/Graphics.hpp>
#include <vector>

class AnimationSystem
{
    public:

    static std::vector<Animation> ANIMATION_DATABASE;
    static const int FRAME_DURATION;
    static void loadAnimations(const std::filesystem::path& path);

    AnimationSystem();

    void selectAnimation(const std::string& name);
    void animate(sf::Sprite& sprite, bool shouldStopOnLastFrame = false);
    Animation* getAnimation();

    private:
    Animation* _currentAnimation = nullptr;
    int index = 0;
    sf::Clock _timer;

};

#endif
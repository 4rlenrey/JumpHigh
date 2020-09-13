#include "AnimationSystem.h"
#include <iostream>

std::vector<Animation> AnimationSystem::ANIMATION_DATABASE{};
const int AnimationSystem::FRAME_DURATION = 100;

void AnimationSystem::loadAnimations(const std::filesystem::path& path)
{
    for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(path))
    {
        ANIMATION_DATABASE.push_back(Animation{entry.path()});
    }
}

AnimationSystem::AnimationSystem()
    :_currentAnimation{&ANIMATION_DATABASE[0]}
{

}

void AnimationSystem::selectAnimation(const std::string& name)
{
    if(_currentAnimation->getName() != name)
    {
        bool animationOfThatNameExists{false};

        for(auto& animation : ANIMATION_DATABASE)
        {    
            if(animation.getName() == name)
            {
                index = 0;
                animationOfThatNameExists = true;
                _currentAnimation = &animation;
                break; 
            }
        }

        if(!animationOfThatNameExists)
        {
            std::cout << "No animation of name : \"" << name << "\"" << std::endl;
        }
    }
}

void AnimationSystem::animate(sf::Sprite& sprite, bool shouldStopOnLastFrame)
{
    if(_timer.getElapsedTime().asMilliseconds() > FRAME_DURATION)
    {
        if(shouldStopOnLastFrame)
        {
            index < _currentAnimation->getImages().size()-1 ? index++ : index = _currentAnimation->getImages().size()-1;
        }
        else
        {
            index < _currentAnimation->getImages().size()-1 ? index++ : index = 0;
        }

        sprite.setTexture(_currentAnimation->getImages()[index]);
        _timer.restart();
    }
}

Animation* AnimationSystem::getAnimation()
{
    
    return _currentAnimation;
}
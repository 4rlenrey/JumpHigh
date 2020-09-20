#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Physics/Physical.h"
#include "AnimationSystem/AnimationSystem.h"

class Player : public Physical
{
    public:
    static const float MAX_VELOCITY;
    static const float RECTANGLE_SIZE; //We can get rid of it later when collision system is finnished
    static const float JUMP_VELOCITY;
    static const float HIGH_JUMP_THRESHOLD;

    Player();

    virtual void applyForce(const sf::Vector2f&) override;
    virtual void reset() override;
    
    void update(float deltaTime = 0.0f) override;
    void jump();

    private:
    void updateVelocity(float deltaTime) override;
    void updateBox() override;
    void updateSprite() override;

    
    void applyCollisionForces();
    void animationSelectionBasedOnState();
    void reactToInput();

    bool isHighSpeed();
    bool justJumped();

    bool _jumping = false;
    bool _prevJumping = false;
    bool _standing = false;
    AnimationSystem _animationSystem;
};

#endif
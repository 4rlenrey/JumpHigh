#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <ostream>
#include <SFML/Graphics.hpp>
#include "GameObject/GameObject.hpp"

class Physical : public GameObject
{
    friend std::ostream& operator<<(std::ostream& out, const Physical& obj);

    public:
    static const float DEFAULT_MASS;                    //mass applied to object in default constructor when no argument is passed
    static const float ACCELERATION_SCALE;              //scale to adjust final acceleration
    static const float GENERAL_FRICTION_FORCE_VALUE;    //value of force opossite to velocity of object 
    static const float MIN_SPEED_THRESHOLD;             //minimal value of speed to stop object's motion
    static const sf::Vector2f GRAVITY_FORCE;            //object falling acceleration

    Physical(float mass = DEFAULT_MASS);
    virtual ~Physical();
    virtual void applyForce(const sf::Vector2f& force);
    void updateAcceleration();
    void updatePosition(float deltaTIme);
    
    virtual void update(float deltaTime) override;
    virtual void updateVelocity(float deltaTime);

    float getMass() const;  
    const sf::Vector2f& getVelocity() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getAppliedForce() const;
    const sf::Vector2f& getAcceleration() const;

    void setVelocity(const sf::Vector2f& vec);
    void setAcceleration(const sf::Vector2f& accel);
    void setMass(float mass);

    protected:
    float _mass;
    float _decelerationValue;
    sf::Vector2f _force;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
};

std::ostream& operator<<(std::ostream& out, const Physical& obj);

#endif
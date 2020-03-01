#ifndef __BULLET_H__
#define __BULLET_H__

#include <SFML/Graphics.hpp>
#include "BulletFactory.h"
#include "TimePoint.h"
#include "WallManager.h"

class Bullet
{
    friend class BulletFactory;

private:
    sf::CircleShape mBody;
    sf::Vector2f mPos;
    sf::Vector2f mDir;
    float mSpeed;
    float mLifeTime;
    TimePoint mStartTime;
    sf::Vector2f mVelocity;

public:
    bool mIsAlive;

public:
    Bullet(sf::CircleShape body, sf::Vector2f position, sf::Vector2f direction, float speed, float life_time);
    //
    bool Update(const float time);
    //
    inline sf::CircleShape GetBody() { return mBody; }
    //
    bool CheckCollision(sf::Vector2f oldPos, const float time);
    void ChangeDirection(const sf::Vector2f rotatePoint, const float angle, bool relativePos);
    //
};

#endif // !__BULLET_H__

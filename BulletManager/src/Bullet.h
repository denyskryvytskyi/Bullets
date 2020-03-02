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

public:
    bool mIsAlive;

public:
    Bullet(sf::CircleShape body, sf::Vector2f position, sf::Vector2f direction, float speed, float life_time);
    //
    bool Update(const float time);
    //
    inline sf::CircleShape GetBody() { return mBody; }
    //
    bool CheckCollision(const float time);
};

#endif // !__BULLET_H__

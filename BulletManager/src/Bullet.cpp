#include "Bullet.h"
#include "TimePoint.h"
#include "WallManager.h"

Bullet::Bullet(sf::CircleShape body, sf::Vector2f position, sf::Vector2f direction, float speed, float life_time) :
    mBody(body),
    mPos(position),
    mDir(direction),
    mSpeed(speed),
    mLifeTime(life_time),
    mAlive(true)
{
    mStartTime.SetCurrTime();
}

bool Bullet::Update(float time)
{
    //CheckCollision();

    float secondsFromStart = SecondsSince(mStartTime);
    if (secondsFromStart >= mLifeTime)
        return false;

    mPos += mDir * mSpeed * time;
    mBody.setPosition(mPos);
    
    return true;
}


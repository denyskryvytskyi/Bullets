#include "Bullet.h"
#include "TimePoint.h"
#include "Math.h"
#include "Physics.h"

Bullet::Bullet(sf::CircleShape body, sf::Vector2f position, sf::Vector2f direction, float speed, float life_time) :
    mBody(body),
    mPos(position),
    mDir(direction),
    mSpeed(speed),
    mLifeTime(life_time),
    mIsAlive(true)
{
    mStartTime.SetCurrTime();
}

bool Bullet::Update(const float time)
{
    float secondsFromStart = SecondsSince(mStartTime);
    if (secondsFromStart >= mLifeTime)
        return false;

    mPos += mDir * mSpeed * time;
    mBody.setPosition(mPos);

    CheckCollision(time);

    return true;
}


bool Bullet::CheckCollision(const float time)
{
    for (WallPtr wall : gWallManager.GetWalls())
    {
        sf::Vector2f point;
        if (Physics::CheckIntersection(mBody, wall->GetBody(), point))
        {
            mDir = Physics::ReflectionVector(mDir, mPos, point);
            mPos = point + mDir * time;
            mBody.setPosition(mPos);

            wall->mIsAlive = false;
            return true;
        }
    }

    return false;
}
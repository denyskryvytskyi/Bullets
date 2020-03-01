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

    sf::Vector2f oldPos = mPos;

    mPos += mDir * mSpeed * time;
    mBody.setPosition(mPos);

    mVelocity = Physics::FindVelocity(oldPos, mPos, time);

    CheckCollision(oldPos, time);

    return true;
}


bool Bullet::CheckCollision(sf::Vector2f oldPos, const float time)
{
    for (WallPtr wall : gWallManager.GetWalls())
    {
        sf::Vector2f point;
        if (Physics::CheckIntersection(mBody, wall->GetBody(), point))
        {
            //float angle = Physics::CalculateRotateAngle(point, mPos, mVelocity);
            float angle = Physics::AngleOfIntersec(Line2f(oldPos, mPos), wall->GetSegment());
            ChangeDirection(point, angle, Physics::PointPosition(mPos, wall->GetSegment()));
            mPos = point + mDir * time;
            mBody.setPosition(mPos);

            wall->mIsAlive = false;
            return true;
        }
    }

    return false;
}

void Bullet::ChangeDirection(const sf::Vector2f rotatePoint, const float angle, bool right)
{
    
    float xNew = mDir.x * cos(2 * angle) - mDir.y * sin(2 * angle);
    float yNew = mDir.x * sin(2 * angle) + mDir.y * cos(2 * angle);

    mDir.x = xNew;
    mDir.y = yNew;
}

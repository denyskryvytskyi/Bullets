#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include <list>
#include "Bullet.h"

typedef std::shared_ptr<Bullet> BulletPtr;

class BulletManager
{
    typedef std::list<BulletPtr> BulletList;

private:
    BulletList mBullets;
    const unsigned int mMaxBulletsCount = 100;

private:
    bool AddBullet(BulletPtr bullet);

public:
    void Update(float time);
    bool Fire(sf::Vector2f pos, sf::Vector2f dir, float speed, float time, float lifeTime);
    //
    inline BulletList GetBullets() const { return mBullets; };
};

#endif // BULLET_MANAGER_H

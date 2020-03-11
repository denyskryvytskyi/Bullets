#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include "Bullet.h"

class BulletManager
{
    typedef std::vector<BulletPtr> BulletArray;

private:
    BulletArray mBullets;
    const unsigned int mMaxBulletsCount = 100;

private:
    bool AddBullet(BulletPtr bullet);

public:
    void Update(float time);
    bool Fire(sf::Vector2f pos, sf::Vector2f dir, float speed, float time, float lifeTime);
    //
    inline BulletArray GetBullets() const { return mBullets; };
};

#endif // !__BULLET_MANAGER_H__

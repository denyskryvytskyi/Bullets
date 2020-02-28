#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include <vector>
#include "Bullet.h"

class BulletManager
{
private:
    const int mMaxBulletsCount = 100;
    std::vector<Bullet*> mBullets;
public:
    BulletManager();
    ~BulletManager();
    //
    void Update();
    void AddBullet(Bullet* bullet);
    void Fire(sf::Vector2f pos, sf::Vector2f dir, float speed, float time, float lifeTime);
};

#endif // BULLET_MANAGER_H

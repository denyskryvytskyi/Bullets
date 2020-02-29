#include "BulletManager.h"
#include "BulletFactory.h"

void BulletManager::Update(float time)
{
    for (BulletList::iterator bulletIterator = mBullets.begin(); bulletIterator != mBullets.end();)
    {
        // check collision

        // check life_time
        if (!(*bulletIterator)->Update(time))
            bulletIterator = mBullets.erase(bulletIterator);
        else
            ++bulletIterator;
    }
}

bool BulletManager::AddBullet(BulletPtr bullet)
{
    if (bullet != nullptr && mBullets.size() < mMaxBulletsCount)
    {
        mBullets.push_back(std::move(bullet));
        return true;
    }

    return false;
}

bool BulletManager::Fire(sf::Vector2f pos, sf::Vector2f dir, float speed, float time, float lifeTime)
{
    // sleep time seconds / for thread

    if (mBullets.size() < mMaxBulletsCount)
    {
        BulletPtr bullet = BulletFactory::Create(pos, dir, speed, lifeTime);

        if (AddBullet(bullet))
            return true;
    }

    return false;
}

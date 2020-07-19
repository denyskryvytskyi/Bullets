#include <thread>
#include <mutex>
#include "BulletManager.h"
#include "BulletFactory.h"

std::mutex mu;

void BulletManager::Update(float time)
{
    std::lock_guard<std::mutex> lock(mu);
    for (BulletArray::iterator bulletIterator = mBullets.begin(); bulletIterator != mBullets.end();)
    {
        if (!(*bulletIterator)->Update(time))
            bulletIterator = mBullets.erase(bulletIterator);
        else
            ++bulletIterator;
    }
}

bool BulletManager::AddBullet(BulletPtr bullet)
{
    std::lock_guard<std::mutex> lock(mu);
    if (bullet != nullptr && mBullets.size() < mMaxBulletsCount)
    {
        mBullets.push_back(std::move(bullet));
        return true;
    }

    return false;
}

bool BulletManager::Fire(sf::Vector2f pos, sf::Vector2f dir, float speed, float time, float lifeTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(time * 1000)));

    if (mBullets.size() < mMaxBulletsCount)
    {
        BulletPtr bullet = BulletFactory::Create(pos, dir, speed, lifeTime);

        if (AddBullet(bullet))
            return true;
    }

    return false;
}

#include "GameManager.h"

void GameManager::CheckSpeed(sf::Vector2f& dir, float& speed) const
{
    if ((abs(dir.x) < mMinBulletSpeed) && (abs(dir.y) < mMinBulletSpeed))
    {
        // if there is not direction
        if (dir.x == 0 && dir.y == 0)
        {
            dir = SetRandomDir();
        }
        speed += pow(mMinBulletSpeed, 2);
    }
}

sf::Vector2f GameManager::SetRandomDir() const
{
    sf::Vector2f dir;

    int var = rand() % 6;

    switch (var)
    {
    case 0:
        dir.x = 1;
        break;
    case 1:
        dir.x = -1;
        break;
    case 2:
        dir.y = 1;
        break;
    case 3:
        dir.y = -1;
        break;
    case 4:
        dir.x = 1;
        dir.y = 1;
        break;
    case 5:
        dir.x = -1;
        dir.y = -1;
        break;
    }

    return dir;
}
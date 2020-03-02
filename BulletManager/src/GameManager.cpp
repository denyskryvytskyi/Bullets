#include "GameManager.h"
#include "Config.h"

void GameManager::CheckSpeed(sf::Vector2f& dir, float& speed)
{
    if ((abs(dir.x) < min_speed) && (abs(dir.y) < min_speed))
    {
        // if there is not direction
        if (dir.x == 0 && dir.y == 0)
        {
            SetRandomDir(dir);
        }
        speed += pow(min_speed, 2);
    }
}

void GameManager::SetRandomDir(sf::Vector2f& dir)
{
    int var = rand() % 6;

    /*
    / random direction from list:
    / (1;0)
    / (-1;0)
    / (0;1)
    / (0;-1)
    / (1;1)
    / (-1;-1)
    */
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
    }
}
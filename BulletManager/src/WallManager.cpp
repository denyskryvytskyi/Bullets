#include "Config.h"
#include "WallManager.h"
#include "WallFactory.h"

void WallManager::Update()
{
    for (WallList::iterator wallIterator = mWalls.begin(); wallIterator != mWalls.end();)
    {
        if (!(*wallIterator)->mIsAlive)
            wallIterator = mWalls.erase(wallIterator);
        else
            ++wallIterator;
    }
}

bool WallManager::BuildWalls()
{
    float wallWidth = 30.f;
    float screenHeight = Config::mode_height;
    float screenWidth = Config::mode_width;

    AddWall(WallFactory::Create(sf::Vector2f(wallWidth, screenHeight), sf::Vector2f(0, 0), sf::Vector2f(screenWidth, 0))); // left
    AddWall(WallFactory::Create(sf::Vector2f(screenWidth, wallWidth), sf::Vector2f(0, screenHeight - wallWidth), sf::Vector2f(screenWidth, screenHeight - wallWidth))); // down
    AddWall(WallFactory::Create(sf::Vector2f(screenWidth, wallWidth), sf::Vector2f(wallWidth, 0), sf::Vector2f(screenHeight - wallWidth, 0))); // up
    AddWall(WallFactory::Create(sf::Vector2f(wallWidth, screenHeight), sf::Vector2f(screenWidth - wallWidth, wallWidth), sf::Vector2f(screenWidth - wallWidth, screenHeight))); // right

    return true;
}

bool WallManager::AddWall(WallPtr wall)
{
    if (wall != nullptr && mWalls.size() < mMaxWallsCount)
    {
        mWalls.push_back(wall);
        return true;
    }

    return false;
}

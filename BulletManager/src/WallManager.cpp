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
    // сделать доп функционал (описал в заметках)

    AddWall(WallFactory::Create(sf::Vector2f(def_rect_width, mode_height), sf::Vector2f(0, 0), sf::Vector2f(mode_width, 0))); // left
    AddWall(WallFactory::Create(sf::Vector2f(mode_width, def_rect_width), sf::Vector2f(0, mode_height - def_rect_width), sf::Vector2f(mode_width, mode_height - def_rect_width))); // down
    AddWall(WallFactory::Create(sf::Vector2f(mode_width, def_rect_width), sf::Vector2f(def_rect_width, 0), sf::Vector2f(mode_height - def_rect_width, 0))); // up
    AddWall(WallFactory::Create(sf::Vector2f(def_rect_width, mode_height), sf::Vector2f(mode_width - def_rect_width, def_rect_width), sf::Vector2f(mode_width - def_rect_width, mode_height))); // right

    return true;
}

bool WallManager::AddWall(WallPtr wall)
{
    if (wall != nullptr && mWalls.size() < max_walls_count)
    {
        mWalls.push_back(wall);
        return true;
    }

    return false;
}

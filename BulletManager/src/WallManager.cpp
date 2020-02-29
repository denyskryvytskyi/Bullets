#include "Config.h"
#include "WallManager.h"

bool WallManager::BuildWalls(int wallsCount)
{
    // for
    // create wall through wall factory

    // add created wall to mWalls through  AddWall method

    return false;
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

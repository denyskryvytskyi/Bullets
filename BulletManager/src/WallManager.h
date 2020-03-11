#ifndef __WALL_MANAGER_H__
#define __WALL_MANAGER_H__

#include "Wall.h"

class WallManager
{
    typedef std::vector<WallPtr> WallArray;

private:
    WallArray mWalls;
    const unsigned int mMaxWallsCount = 50;

private:
    bool AddWall(WallPtr wall);

public:
    void Update();
    bool BuildWalls();
    //
    inline WallArray GetWalls() { return mWalls; };
};

extern WallManager gWallManager;

#endif // BULLET_MANAGER_H

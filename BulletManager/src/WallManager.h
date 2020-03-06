#ifndef __WALL_MANAGER_H__
#define __WALL_MANAGER_H__

#include <list>
#include "Wall.h"

class WallManager
{
    typedef std::list<WallPtr> WallList;

private:
    WallList mWalls;
    const unsigned int mMaxWallsCount = 50;

private:
    bool AddWall(WallPtr wall);

public:
    void Update();
    bool BuildWalls();
    //
    inline WallList GetWalls() { return mWalls; };
};

extern WallManager gWallManager;

#endif // BULLET_MANAGER_H

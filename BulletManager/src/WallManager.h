#ifndef __WALL_MANAGER_H__
#define __WALL_MANAGER_H__

#include <list>
#include "Wall.h"

typedef std::shared_ptr<Wall> WallPtr;
typedef std::list<WallPtr> WallList;

class WallManager
{
private:
    WallList mWalls;

private:
    bool AddWall(WallPtr wall);

public:
    bool BuildWalls(int wallsCount);
};

extern WallManager gWallManager;

#endif // BULLET_MANAGER_H

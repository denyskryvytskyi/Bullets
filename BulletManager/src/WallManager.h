#ifndef __WALL_MANAGER_H__
#define __WALL_MANAGER_H__

#include <vector>
#include "Wall.h"

class WallManager
{
private:
    std::vector<Wall> mWalls;
public:
    WallManager();
    ~WallManager();
    //
    void Update(float time);
    void AddWall(Wall* wall);
};

#endif // BULLET_MANAGER_H

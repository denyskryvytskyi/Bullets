#ifndef __WALL_H__
#define __WALL_H__

#include "CommonTypes.h"

class Wall
{
private:
    sf::RectangleShape mBody;
    Line mWallSegment;

public:
    Wall();
    ~Wall();
};

#endif // !__WALL_H__

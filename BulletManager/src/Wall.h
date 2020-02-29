#ifndef __WALL_H__
#define __WALL_H__

#include "CommonTypes.h"
#include "WallFactory.h"

class Wall
{
    friend class WallFactory;

private:
    sf::RectangleShape mBody;
    Line2f mWallSegment;

public:
    Wall();
    Wall(sf::RectangleShape body, Line2f wallSegment);
    ~Wall();
};

#endif // !__WALL_H__

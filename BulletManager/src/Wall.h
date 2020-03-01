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
    bool mIsAlive;
public:
    Wall(sf::RectangleShape body, Line2f wallSegment);
    //
    inline sf::RectangleShape GetBody() { return mBody; }
    inline Line2f GetSegment() { return mWallSegment; }
};

#endif // !__WALL_H__

#ifndef __WALL_H__
#define __WALL_H__

#include "CommonTypes.h"

class Wall
{
private:
    sf::RectangleShape mBody;
    Line2f mWallSegment;

public:
    bool mIsAlive;

public:
    Wall(sf::RectangleShape body, Line2f wallSegment);
    //
    inline sf::RectangleShape GetBody() const { return mBody; }
    inline Line2f GetSegment() const { return mWallSegment; }
};

typedef std::shared_ptr<Wall> WallPtr;

#endif // !__WALL_H__

#include "Wall.h"

Wall::Wall(sf::RectangleShape body, Line2f wallSegment) :
    mBody(body),
    mWallSegment(wallSegment),
    mIsAlive(true)
{}

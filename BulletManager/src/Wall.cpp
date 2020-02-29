#include "Wall.h"

Wall::Wall()
{}

Wall::Wall(sf::RectangleShape body, Line2f wallSegment) :
    mBody(body),
    mWallSegment(wallSegment)
{}

Wall::~Wall()
{}

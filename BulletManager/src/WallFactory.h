#ifndef __WALL_FACTORY_H__
#define __WALL_FACTORY_H__

#include "Wall.h"

class Wall;

class WallFactory
{
public:
    static std::shared_ptr<Wall> Create(sf::Vector2f size, sf::Vector2f startPosition, sf::Vector2f endPosition);
};

#endif // !__WALL_FACTORY_H__

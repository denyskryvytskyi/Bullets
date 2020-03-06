#ifndef __WALL_FACTORY_H__
#define __WALL_FACTORY_H__

#include "Wall.h"

class WallFactory
{
public:
    static WallPtr Create(sf::Vector2f size, sf::Vector2f startPosition, sf::Vector2f endPosition);
};

#endif // !__WALL_FACTORY_H__

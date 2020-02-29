#ifndef __BULLET_FACTORY_H__
#define __BULLET_FACTORY_H__

#include "Config.h"
#include "Bullet.h"

class Bullet;

class BulletFactory
{
public:
    static std::shared_ptr<Bullet> Create(sf::Vector2f position, sf::Vector2f direction, float speed, float left_time, float radius = circle_radius);
};

#endif // !__BULLET_FACTORY_H__

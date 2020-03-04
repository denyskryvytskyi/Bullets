#ifndef __BULLET_FACTORY_H__
#define __BULLET_FACTORY_H__

#include "Bullet.h"

class BulletFactory
{
public:
    static std::shared_ptr<Bullet> Create(sf::Vector2f position, sf::Vector2f direction, float speed, float left_time, float radius = 10.f);
};

#endif // !__BULLET_FACTORY_H__

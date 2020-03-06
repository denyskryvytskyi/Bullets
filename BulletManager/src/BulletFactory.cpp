#include "BulletFactory.h"

BulletPtr BulletFactory::Create(sf::Vector2f position, sf::Vector2f direction, float speed, float life_time, float radius)
{
    sf::CircleShape body;
    body.setRadius(radius);
    body.setPosition(position);
    body.setOrigin(radius, radius);
    body.setFillColor(sf::Color::Green);

    return std::make_shared<Bullet>(body, position, direction, speed, life_time);
}

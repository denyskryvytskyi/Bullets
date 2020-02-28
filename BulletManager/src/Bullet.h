#ifndef __BULLET_H__
#define __BULLET_H__

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::CircleShape mBody;
    sf::Vector2f mPos;
    sf::Vector2f mDir;
    float mSpeed;
    float mLeftTime;

public:
    Bullet();
    ~Bullet();
};

#endif // !__BULLET_H__

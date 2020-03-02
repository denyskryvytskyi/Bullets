#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SFML/Graphics.hpp>

class GameManager
{
public:
    const float mFireStartTime = 1.f;
    const float mBulletLifeTime = 5.f;
    const float mBulletSpeed = 5.f;

public:
    void CheckSpeed(sf::Vector2f& dir, float& speed);
    void SetRandomDir(sf::Vector2f& dir);
};

#endif // !__GAME_MANAGER_H__

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <SFML/Graphics.hpp>

class GameManager
{
public:
    const float mDefaultBulletSpeed = 5.f;
    const float mMinBulletSpeed = 10.f;

public:
    void CheckSpeed(sf::Vector2f& dir, float& speed) const;
    sf::Vector2f SetRandomDir() const;
};

#endif // !__GAME_MANAGER_H__

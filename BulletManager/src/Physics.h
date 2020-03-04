#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include <SFML/Graphics.hpp>

namespace Physics
{
    bool CheckIntersection(const sf::CircleShape circle, const sf::RectangleShape rect, sf::Vector2f& intersectPoint);
    //
    sf::Vector2f ReflectionVector(sf::Vector2f dir, sf::Vector2f pos, sf::Vector2f point);
};

#endif // !__PHYSICS_H__
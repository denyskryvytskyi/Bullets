#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include <SFML/Graphics.hpp>
#include "CommonTypes.h"

class Physics
{
public:
    static sf::Vector2f FindVelocity(const sf::Vector2f& aPos, const sf::Vector2f& bPos, float speed);
    //
    static float CalculateRotateAngle(const sf::Vector2f point, const sf::Vector2f pos, const sf::Vector2f velocity);
    //
    static bool CheckIntersection(const sf::CircleShape circle, const sf::RectangleShape rect, sf::Vector2f& intersectPoint);
    //
    static bool PointPosition(sf::Vector2f point, Line2f line);
    //
    static float AngleOfIntersec(Line2f A, Line2f B);
};

#endif // !__PHYSICS_H__
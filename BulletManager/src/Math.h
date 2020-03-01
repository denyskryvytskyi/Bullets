#ifndef __MATH_H__
#define __MATH_H__

#include "SFML/Graphics.hpp"

class Math
{
private:
    static const double mPi;
public:
    static float Length(sf::Vector2f A, sf::Vector2f B);

    static sf::Vector2f Normalized(sf::Vector2f vec, float distance);

    static bool PointInPoly(const sf::Vector2f& point, const sf::Shape& polygon);

    static float Max(float, float);
    static float Min(float, float);

    static float RadiansToDegrees(float radians);
};

#endif // !__MATH_H__
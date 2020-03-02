#ifndef __MATH_H__
#define __MATH_H__

#include "SFML/Graphics.hpp"

class Math
{
private:
    static const double mPi;
public:
    static float Length(sf::Vector2f A, sf::Vector2f B);
    static float VecLength(sf::Vector2f vec);
    //
    static sf::Vector2f Normalized(sf::Vector2f vec);
    //
    static float Max(float, float);
    static float Min(float, float);
    //
    static float DotProduct(const sf::Vector2f vecA, const sf::Vector2f vecB);
};

#endif // !__MATH_H__
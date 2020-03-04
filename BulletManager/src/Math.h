#ifndef __MATH_H__
#define __MATH_H__

#include "SFML/Graphics.hpp"

namespace Math
{
    const double mPi = 3.141592653589793238463;
    //
    float Length(sf::Vector2f A, sf::Vector2f B);
    float VecLength(sf::Vector2f vec);
    //
    sf::Vector2f Normalized(sf::Vector2f vec);
    //
    float Max(float, float);
    float Min(float, float);
    //
    float DotProduct(const sf::Vector2f vecA, const sf::Vector2f vecB);
};

#endif // !__MATH_H__
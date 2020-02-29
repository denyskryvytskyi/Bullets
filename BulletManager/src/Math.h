#ifndef __MATH_H__
#define __MATH_H__

#include "SFML/Graphics.hpp"

class Math
{
public:
    static float Length(sf::Vector2i A, sf::Vector2i B);
    static float Length(sf::Vector2f A, sf::Vector2f B);
    
    static sf::Vector2f Normalized(sf::Vector2f vec, float distance);
};

#endif // !__MATH_H__
#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <SFML/Graphics.hpp>

class Line
{
public:
    sf::Vector2f A;
    sf::Vector2f B;

public:
    Line() :A(), B() {}
    Line(sf::Vector2f theA, sf::Vector2f theB)
        :A(theA), B(theB) {}
    Line(const Line& line)
        :A(line.A), B(line.B) {}

};

#endif // !__COMMON_TYPES_H__

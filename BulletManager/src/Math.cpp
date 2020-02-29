#include "Math.h"

float Math::Length(sf::Vector2i A, sf::Vector2i B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

float Math::Length(sf::Vector2f A, sf::Vector2f B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

sf::Vector2f Math::Normalized(sf::Vector2f vec, float distance)
{
    vec.x /= distance;
    vec.y /= distance;
    return vec;
}

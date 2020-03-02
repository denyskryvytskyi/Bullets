#include "Math.h"

const double Math::mPi = 3.141592653589793238463;

float Math::Length(sf::Vector2f A, sf::Vector2f B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

float Math::VecLength(sf::Vector2f vec)
{
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f Math::Normalized(const sf::Vector2f vec)
{
    float lengthInverse = 1 / VecLength(vec);

    return vec * lengthInverse;
}

float Math::Max(float x, float y)
{
    return x >= y ? x : y;
}

float Math::Min(float x, float y)
{
    return x <= y ? x : y;
}

float Math::DotProduct(const sf::Vector2f vecA, const sf::Vector2f vecB)
{
    return vecA.x * vecB.x + vecA.y * vecB.y;
}
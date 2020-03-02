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

bool Math::PointInPoly(const sf::Vector2f& test, const sf::Shape& polygon)
{
    sf::Vector2f newPoint, oldPoint;
    sf::Vector2f left, right;

    bool inside = false;

    size_t points = polygon.getPointCount();

    // The polygon must at least be a triangle
    if (points < 3)
        return false;

    oldPoint = polygon.getPoint(points - 1);

    for (size_t i = 0; i < points; i++)
    {
        newPoint = polygon.getPoint(i);
        if (newPoint.x > oldPoint.y)
        {
            left = oldPoint;
            right = newPoint;
        }
        else
        {
            left = newPoint;
            right = oldPoint;
        }

        // A point exactly on the left side of the polygon
        // will not intersect - as if it were "open"
        if ((newPoint.x < test.x) == (test.x <= oldPoint.x)
            && (test.y - left.y) * (right.x - left.x)
            < (right.y - left.y) * (test.x - left.x))
        {
            inside = !inside;
        }

        oldPoint = newPoint;
    }

    return inside;
}

float Math::Max(float x, float y)
{
    return x >= y ? x : y;
}

float Math::Min(float x, float y)
{
    return x <= y ? x : y;
}

float Math::RadiansToDegrees(float radians)
{
    return radians * (180.f / mPi);
}

float Math::DotProduct(const sf::Vector2f vecA, const sf::Vector2f vecB)
{
    return vecA.x * vecB.x + vecA.y * vecB.y;
}

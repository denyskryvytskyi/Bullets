#include "Physics.h"
#include "Math.h"
#include <cmath>

sf::Vector2f Physics::FindVelocity(const sf::Vector2f& aPos, const sf::Vector2f& bPos, float time)
{
    // velocity = displacement / time

    sf::Vector2f disp = bPos - aPos;
    //float distance = Math::Length(bPos, aPos);
    return disp / time;
}

float Physics::CalculateRotateAngle(const sf::Vector2f point, const sf::Vector2f pos, const sf::Vector2f velocity)
{
    // calculate rotate angle
    sf::Vector2f distance(pos.x - point.x, pos.y - point.y);
    sf::Vector2f normal(-distance.y, distance.x);

    float normalAngle = atan2(normal.y, normal.x);
    float incomingAngle = atan2(velocity.y, velocity.x);
    float theta = abs(normalAngle) - abs(incomingAngle);

    return theta *= 2;
}

bool Physics::CheckIntersection(const sf::CircleShape circle, const sf::RectangleShape rect, sf::Vector2f& intersectPoint)
{
    sf::Vector2f circlePos = circle.getPosition();
    float radius = circle.getRadius();
    sf::Vector2f rectPos = rect.getPosition();
    sf::Vector2f rectSize = rect.getSize();

    intersectPoint.x = Math::Max(rectPos.x, Math::Min(circlePos.x, rectPos.x + rectSize.x));
    intersectPoint.y = Math::Max(rectPos.y, Math::Min(circlePos.y, rectPos.y + rectSize.y));

    float deltaX = circlePos.x - intersectPoint.x;
    float deltaY = circlePos.y - intersectPoint.y;

    return (deltaX * deltaX + deltaY * deltaY) < (radius * radius);
}

sf::Vector2f Physics::ReflectionVector(sf::Vector2f dir, sf::Vector2f pos, sf::Vector2f point)
{
    // r = d - 2(d . n) * n , where d . n is dot product
    sf::Vector2f distance(pos.x - point.x, pos.y - point.y);
    sf::Vector2f normal(distance.x, distance.y);

    normal = Math::Normalized(normal);

    sf::Vector2f r = dir - 2 * Math::DotProduct(dir, normal) * normal;

    return r;
}

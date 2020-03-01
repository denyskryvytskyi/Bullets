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

bool Physics::PointPosition(sf::Vector2f point, Line2f line)
{
    // for vertical

    // for horizontal

    float D = (point.x - line.A.x) * (line.B.y - line.A.y) - (point.y - line.A.y) * (line.B.x - line.A.x);

    return D > 0 ? false : true;
}

float Physics::AngleOfIntersec(Line2f aLine, Line2f bLine) 
{
    sf::Vector2f first, second;
    first.x = aLine.B.x - aLine.A.x;	//calculating vectors first and second from A and B lines
    first.y = aLine.B.y - aLine.A.y;	//
    second.x = bLine.B.x - bLine.A.x;	//
    second.y = bLine.B.y - bLine.A.y;	//

    float fMod = std::sqrt(first.x * first.x + first.y * first.y);		//vectors' modules
    float sMod = std::sqrt(second.x * second.x + second.y * second.y);	//

    return acos((first.x * second.x + first.y * second.y) / (fMod * sMod));
}

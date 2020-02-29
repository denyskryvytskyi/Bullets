#include "WallFactory.h"

std::shared_ptr<Wall> WallFactory::Create(sf::Vector2f size, sf::Vector2f startPosition, sf::Vector2f endPosition)
{
    sf::RectangleShape body(size);
    Line2f segment(startPosition, endPosition);

    return std::make_shared<Wall>(body, segment);
}
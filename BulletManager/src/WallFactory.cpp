#include "WallFactory.h"

WallPtr WallFactory::Create(sf::Vector2f size, sf::Vector2f startPosition, sf::Vector2f endPosition)
{
    sf::RectangleShape body;
    body.setPosition(startPosition);
    body.setSize(size);
    body.setFillColor(sf::Color::Red);

    Line2f segment(startPosition, endPosition);

    return std::make_shared<Wall>(body, segment);
}
#include "Math.h"
#include "Config.h"
#include "WallFactory.h"

std::shared_ptr<Wall> WallFactory::Create(sf::Vector2f size, sf::Vector2f startPosition, sf::Vector2f endPosition)
{
    sf::RectangleShape body;
    body.setPosition(startPosition);
    body.setSize(size);
    body.setFillColor(sf::Color::Yellow);

    Line2f segment(startPosition, endPosition);

    return std::make_shared<Wall>(body, segment);
}
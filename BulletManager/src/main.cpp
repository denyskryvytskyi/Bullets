#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "BulletManager.h"
#include "WallManager.h"
#include "Math.h"

WallManager gWallManager;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Bullet Manager");

    sf::Clock clock;

    BulletManager bulletManager;
    gWallManager.BuildWalls(4);

    sf::Vector2i startPos;
    sf::Vector2i endPos;

    while (window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == KeyCode_WinClosed)
            {
                window.close();
                break;
            }

            if (event.type == KeyCode_MouseBtnPressed)
            {
                if (event.mouseButton.button == KeyCode_LeftMouseBtn)
                {
                    startPos = sf::Mouse::getPosition(window);
                }
            }
            if (event.type == KeyCode_MouseBtnReleased)
            {
                if (event.mouseButton.button == KeyCode_LeftMouseBtn)
                {
                    endPos = sf::Mouse::getPosition(window);
                    float distance = Math::Length(sf::Vector2f(startPos), sf::Vector2f(endPos));
                    //sf::Vector2f direction = Math::Normalized(sf::Vector2f(endPos), distance);
                    sf::Vector2f direction = sf::Vector2f(endPos - startPos);
                    float speed = 1.f;
                    float startTime = 1.f;
                    float lifeTime = 5.f;

                    bulletManager.Fire(sf::Vector2f(startPos), direction, speed, startTime, lifeTime);
                }
            }
        }

        bulletManager.Update(elapsedTime.asSeconds());

        window.clear();
        // draw walls

        // draw bullets
        for (BulletPtr bullet : bulletManager.GetBullets())
        {
            window.draw(bullet->GetBody());
        }
        window.display();
    }

    return 0;
}
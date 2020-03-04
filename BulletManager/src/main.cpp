#include <list>
#include <thread>
#include <SFML/Graphics.hpp>
#include "BulletManager.h"
#include "WallManager.h"
#include "GameManager.h"
#include "Config.h"

WallManager gWallManager;

int main()
{
    sf::RenderWindow window(sf::VideoMode(Config::mode_width, Config::mode_height), "Bullet Manager");

    sf::Clock clock;

    BulletManager bulletManager;
    GameManager gameManager;

    gWallManager.BuildWalls();

    sf::Vector2i startPos;
    sf::Vector2i endPos;

    float speed;
    float startTime = 0.2f;
    float lifeTime = 5.f;

    sf::Time elapsedTime;
    sf::Event event;
    sf::Vector2f direction;

    while (window.isOpen())
    {
        elapsedTime = clock.restart();

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

                    direction = sf::Vector2f(endPos - startPos);
                    speed = gameManager.mDefaultBulletSpeed;

                    gameManager.CheckSpeed(direction, speed);

                    std::thread fThread(&BulletManager::Fire, std::ref(bulletManager), sf::Vector2f(startPos), direction, speed, startTime, lifeTime);
                    fThread.detach();
                }
            }
        }

        bulletManager.Update(elapsedTime.asSeconds());
        gWallManager.Update();

        window.clear();

        for (WallPtr wall : gWallManager.GetWalls())
        {
            window.draw(wall->GetBody());
        }
        for (BulletPtr bullet : bulletManager.GetBullets())
        {
            window.draw(bullet->GetBody());
        }

        window.display();
    }

    return 0;
}

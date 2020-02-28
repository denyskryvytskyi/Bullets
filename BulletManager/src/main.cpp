#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "BulletManager.h"
#include "WallManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Bullet Manager");
    
    BulletManager bulletManager();
    WallManager wallManager();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            window.clear();
            window.display();
        }
    }

    return 0;
}
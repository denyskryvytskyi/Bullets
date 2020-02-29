#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <SFML/Graphics.hpp>

template <typename T>
class Line
{
public:
    T A;
    T B;

public:
    Line() :A(), B() {}
    Line(T theA, T theB)
        :A(theA), B(theB) {}
    Line(const Line& line)
        :A(line.A), B(line.B) {}
};

typedef Line<sf::Vector2f> Line2f;
typedef Line<sf::Vector2i> Line2i;

enum KeyCode
{
    KeyCode_MouseBtnPressed = sf::Event::MouseButtonPressed,
    KeyCode_MouseBtnReleased = sf::Event::MouseButtonReleased,
    KeyCode_LeftMouseBtn = sf::Mouse::Left,
    KeyCode_RightMouseBtn = sf::Mouse::Right,
    KeyCode_WinClosed = sf::Event::Closed,
};
#endif // !__COMMON_TYPES_H__

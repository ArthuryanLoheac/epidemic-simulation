#include "interetPoint.hpp"
#include "color.hpp"
#include <SFML/Graphics.hpp>

interetPoint::interetPoint(size_t x, size_t y, size_t sizeX, size_t sizeY)
{
    _pos = sf::Vector2f(x, y);
    _size = sf::Vector2f(sizeX, sizeY);
    _rect.setSize(_size);
    _rect.setPosition(_pos);
    _rect.setOrigin(_size.x / 2, _size.y / 2);
    _rect.setFillColor(sf::Color::Transparent);
    _rect.setOutlineColor(sf::Color::White);
    _rect.setOutlineThickness(2);
    _type = NORMAL;
}

interetPoint::~interetPoint()
{
}

interetPoint::TypePoint interetPoint::getType(void)
{
    return _type;
}

sf::Vector2f interetPoint::getPos(void)
{
    return _pos;
}

void interetPoint::draw(sf::RenderWindow *window)
{
    window->draw(_rect);
}

void interetPoint::update(float speed, int percent)
{

}

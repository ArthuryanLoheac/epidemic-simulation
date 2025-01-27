#include "workPoint.hpp"

workPoint::workPoint(size_t x, size_t y, size_t sizeX, size_t sizeY)
    : interetPoint(x, y, sizeX, sizeY)
{
    _rect.setFillColor(sf::Color::White);
    _type = WORK;
}

workPoint::~workPoint()
{
}

void workPoint::update(void)
{

}

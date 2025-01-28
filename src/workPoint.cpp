#include "workPoint.hpp"

workPoint::workPoint(size_t x, size_t y, size_t sizeX, size_t sizeY)
    : interetPoint(x, y, sizeX, sizeY)
{
    _rect.setOutlineColor(sf::Color::White);
    _type = WORK;
}

workPoint::~workPoint()
{
}

void workPoint::update(void)
{

}

void workPoint::addPerson(Person *pers)
{
    lst.push_back(pers);
}

void workPoint::removePerson(Person *pers)
{
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == pers) {
            lst.erase(lst.begin() + i);
            return;
        }
    }
}

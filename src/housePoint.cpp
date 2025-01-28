#include "housePoint.hpp"

housePoint::housePoint(size_t x, size_t y, size_t sizeX, size_t sizeY)
    : interetPoint(x, y, sizeX, sizeY)
{
    _rect.setOutlineColor(IMUNE_COLOR);
    _type = HOUSE;
}

housePoint::~housePoint()
{
}


void housePoint::addPerson(Person *pers)
{
    lst.push_back(pers);
}

void housePoint::removePerson(Person *pers)
{
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == pers) {
            lst.erase(lst.begin() + i);
            return;
        }
    }
}

void housePoint::update(void)
{
    
}

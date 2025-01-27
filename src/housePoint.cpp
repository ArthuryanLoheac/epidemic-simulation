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

void housePoint::addHabitant(Person *person)
{
    _habitants.push_back(person);
}

void housePoint::update(void)
{
    
}

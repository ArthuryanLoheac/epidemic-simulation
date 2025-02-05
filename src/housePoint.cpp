#include "housePoint.hpp"

housePoint::housePoint(size_t x, size_t y, size_t sizeX, size_t sizeY)
    : interetPoint(x, y, sizeX, sizeY)
{
    _rect.setOutlineColor(HOUSE_COLOR);
    _type = HOUSE;
}

housePoint::~housePoint()
{
}


void housePoint::addPersonHouse(Person *pers)
{
    lst.push_back(pers);
}

void housePoint::removePersonHouse(Person *pers)
{
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == pers) {
            lst.erase(lst.begin() + i);
            return;
        }
    }
}
static void checkMakeSick(std::vector<Person *> lst, int percent)
{
    for (Person *&j : lst) {
        if (j->state == NOT_SICK && (rand() % 100 < percent)) {
            j->setSick();
        }
    }
}

void housePoint::update(float speed, int percent)
{
    if (clock.getElapsedTime().asSeconds() >= (1.f / speed)) {
        for (Person *&i : lst) {
            if (i->state == SICK)
                checkMakeSick(lst, percent);
        }
        clock.restart();
    }
}

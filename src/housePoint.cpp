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
static void checkMakeSick(std::vector<Person *> lst)
{
    for (Person *&j : lst) {
        if (j->state == NOT_SICK && (rand() % 100 < PERCENT_TRANSMISSION_HOME)) {
            j->state = SICK;
        }
    }
}

void housePoint::update(float speed)
{
    if (clock.getElapsedTime().asSeconds() >= (1.f / speed)) {
        for (Person *&i : lst) {
            if (i->state == SICK)
                checkMakeSick(lst);
        }
        clock.restart();
    }
}

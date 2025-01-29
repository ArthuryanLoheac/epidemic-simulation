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

static void checkMakeSick(std::vector<Person *> lst)
{
    for (Person *&j : lst) {
        if (j->state == NOT_SICK && ((rand() % 100) < PERCENT_TRANSMISSION_WORK)) {
            j->setSick();
        }
    }
}

void workPoint::update(float speed)
{
    if (clock.getElapsedTime().asSeconds() >= (1.f / speed)) {
        for (Person *&i : lst) {
            if (i->state == SICK)
                checkMakeSick(lst);
        }
        clock.restart();
    }
}

void workPoint::addPersonWork(Person *pers)
{
    lst.push_back(pers);
}

void workPoint::removePersonWork(Person *pers)
{
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == pers) {
            lst.erase(lst.begin() + i);
            return;
        }
    }
}

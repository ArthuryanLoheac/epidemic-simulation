#pragma once
#include "interetPoint.hpp"
#include "person.hpp"

class housePoint : public interetPoint
{
    public:
        housePoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        std::vector<Person *> lst;
        ~housePoint();
        void update(void) override;
        void addPerson(Person *pers);
        void removePerson(Person *pers);
};
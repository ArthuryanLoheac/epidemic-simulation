#pragma once
#include "interetPoint.hpp"
#include "color.hpp"
#include <SFML/Graphics.hpp>
#include "person.hpp"

class workPoint : public interetPoint
{
    public:
        workPoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        ~workPoint();
        void update(void) override;
        std::vector<Person *> lst;
        void addPerson(Person *pers);
        void removePerson(Person *pers);
};
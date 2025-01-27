#pragma once
#include "interetPoint.hpp"
#include "color.hpp"
#include "person.hpp"

class housePoint : public interetPoint
{
    private:
        std::vector<Person *> _habitants;
    public:
        housePoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        ~housePoint();
        void addHabitant(Person *person);
        void update(void) override;
};
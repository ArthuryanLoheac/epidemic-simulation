#pragma once
#include "interetPoint.hpp"
#include "color.hpp"
#include <SFML/Graphics.hpp>
#include "person.hpp"

class workPoint : public interetPoint
{
    private:
        //std::vector<Person *> _habitants;
    public:
        workPoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        ~workPoint();
        //void addHabitant(Person *person);
        void update(void) override;
};
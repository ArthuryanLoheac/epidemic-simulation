#pragma once
#include "interetPoint.hpp"
#include "color.hpp"
#include <SFML/Graphics.hpp>
#include "person.hpp"

class workPoint : public interetPoint
{
    private:
        int work;
    public:
        workPoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        ~workPoint();
        void update(float speed) override;
        std::vector<Person *> lst;
        void addPersonWork(Person *pers);
        void removePersonWork(Person *pers);
};

#pragma once
#include "interetPoint.hpp"
#include "person.hpp"

class housePoint : public interetPoint
{
    private:
        std::string house;
    public:
        housePoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        std::vector<Person *> lst;
        ~housePoint();
        void update(float speed) override;
        void addPersonHouse(Person *pers);
        void removePersonHouse(Person *pers);
};
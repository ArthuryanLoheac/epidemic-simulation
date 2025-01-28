#include "sim.hpp"

using namespace sf;

void createLstInteretPoints(std::vector<interetPoint *> &lst)
{
    lst.clear();
    for (int i = 0; i < NB_HOUSE; i++) {
        lst.push_back(new housePoint(
            rand() % (WIN_WIDTH - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            rand() % (WIN_HEIGHT - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            HOUSE_SIZE, HOUSE_SIZE));
    }
    for (int i = 0; i < NB_WORKS; i++) {
        lst.push_back(new workPoint(
            rand() % (WIN_WIDTH - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            rand() % (WIN_HEIGHT - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            HOUSE_SIZE, HOUSE_SIZE));
    }
}

void assignPerson(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints)
{
    int id = 0;
    housePoint *house;

    std::vector<interetPoint*> lstHouse;
    setListType(lstInteretPoints, lstHouse, interetPoint::HOUSE);
    std::vector<interetPoint*> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    for (int i = 0; i < heros.size(); i++) {
        id = rand() % lstHouse.size();
        house = ((housePoint *)(lstHouse[id]));
        heros[i]->setHome(house);
        heros[i]->pos = house->getPos() + sf::Vector2f((rand() % HOUSE_SIZE) - (HOUSE_SIZE/2), (rand() % HOUSE_SIZE) - (HOUSE_SIZE/2));
        heros[i]->setNewObj(lstWork);
    }
}

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
    for (int i = 0; i < NB_WORK_POINT; i++) {
        lst.push_back(new workPoint(
            rand() % (WIN_WIDTH - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            rand() % (WIN_HEIGHT - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            HOUSE_SIZE, HOUSE_SIZE));
    }
}

void assignOnePerson(std::vector<interetPoint *> &lstInteretPoints, Person *hero)
{
    int id = 0;
    housePoint *house;
    std::vector<interetPoint*> lstHouse;
    setListType(lstInteretPoints, lstHouse, interetPoint::HOUSE);
    std::vector<interetPoint*> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    id = rand() % lstHouse.size();
    house = ((housePoint *)(lstHouse[id]));
    hero->setHome(house);
    hero->pos = house->getPos() + sf::Vector2f((rand() % HOUSE_SIZE) - (HOUSE_SIZE/2), (rand() % HOUSE_SIZE) - (HOUSE_SIZE/2));
    hero->setNewObj(lstWork);
}

static void assignOnePerson(std::vector<interetPoint *> &lstInteretPoints, std::vector<Person *> &heros,
    std::vector<interetPoint*> lstHouse, std::vector<interetPoint*> lstWork, int i)
{
    int id = 0;
    housePoint *house;

    id = rand() % lstHouse.size();
    house = ((housePoint *)(lstHouse[id]));
    heros[i]->setHome(house);
    heros[i]->pos = house->getPos() + sf::Vector2f((rand() % HOUSE_SIZE) - (HOUSE_SIZE/2), (rand() % HOUSE_SIZE) - (HOUSE_SIZE/2));
    heros[i]->setNewObj(lstWork);
}

void assignPerson(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints)
{
    std::vector<interetPoint*> lstHouse;
    setListType(lstInteretPoints, lstHouse, interetPoint::HOUSE);
    std::vector<interetPoint*> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    for (int i = 0; i < heros.size(); i++)
        assignOnePerson(lstInteretPoints, heros, lstHouse, lstWork, i);
}

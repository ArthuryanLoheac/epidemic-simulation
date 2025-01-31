#include "sim.hpp"
using namespace sf;

static void updateHerosSick(Person *hero)
{
    hero->dayInfection -= 1;
    if (hero->dayInfection == 0) {
        int r = (rand() % 100) + 1;
        if (r < PERCENT_DEAD)
            hero->state = DEAD;
        else
            hero->state = RECOVERED;
    }
}

static void setHerosNewDatas(std::vector<interetPoint *> lstWork,
    std::vector<Person *> &heros)
{
    for (int i = 0; i < heros.size(); i++) {
        if (heros[i]->state != DEAD) {
            heros[i]->setNewObj(lstWork);
            heros[i]->setNewDay();
            if (heros[i]->state == SICK)
                updateHerosSick(heros[i]);
        }
    }
}

static bool isEven(Person *n) {
    return n->state == LIFE_DEATH;
}

static void resetLen(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints)
{
    Person *p;
    bool r = false;

    while (heros.size() < NUMBER_PERSON) {
        r = (rand() % 100) < PERCENT_IMUNE_BORN;
        p = create_person(heros.back()->id + 1, r);
        assignOnePerson(lstInteretPoints, p);
        heros.push_back(p);
    }
}

void newDay(std::vector<Person *> &heros,
    std::vector<interetPoint *> &lstInteretPoints, window_game* game)
{
    std::vector<interetPoint *> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    game->Days++;
    setHerosNewDatas(lstWork, heros);
    heros.erase(std::remove_if(heros.begin(), heros.end(), isEven), heros.end());
    resetLen(heros, lstInteretPoints);
}
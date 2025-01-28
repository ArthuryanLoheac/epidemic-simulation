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
        heros[i]->isBackHome = false;
        heros[i]->isGoingWorking = (rand() % NB_PLACE_VISIT_A_DAY) + 1;
        heros[i]->setNewObj(lstWork);
        if (heros[i]->state == SICK)
            updateHerosSick(heros[i]);
    }
}

void newDay(std::vector<Person *> &heros,
    std::vector<interetPoint *> &lstInteretPoints, window_game* game)
{
    std::vector<interetPoint *> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    game->Days++;
    setHerosNewDatas(lstWork, heros);
}
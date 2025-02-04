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
    return (n->state == LIFE_DEATH || n->state == IMUNE_DEATH);
}

static void resetLen(std::vector<Person *> &heros,
    std::vector<interetPoint *> &lstInteretPoints, int nbImune, int nbRecovered)
{
    Person *p;
    bool r = false;

    while (heros.size() < NUMBER_PERSON) {
        r = (rand() % 100) < PERCENT_IMUNE_BORN;
        if (nbRecovered)
            nbRecovered--;
        else
            r = false;
        p = create_person(heros.back()->id + 1, r);
        if (nbImune-- > 0)
            p->state = IMUNE;
        assignOnePerson(lstInteretPoints, p);
        heros.push_back(p);
    }
}

float getPercentType(PersonDisease type, std::vector<Person *> &heros)
{
    int len = NUMBER_PERSON;
    int nbType = 0;

    for (auto &i : heros) {
        if (i->state == type)
            nbType++;
    }
    return (float)nbType / (float)len;
}

void newDay(std::vector<Person *> &heros,
    std::vector<interetPoint *> &lstInteretPoints, window_game* game)
{
    std::vector<interetPoint *> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);
    int nbImune = 0;
    int nbRecovered = 0;

    game->percentSick.push_front(getPercentType(SICK, heros));
    if (game->percentSick.size() > 200)
        game->percentSick.pop_back();
    game->percentImune.push_front(getPercentType(IMUNE, heros));
    if (game->percentImune.size() > 200)
        game->percentImune.pop_back();
    game->percentRecovered.push_front(getPercentType(RECOVERED, heros));
    if (game->percentRecovered.size() > 200)
        game->percentRecovered.pop_back();
    game->percentDead.push_front(getPercentType(DEAD, heros));
    if (game->percentDead.size() > 200)
        game->percentDead.pop_back();

    game->Days++;
    setHerosNewDatas(lstWork, heros);
    for (auto &i : heros) {
        if (i->state == IMUNE_DEATH)
            nbImune++;
        if (i->state == RECOVERED)
            nbRecovered++;
    }
    heros.erase(std::remove_if(heros.begin(), heros.end(),
        isEven), heros.end());
    resetLen(heros, lstInteretPoints, nbImune, nbRecovered);
}

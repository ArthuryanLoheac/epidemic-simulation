#include "sim.hpp"
using namespace sf;
using namespace std;

void setListType(std::vector<interetPoint*> &lstSrc, std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type)
{
    for (int i = 0; i < lstSrc.size(); i++) {
        if (lstSrc[i]->getType() == type) {
            lstDest.push_back(((housePoint *)(lstSrc[i])));
        }
    }
}

void update_all_person(std::vector<Person *> &heros, window_game* game, std::vector<interetPoint *> &lstInteretPoints)
{
    int i = 0;
    for (int i = 0; i < heros.size(); i++)
    {
        if (heros[i]->state != DEAD)
            heros[i]->update_pers(game->deltaTime, heros, lstInteretPoints);
    }
}

int get_total_state(std::vector<Person *> heros, PersonDisease state)
{
    int nb = 0;
    int i = 0;

    for (int i = 0; i < heros.size(); i++)
    {
        if (heros[i]->state == state)
            nb++;
    }
    return nb;
}

void update_stats(stats_game* stats, std::vector<Person *> &heros)
{
    stats->nb_imune = get_total_state(heros, IMUNE);
    stats->txt_imune->setString("Imunes : " + to_string(stats->nb_imune));
    stats->nb_death = get_total_state(heros, DEAD);
    stats->txt_death->setString("Deads : " + to_string(stats->nb_death));
    stats->nb_sick = get_total_state(heros, SICK);
    stats->txt_sick->setString("Sick : " + to_string(stats->nb_sick));
    stats->nb_not_sick = get_total_state(heros, NOT_SICK);
    stats->txt_not_sick->setString("Not Sick : " + to_string(stats->nb_not_sick));
    stats->nb_recovered = get_total_state(heros, RECOVERED);;
    stats->txt_recovered->setString("Recovered : " + to_string(stats->nb_recovered));
    stats->nb_alives = stats->nb_imune + stats->nb_sick + stats->nb_not_sick + stats->nb_recovered;
    stats->txt_alives->setString("Alives : " + to_string(stats->nb_alives));
}

int isAllBack(std::vector<Person *> heros)
{
    int len = 0;

    for (int i = 0; i < heros.size(); i++) {
        if (heros[i]->state == DEAD)
            continue;
        if (heros[i]->isBackHome == false)
            len++;
    }
    return len;
}

void newDay(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints)
{
    std::vector<interetPoint *> lstWork;
    setListType(lstInteretPoints, lstWork, interetPoint::WORK);

    for (int i = 0; i < heros.size(); i++) {
        heros[i]->isBackHome = false;
        heros[i]->isGoingWorking = true;
        heros[i]->setNewObj(lstWork);
    }
}

void update(std::vector<Person *> &heros, window_game* game, std::vector<interetPoint *> &lstInteretPoints)
{
    //std::cout << isAllBack(heros) << endl;
    if (isAllBack(heros) == 0)
        newDay(heros, lstInteretPoints);
    game->deltaTime = game->clock->restart().asSeconds();
    update_all_person(heros, game, lstInteretPoints);
    update_stats(game->stats, heros);
}
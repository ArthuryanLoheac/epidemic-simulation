#include "sim.hpp"
#include <format>
using namespace sf;
using namespace std;

void setListType(std::vector<interetPoint*> &lstSrc,
    std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type)
{
    for (int i = 0; i < lstSrc.size(); i++) {
        if (lstSrc[i]->getType() == type) {
            lstDest.push_back(((housePoint *)(lstSrc[i])));
        }
    }
}

static int get_total_state(std::vector<Person *> heros, PersonDisease state)
{
    int nb = 0;
    int i = 0;

    for (int i = 0; i < heros.size(); i++) {
        if (heros[i]->state == state)
            nb++;
    }
    return nb;
}

static void update_stats(stats_game* stats, std::vector<Person *> &heros)
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

static int isAllBack(std::vector<Person *> heros)
{
    int len = 0;

    for (int i = 0; i < heros.size(); i++) {
        if (heros[i]->state == DEAD)
            continue;
        if (heros[i]->moveStatus != ATHOME)
            len++;
    }
    return len;
}

void updateAllInteretPoint(std::vector<interetPoint *> &lstInteretPoints, window_game* game)
{
    for (interetPoint *&i : lstInteretPoints) {
        if (dynamic_cast<housePoint *>(i))
            ((housePoint *)(i))->update(game->speed);
        if (dynamic_cast<workPoint *>(i))
            ((workPoint *)(i))->update(game->speed);
    }
}

void update(std::vector<Person *> &heros, window_game* game, std::vector<interetPoint *> &lstInteretPoints)
{
    if (isAllBack(heros) == 0)
        newDay(heros, lstInteretPoints, game);
    game->deltaTime = game->clock->restart().asSeconds() * game->speed;

    update_all_person(heros, game, lstInteretPoints);
    update_stats(game->stats, heros);
    updateAllInteretPoint(lstInteretPoints, game);

    game->txt_days->setString("Days : " + to_string(game->Days));
    game->txt_speed->setString("Speed : x" + std::format("{:.1f}", game->speed));

}

#include "sim.hpp"
using namespace sf;
using namespace std;

void update_all_person(std::vector<Person *> heros, window_game* game, std::vector<interetPoint *> &lstInteretPoints)
{
    int i = 0;
    for (int i = 0; i < heros.size(); i++)
    {
        if (heros[i]->state != DEAD)
            heros[i]->update_pers(game->deltaTime, heros, lstInteretPoints);
        i++;
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
        i++;
    }
    return nb;
}

void update_stats(stats_game* stats, std::vector<Person *> heros)
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

void update(std::vector<Person *> heros, window_game* game, std::vector<interetPoint *> &lstInteretPoints)
{
    game->deltaTime = game->clock->restart().asSeconds();
    update_all_person(heros, game, lstInteretPoints);
    update_stats(game->stats, heros);
}
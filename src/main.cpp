#include "sim.hpp"

using namespace sf;

void init(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints, window_game &game)
{
    game.percentImune.clear();
    game.percentRecovered.clear();
    game.percentSick.clear();
    create_lst_person(heros);
    createLstInteretPoints(lstInteretPoints);
    assignPerson(heros, lstInteretPoints);
    game.Days = 1;
}

void deleteAll(window_game* game, std::vector<Person *> heros, std::vector<interetPoint *> lstInteretPoints)
{
    delete game->window;
    delete game->clock;
    delete game->stats->txt_alives;
    delete game->stats->txt_death;
    delete game->stats->txt_imune;
    delete game->stats->txt_not_sick;
    delete game->stats->txt_recovered;
    delete game->stats->txt_sick;
    delete game->stats;
    delete game->font;
    delete game->txt_days;
    delete game->txt_speed;
    delete game;
    for (int i = 0; i < NUMBER_PERSON; i++)
        delete heros[i];
    for (int i = 0; i < NB_HOUSE + NB_WORK_POINT; i++)
        delete lstInteretPoints[i];
}

int main()
{
    window_game* game = create_window_game();
    std::vector<Person *> heros;
    std::vector<interetPoint *> lstInteretPoints;
    init(heros, lstInteretPoints, *game);

    while (game->window->isOpen())
    {
        Event event;
        while (game->window->pollEvent(event)) {
            compute_event(event, game, heros, lstInteretPoints);
        }
        update(heros, game, lstInteretPoints);
        draw(game, heros, lstInteretPoints);
    }
    deleteAll(game, heros, lstInteretPoints);
    return 0;
}

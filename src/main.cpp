#include "sim.hpp"

using namespace sf;

void init(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints, window_game &game)
{
    create_lst_person(heros);
    createLstInteretPoints(lstInteretPoints);
    assignPerson(heros, lstInteretPoints);
    game.Days = 1;
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
    delete game;
    return 0;
}

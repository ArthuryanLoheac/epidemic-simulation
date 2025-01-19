#include "sim.h"

using namespace sf;

int main()
{
    window_game* game = create_window_game();
    Person** heros = create_lst_person();

    while (game->window->isOpen())
    {
        Event event;
        while (game->window->pollEvent(event)) {
            compute_event(event, game->window, &heros);
        }
        update(heros, game);
        draw(game, heros);
    }

    delete game;
    delete heros;
    return 0;
}

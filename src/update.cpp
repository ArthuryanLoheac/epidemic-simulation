#include "sim.h"
using namespace sf;

void update(Person** heros, window_game* game)
{
    int i = 0;

    game->deltaTime = game->clock->restart().asSeconds();

    while(heros[i])
    {
        if (heros[i]->state != DEAD)
            heros[i]->update_pers(game->deltaTime, heros);
        i++;
    }
}
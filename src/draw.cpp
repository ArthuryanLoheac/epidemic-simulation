#include "sim.h"

void draw_circles_dead(RenderWindow *window, Person** lst)
{
    int i = 0;

    while(lst[i])
    {
        if (lst[i]->state == DEAD)
            window->draw(*(lst[i]->circle));
        i++;
    }
}
void draw_circles_other(RenderWindow *window, Person** lst)
{
    int i = 0;

    while(lst[i])
    {
        if (lst[i]->state != DEAD)
            window->draw(*(lst[i]->circle));
        i++;
    }
}

void draw_stats(stats_game *stats, RenderWindow *window)
{
    window->draw(*(stats->txt_imune));
    window->draw(*(stats->txt_death));
    window->draw(*(stats->txt_sick));
    window->draw(*(stats->txt_not_sick));
    window->draw(*(stats->txt_alives));
}

void draw(window_game *game, Person** lst)
{
    game->window->clear(DARK_BLUE);

    draw_circles_dead(game->window, lst);
    draw_circles_other(game->window, lst);

    draw_stats(game->stats, game->window);

    game->window->display();
}
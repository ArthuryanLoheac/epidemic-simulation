#include "sim.hpp"

void draw_circles_dead(RenderWindow *window, std::vector<Person *> lst)
{
    int i = 0;

    for (int i = 0; i < lst.size(); i++)
    {
        if (lst[i]->state == DEAD)
            window->draw(*(lst[i]->circle));
        i++;
    }
}

void draw_circles_other(RenderWindow *window, std::vector<Person *> lst)
{
    int i = 0;

    for (int i = 0; i < lst.size(); i++)
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
    window->draw(*(stats->txt_recovered));
}

void draw(window_game *game, std::vector<Person *> lst, std::vector<interetPoint *> lstPoints)
{
    game->window->clear(DARK_BLUE);

    draw_circles_dead(game->window, lst);
    draw_circles_other(game->window, lst);

    for (interetPoint *&point:lstPoints) {
        point->draw(game->window);
    }

    draw_stats(game->stats, game->window);

    game->window->display();
}

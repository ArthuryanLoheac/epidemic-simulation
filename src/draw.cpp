#include "sim.hpp"

void draw_circles_dead(RenderWindow *window, std::vector<Person *> lst)
{
    int i = 0;

    for (int i = 0; i < lst.size(); i++) {
        if (lst[i]->state == DEAD)
            window->draw(*(lst[i]->circle));
    }
}

void draw_circles_other(RenderWindow *window, std::vector<Person *> lst)
{
    int i = 0;

    for (int i = 0; i < lst.size(); i++) {
        if (lst[i]->state != DEAD)
            window->draw(*(lst[i]->circle));
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

void draw_graph(window_game *game)
{
    sf::CircleShape c;
    c.setRadius(1);

    for (int i = 0; i < game->percentSick.size(); i++) {
        c.setFillColor(SICK_COLOR);
        for (int j = 0; j < (game->percentSick[i] * 200); j++) {
            c.setPosition((WIN_WIDTH-200) + (game->percentSick.size() - i), WIN_HEIGHT - j);
            game->window->draw(c);
        }
        c.setFillColor(RECOVERED_COLOR);
        for (int j = (game->percentSick[i] * 200); j < (game->percentSick[i] * 200) + (game->percentRecovered[i] * 200); j++) {
            c.setPosition((WIN_WIDTH-200) + (game->percentRecovered.size() - i), WIN_HEIGHT - j);
            game->window->draw(c);
        }
        c.setFillColor(IMUNE_COLOR);
        for (int j = (game->percentSick[i] * 200) + (game->percentRecovered[i] * 200);
            j < (game->percentSick[i] * 200) + (game->percentRecovered[i] * 200) + (game->percentImune[i] * 200); j++) {
            c.setPosition((WIN_WIDTH-200) + (game->percentSick.size() - i), WIN_HEIGHT - j);
            game->window->draw(c);
        }
    }
}

void draw(window_game *game, std::vector<Person *> lst, std::vector<interetPoint *> lstPoints)
{
    game->window->clear(DARK_BLUE);

    draw_circles_dead(game->window, lst);
    draw_circles_other(game->window, lst);
    for (interetPoint *&point:lstPoints)
        point->draw(game->window);
    draw_graph(game);
    draw_stats(game->stats, game->window);
    game->window->draw(*(game->txt_days));
    game->window->draw(*(game->txt_speed));

    game->window->display();
}

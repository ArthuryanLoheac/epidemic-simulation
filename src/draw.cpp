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

void paintPixels(int start, int end, window_game *game, int i, sf::CircleShape &c)
{
    for (int j = start; j < end; j++) {
        c.setPosition((WIN_WIDTH-200) + (game->percentSick.size() - i), WIN_HEIGHT - j);
        game->window->draw(c);
    }
}

void drawTxtGraph(window_game *game)
{
    sf::Font f;
    sf::Text t;

    f.loadFromFile("font/Oswald-Bold.ttf");
    t.setFont(f);
    t.setString("100%");
    t.setFillColor(BLUE);
    t.setCharacterSize(14);
    t.setPosition(WIN_WIDTH-200, WIN_HEIGHT-200);
    game->window->draw(t);
}

void draw_graph(window_game *game)
{
    sf::CircleShape c;
    c.setRadius(1);
    int Sick = 0;
    int Recovered = 0;
    int Imune = 0;
    int Dead = 0;
    sf::RectangleShape r(sf::Vector2f(200, 200));
    r.setPosition(WIN_WIDTH-200, WIN_HEIGHT-200);
    r.setOutlineColor(BLUE);
    r.setFillColor(sf::Color::Transparent);
    r.setOutlineThickness(2);
    game->window->draw(r);
    drawTxtGraph(game);

    for (int i = 0; i < game->percentSick.size(); i++) {
        Dead = (game->percentDead[i] * 200);
        Sick = Dead + (game->percentSick[i] * 200);
        Recovered = Sick + (game->percentRecovered[i] * 200);
        Imune = Recovered + (game->percentImune[i] * 200);

        c.setFillColor(DEAD_COLOR);
        paintPixels(0, Dead, game, i, c);
        c.setFillColor(SICK_COLOR);
        paintPixels(Dead, Sick, game, i, c);
        c.setFillColor(RECOVERED_COLOR);
        paintPixels(Sick, Recovered, game, i, c);
        c.setFillColor(IMUNE_COLOR);
        paintPixels(Recovered, Imune, game, i, c);
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
    game->Peoples->draw(game->window);

    game->window->display();
}

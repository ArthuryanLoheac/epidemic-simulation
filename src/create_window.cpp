#include "sim.hpp"

using namespace sf;
using namespace std;

CircleShape *create_circle(Vector2f pos)
{
    CircleShape *circle = new CircleShape();
    circle->setRadius(RADIUS_CIRCLE);
    circle->setOrigin(RADIUS_CIRCLE/2, RADIUS_CIRCLE/2);
    circle->setFillColor(NOT_SICK_COLOR);
    circle->setPosition(pos);
    return circle;
}

Person *create_person(int id, float x = 0.f, float y = 0.f)
{
    Person *pers = new Person();
    pers->pos = Vector2f(x,y);
    pers->id = id;
    pers->circle = create_circle(pers->pos);
    pers->speed = (rand() % (SPEED_MAX - SPEED_MIN)) + SPEED_MIN;
    pers->setNewObj();
    return pers;
}

void create_lst_person(vector<Person *> &lst)
{
    lst.clear();
    for (int i = 0; i < NUMBER_PERSON; i++) {
        lst.push_back(create_person(i, 0, 0));
    }
    for (int i = 0; i < min(NUMBER_INFECTED_START, NUMBER_PERSON); i++) {
        lst[i]->state = SICK; 
    }
}

RenderWindow* create_window()
{
    RenderWindow *window = new RenderWindow(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Simulation");
    window->setVerticalSyncEnabled(true);
    return window;
}

Text* create_text(String txt, Font* fnt, int i, Color c)
{
    Text* text = new Text();

    text->setFont(*fnt);
    text->setString(txt);
    text->setCharacterSize(20);
    text->setFillColor(c);
    text->setStyle(Text::Bold);
    text->setPosition(0, i*24);
    return text;
}

stats_game* create_stats(Font* fnt)
{
    stats_game *stats = new stats_game();

    stats->nb_imune = 0;
    stats->nb_death = 0;
    stats->nb_sick = 0;
    stats->nb_not_sick = 0;
    stats->nb_alives = 0;
    stats->nb_recovered = 0;
    stats->txt_imune = create_text("Imunes : ",fnt, 3, IMUNE_COLOR);
    stats->txt_recovered = create_text("Recovered : ",fnt, 1, RECOVERED_COLOR);
    stats->txt_alives = create_text("Alives : ",fnt, 5, Color::White);
    stats->txt_death = create_text("Dead : ",fnt, 4, Color::White);
    stats->txt_sick = create_text("Sick : ",fnt, 2, SICK_COLOR);
    stats->txt_not_sick = create_text("Not Sick : ",fnt, 0, NOT_SICK_COLOR);
    return stats;
}

window_game* create_window_game()
{
    srand((unsigned)time(0));
    window_game *game = new window_game();
    game->window = create_window();
    game->clock = new Clock();
    game->font = new Font();
    game->font->loadFromFile("font/Oswald-Bold.ttf");
    game->stats = create_stats(game->font);
    game->speed = 1;
    game->Days = 1;
    game->txt_speed = create_text("Speed : x1",game->font, (WIN_HEIGHT / 24) - 1, sf::Color::White);
    game->txt_days = create_text("Days : 1",game->font, (WIN_HEIGHT / 24) - 2, sf::Color::White);
    return game;
}
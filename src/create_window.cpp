#include "sim.h"

using namespace sf;

CircleShape *create_circle(Vector2f pos)
{
    CircleShape *circle = new CircleShape();
    circle->setRadius(RADIUS_CIRCLE);
    circle->setOrigin(RADIUS_CIRCLE/2, RADIUS_CIRCLE/2);
    circle->setFillColor(BEIGE);
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

Person** create_lst_person()
{   
    Person** lst = new Person*[NUMBER_PERSON+1];
    for (int i = 0; i<NUMBER_PERSON; i++) {
        lst[i] = create_person(i,
            rand() % (WIN_WIDTH-RADIUS_CIRCLE) + RADIUS_CIRCLE/2,
            rand() % (WIN_HEIGHT-RADIUS_CIRCLE) + RADIUS_CIRCLE/2);
    }
    lst[NUMBER_PERSON] = NULL;
    lst[0]->state = SICK;
    return lst;
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
    stats->txt_imune = create_text("Imunes : ",fnt, 2, LIGHT_BLUE);
    stats->txt_alives = create_text("Alives : ",fnt, 4, Color::White);
    stats->txt_death = create_text("Dead : ",fnt, 3, Color::White);
    stats->txt_sick = create_text("Sick : ",fnt, 1, RED);
    stats->txt_not_sick = create_text("Not Sick : ",fnt, 0, BEIGE);

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
    return game;
}
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

window_game* create_window_game()
{
    srand((unsigned)time(0));
    window_game *game = new window_game();
    game->window = create_window();
    game->clock = new Clock();
    return game;
}
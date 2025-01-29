#include "sim.hpp"

using namespace sf;
using namespace std;

static CircleShape *create_circle(Vector2f pos)
{
    CircleShape *circle = new CircleShape();
    circle->setRadius(RADIUS_CIRCLE);
    circle->setOrigin(RADIUS_CIRCLE/2, RADIUS_CIRCLE/2);
    circle->setFillColor(NOT_SICK_COLOR);
    circle->setPosition(pos);
    return circle;
}

static Person *create_person(int id, float x = 0.f, float y = 0.f)
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
    for (int i = 0; i < min(NUMBER_INFECTED_START, NUMBER_PERSON); i++)
        lst[i]->setSick();
}

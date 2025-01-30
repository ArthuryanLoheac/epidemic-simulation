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

Person *create_person(int id, float x, float y)
{
    Person *pers = new Person();
    pers->pos = Vector2f(x,y);
    pers->id = id;
    pers->circle = create_circle(pers->pos);
    pers->speed = (rand() % (SPEED_MAX - SPEED_MIN)) + SPEED_MIN;
    pers->lifeTimeRemaining = (rand() % (LIFE_TIME - 1)) + 1;
    pers->setNewObj();
    return pers;
}

void create_lst_person(vector<Person *> &lst)
{
    lst.clear();
    for (int i = 0; i < NUMBER_PERSON; i++) {
        lst.push_back(create_person(i));
    }
    for (int i = 0; i < min(NUMBER_INFECTED_START, NUMBER_PERSON); i++)
        lst[i]->setSick();
}

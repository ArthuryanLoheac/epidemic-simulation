#include "person.hpp"

void Person::setNewObj() {
    objectif = Vector2f(rand() % (WIN_WIDTH-RADIUS_CIRCLE) + RADIUS_CIRCLE/2,
                        rand() % (WIN_HEIGHT-RADIUS_CIRCLE) + RADIUS_CIRCLE/2);
    direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
}

void Person::update_pers(float deltaTime, std::vector<Person *> lst)
{
    check_disease_time();
    pos += (direction * deltaTime * speed);
    circle->setPosition(pos);
    if (get_dist(pos, objectif) <= 10.f)
        setNewObj();
    check_infected(lst);
    set_color();
}

float Person::get_dist(Vector2f a, Vector2f b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((b.y - a.y), 2));
}

void Person::check_disease_time()
{
    if (state == SICK && timeInfection.getElapsedTime() >= seconds(TIME_SICK)) {
        int id = rand() % (PERCENT_DEAD + PERCENT_RECOVERED);
        if (id < PERCENT_DEAD) {
            state = DEAD;
        } else if (id < PERCENT_RECOVERED) {
            state = RECOVERED;
        }
    }
}

void Person::set_color()
{
    if (state == NOT_SICK) {
        circle->setFillColor(NOT_SICK_COLOR);
    } else if (state == SICK) {
        circle->setFillColor(SICK_COLOR);
    } else if (state == IMUNE) {
        circle->setFillColor(IMUNE_COLOR);
    } else if (state == DEAD) {
        circle->setFillColor(DEAD_COLOR);
    } else if (state == RECOVERED) {
        circle->setFillColor(RECOVERED_COLOR);
    }
}

void Person::check_infected(std::vector<Person *> lst)
{
    int i = 0;

    for (int i = 0; i < lst.size(); i++) {
        if (i != id && get_dist(pos, lst[i]->pos) < RADIUS_INFECTION
            && lst[i]->state == SICK && state == NOT_SICK)
        {
            state = SICK;
            timeInfection.restart();
        }
        i++;
    }
}
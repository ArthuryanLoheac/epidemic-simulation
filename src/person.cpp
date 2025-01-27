#include "person.hpp"
#include <housePoint.hpp>


Person::Person() {
    isGoingWorking = (rand() % NB_PLACE_VISIT_A_DAY) + 1;
    isBackHome = false;
    state = NOT_SICK;
}

void Person::setNewObj() {
    objectif = Vector2f(rand() % (WIN_WIDTH-RADIUS_CIRCLE) + RADIUS_CIRCLE/2,
                        rand() % (WIN_HEIGHT-RADIUS_CIRCLE) + RADIUS_CIRCLE/2);
    direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
}

void Person::setHome(interetPoint *home)
{
    _home = home;
}

void Person::setNewObj(std::vector<interetPoint *> &lstInteretPoints)
{
    interetPoint *point = lstInteretPoints[rand() % lstInteretPoints.size()];

    objectif = point->getPos();
    direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
}

void Person::setNewObj(interetPoint *point)
{
    objectif = point->getPos();
    direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
}

void Person::setListType_pers(std::vector<interetPoint*> &lstSrc, std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type)
{
    for (int i = 0; i < lstSrc.size(); i++) {
        if (lstSrc[i]->getType() == type) {
            lstDest.push_back(((housePoint *)(lstSrc[i])));
        }
    }
}

void Person::arrivedAtObjectif(std::vector<interetPoint *> &lstInteretPoints)
{
    std::vector<interetPoint *> lstWork;
    setListType_pers(lstInteretPoints, lstWork, interetPoint::WORK);

    isGoingWorking--;
    if (isGoingWorking == 0) {
        setNewObj(_home);
    } else if (isGoingWorking == -1) {
        isBackHome = true;
        isGoingWorking = true;
    } else {
        setNewObj(lstWork);
    }
}

void Person::update_pers(float deltaTime, std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints)
{
    check_disease_time();
    if (isBackHome == false)
        pos += (direction * deltaTime * speed);
    circle->setPosition(pos);
    if (get_dist(pos, objectif) <= 5.f) {
        arrivedAtObjectif(lstInteretPoints);
    }
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
    }
}
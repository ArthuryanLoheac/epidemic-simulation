#include "person.hpp"
#include <housePoint.hpp>


Person::Person() {
    isGoingWorking = (rand() % NB_PLACE_VISIT_A_DAY) + 1;
    isBackHome = false;
    state = NOT_SICK;
}

void Person::setSick()
{
    state = SICK;
    dayInfection = 3;
}

float Person::getRandomWait()
{
    isWaiting = true;
    return (float)((rand() % (MAX_SECONDS_WORKING - MIN_SECONDS_WORKING)) + MIN_SECONDS_WORKING);
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

    timeWaited = 0;
    isGoingWorking--;
    if (isGoingWorking == 0) { // ARRIVED LAST INTERET POINT
        setNewObj(_home);
        timeWaiting = getRandomWait();
    } else if (isGoingWorking == -1) { // ARRIVED HOME
        isBackHome = true;
        isGoingWorking = true;
        timeWaiting = (rand() % 10)/10.f;
    } else { // ARRIVED INTERET POINT
        setNewObj(lstWork);
        timeWaiting = getRandomWait();
    }
}

void Person::update_pers(float deltaTime, float speedGeneral
    , std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints)
{
    timeWaited += clockWaiting.getElapsedTime().asSeconds() * speedGeneral;
    clockWaiting.restart();
    if (timeWaited >= timeWaiting && isWaiting)
        isWaiting = false;
    //If not home move
    if (isBackHome == false && !isWaiting)
        pos += (direction * deltaTime * speed);
    circle->setPosition(pos);
    if (get_dist(pos, objectif) <= 5.f && !isWaiting)
        arrivedAtObjectif(lstInteretPoints);
    if (state == SICK)
        check_infected(lst);
}

float Person::get_dist(Vector2f a, Vector2f b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((b.y - a.y), 2));
}

void Person::update_color()
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
            && state == SICK && lst[i]->state == NOT_SICK)
            lst[i]->setSick();
    }
}
#include "person.hpp"
#include "housePoint.hpp"
#include "workPoint.hpp"

static CircleShape *create_circle(Vector2f pos)
{
    CircleShape *circle = new CircleShape();
    circle->setRadius(RADIUS_CIRCLE);
    circle->setOrigin(RADIUS_CIRCLE/2, RADIUS_CIRCLE/2);
    circle->setFillColor(NOT_SICK_COLOR);
    circle->setPosition(pos);
    return circle;
}

Person::Person(float x, float y, int uid, bool imune)
{
    setNewDay();
    state = imune ? IMUNE : NOT_SICK;
    pos = Vector2f(x,y);
    prevPos = pos;
    id = uid;
    circle = create_circle(pos);
    speed = (rand() % (SPEED_MAX - SPEED_MIN)) + SPEED_MIN;
    lifeTimeRemaining = (rand() % (LIFE_TIME - 1)) + 1;
    setNewObj();
}

void Person::setSick()
{
    state = SICK;
    dayInfection = 3;
}

void Person::setNewDay()
{
    nbVisitsRemaining = ((rand() % NB_PLACE_VISIT_A_DAY) + 1);
    moveStatus = WAITING_AT_HOME;
    timeWaiting = (rand() % 300) / 100.f;
    clock.restart();
    lifeTimeRemaining--;
    if (lifeTimeRemaining <= 0) {
        if (state == IMUNE)
            state = IMUNE_DEATH;
        else
            state = LIFE_DEATH;
    }
}

void Person::setHome(interetPoint *home)
{
    _home = home;
}

void Person::setNewObj()
{
}

void Person::setNewObj(std::vector<interetPoint *> &lstInteretPoints)
{
    interetPoint *point = lstInteretPoints[rand() % lstInteretPoints.size()];
    _obj = point;
    setNewObj(point);
}

void Person::setNewObj(interetPoint *point)
{
    objectif = point->getPos();
    computeDir();
}

void Person::setListType_pers(std::vector<interetPoint*> &lstSrc,
    std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type)
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

    nbVisitsRemaining--;
    if (nbVisitsRemaining == -1) {// ARRIVE AT HOME
        moveStatus = ATHOME;
        ((housePoint *)(_home))->addPersonHouse(this);
    }
    if (nbVisitsRemaining == 0) { // ARRIVED LAST INTERET POINT
        setNewObj(_home);
        ((workPoint *)(_obj))->addPersonWork(this);
        moveStatus = WORKING;
        timeWaiting = rand() % 3;
        clock.restart();
    }
    if (nbVisitsRemaining > 0) { // ARRIVED INTERET POINT
        setNewObj(lstWork);
        ((workPoint *)(_obj))->addPersonWork(this);
        moveStatus = WORKING;
        timeWaiting = rand() % 3;
        clock.restart();
    }
}

void Person::statusMoving(float deltaTime, std::vector<interetPoint *> &lstInteretPoints)
{
    prevPos = pos;
    pos += (direction * deltaTime * speed);
    if (get_dist(pos, objectif) <= 5.f)
        arrivedAtObjectif(lstInteretPoints);
    else if (get_dist(prevPos, objectif) < get_dist(pos, objectif)) {
        pos = objectif;
        arrivedAtObjectif(lstInteretPoints);
    }
}

void Person::statusAtHome()
{
}

void Person::statusWaitingAtHome(float speed)
{
    if (clock.getElapsedTime().asSeconds() >= (timeWaiting / speed)) {
        moveStatus = MOVING;
        ((housePoint *)(_home))->removePersonHouse(this);
    }
}

void Person::statusWorking(float speed)
{
    if (clock.getElapsedTime().asSeconds() >= (timeWaiting / speed)) {
        moveStatus = MOVING;
        ((workPoint *)(_obj))->removePersonWork(this);
    }
}

void Person::update_pers(float deltaTime, float speedGeneral
    , std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints)
{
    //If not home move
    if (moveStatus == MOVING)
        statusMoving(deltaTime, lstInteretPoints);
    if (moveStatus == ATHOME)
        statusAtHome();
    if (moveStatus == WORKING)
        statusWorking(speedGeneral);
    if (moveStatus == WAITING_AT_HOME)
        statusWaitingAtHome(speedGeneral);

    if (pos.x < 0 || pos.y < 0 || pos.x > (WIN_WIDTH - 200) || pos.y > WIN_HEIGHT)
        computeDir();
    circle->setPosition(pos);
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

void Person::computeDir()
{
    direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
}

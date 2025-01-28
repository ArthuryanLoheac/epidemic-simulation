#include "person.hpp"
#include "housePoint.hpp"
#include "workPoint.hpp"


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
    setNewObj(point);
}

void Person::setNewObj(interetPoint *point)
{
    objectif = point->getPos();
    objPoint = point;
    computeDir();
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
    if (dynamic_cast<housePoint *>(objPoint))
        ((housePoint *)(objPoint))->addPerson(this);
    if (dynamic_cast<workPoint *>(objPoint))
        ((workPoint *)(objPoint))->addPerson(this);
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

void Person::updateClockPerson(float speedGeneral)
{
    timeWaited += clockWaiting.getElapsedTime().asSeconds() * speedGeneral;
    clockWaiting.restart();
    if (timeWaited >= timeWaiting && isWaiting) { // LEAVE POINT
        isWaiting = false;
        if (dynamic_cast<housePoint *>(objPoint))
            ((housePoint *)(objPoint))->removePerson(this);
        if (dynamic_cast<workPoint *>(objPoint))
            ((workPoint *)(objPoint))->removePerson(this);
    }
}

void Person::update_pers(float deltaTime, float speedGeneral
    , std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints)
{
    updateClockPerson(speedGeneral);
    //If not home move
    if (isBackHome == false && !isWaiting)
        pos += (direction * deltaTime * speed);
    if (pos.x < 0 || pos.y < 0 || pos.x > WIN_WIDTH || pos.y > WIN_HEIGHT)
        computeDir();

    circle->setPosition(pos);
    if (get_dist(pos, objectif) <= 5.f && !isWaiting)
        arrivedAtObjectif(lstInteretPoints);
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

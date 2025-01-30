#pragma once

#include <SFML/Graphics.hpp>
#include "const.hpp"
#include "color.hpp"
#include <math.h>
#include "interetPoint.hpp"
using namespace sf;

enum PersonDisease {
    NOT_SICK,
    SICK,
    RECOVERED,
    IMUNE,
    DEAD,
    LIFE_DEATH
};

enum PersonMovingStatus {
    WORKING,
    MOVING,
    ATHOME,
    WAITING_AT_HOME,
};

class Person {
    public:
        PersonDisease state = NOT_SICK;
        CircleShape *circle;
        float speed;
        int id;
        Vector2f pos;
        Vector2f objectif;
        int dayInfection;

        interetPoint *_home;
        PersonMovingStatus moveStatus;
        int nbVisitsRemaining;
        interetPoint *_obj;
        sf::Clock clock;
        float timeWaiting;
        int lifeTimeRemaining;

        void setHome(interetPoint *home);
        void setNewObj(std::vector<interetPoint *> &lstInteretPoints);
        void setNewObj(interetPoint * point);
        void setNewObj();
        void update_pers(float deltaTime, float speedGeneral,
            std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints);
        Person();
        void setSick();
        void setNewDay();
        void update_color();
    private:
        Vector2f direction;
    
        void statusMoving(float deltaTime, std::vector<interetPoint *> &lstInteretPoints);
        void statusAtHome();
        void statusWaitingAtHome(float speed);
        void statusWorking(float speed);

        float get_dist(Vector2f a, Vector2f b);
        void computeDir();
        void arrivedAtObjectif(std::vector<interetPoint *> &lstInteretPoints);
        void setListType_pers(std::vector<interetPoint*> &lstSrc, std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type);
};
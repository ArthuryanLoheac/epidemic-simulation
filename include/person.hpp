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
    DEAD
};

class Person {
    public:
        CircleShape *circle;
        float speed;
        int id;
        PersonDisease state = NOT_SICK;
        Vector2f pos;
        Vector2f objectif;
        int isGoingWorking;
        bool isBackHome;
        interetPoint *_home;
        int dayInfection;

        void setNewObj();
        void setHome(interetPoint *home);
        void setNewObj(std::vector<interetPoint *> &lstInteretPoints);
        void setNewObj(interetPoint * point);
        void update_pers(float deltaTime, std::vector<Person *> lst, std::vector<interetPoint *> &lstInteretPoints);
        Person();
        void setSick();
        void update_color();
    private:
        Vector2f direction;
    
        float get_dist(Vector2f a, Vector2f b);
        void check_infected(std::vector<Person *> lst);
        void arrivedAtObjectif(std::vector<interetPoint *> &lstInteretPoints);
        void setListType_pers(std::vector<interetPoint*> &lstSrc, std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type);
};
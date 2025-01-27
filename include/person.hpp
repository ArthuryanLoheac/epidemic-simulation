#pragma once

#include <SFML/Graphics.hpp>
#include "const.hpp"
#include "color.hpp"
#include <math.h>
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

        void setNewObj();
        void update_pers(float deltaTime, std::vector<Person *> lst);

    private:
        Clock timeInfection;
        Vector2f direction;
    
        float get_dist(Vector2f a, Vector2f b);
        void check_disease_time();
        void set_color();
        void check_infected(std::vector<Person *> lst);
};
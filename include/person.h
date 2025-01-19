
#ifndef PERSON_H
#define PERSON_H

    #include <SFML/Graphics.hpp>
    #include "const.h"
    #include <math.h>
    using namespace sf;

    enum PersonDisease {
        NOT_SICK,
        SICK,
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

            void setNewObj() {
                objectif = Vector2f(rand() % (WIN_WIDTH-RADIUS_CIRCLE) + RADIUS_CIRCLE/2,
                                    rand() % (WIN_HEIGHT-RADIUS_CIRCLE) + RADIUS_CIRCLE/2);
                direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist(pos, objectif);
            }

            void update_pers(float deltaTime, Person** lst)
            {
                check_disease_time();
                pos += (direction * deltaTime * speed);
                circle->setPosition(pos);
                if (get_dist(pos, objectif) <= 10.f)
                   setNewObj();
                check_infected(lst);
                set_color();
            }

        private:
            Clock timeInfection;
            Vector2f direction;
        
            float get_dist(Vector2f a, Vector2f b)
            {
                return sqrt(pow((a.x - b.x), 2) + pow((b.y - a.y), 2));
            }

            void check_disease_time()
            {
                if (state == SICK && timeInfection.getElapsedTime() >= seconds(TIME_SICK)) {
                    if (rand() % ONE_OF_X_DEAD) {
                        state = IMUNE;
                    } else {    
                        state = DEAD;
                    }
                }
            }

            void set_color()
            {
                if (state == NOT_SICK) {
                    circle->setFillColor(BEIGE);
                } else if (state == SICK) {
                    circle->setFillColor(RED);
                } else if (state == IMUNE) {
                    circle->setFillColor(LIGHT_BLUE);
                } else {
                    circle->setFillColor(Color::Black);
                }
            }

            void check_infected(Person** lst)
            {
                int i = 0;

                while(lst[i]) {
                    if (i != id && get_dist(pos, lst[i]->pos) < RADIUS_INFECTION
                        && lst[i]->state == SICK && state == NOT_SICK)
                    {
                        state = SICK;
                        timeInfection.restart();
                    }
                    i++;
                }
            }
    };
#endif

#ifndef PERSON_H
#define PERSON_H

    #include <SFML/Graphics.hpp>
    #include <math.h>
    #include "const.h"
    using namespace sf;

    class Person {
        public:
            CircleShape *circle;
            float speed;
            Vector2f direction;
            Vector2f pos;
            Vector2f objectif;

            void setNewObj() {
                objectif = Vector2f(rand() % (WIN_WIDTH-RADIUS_CIRCLE) + RADIUS_CIRCLE/2,
                                    rand() % (WIN_HEIGHT-RADIUS_CIRCLE) + RADIUS_CIRCLE/2);
                direction = Vector2f((objectif.x - pos.x), (objectif.y - pos.y)) / get_dist();
            }

            float get_dist()
            {
                return sqrt(pow((pos.x - objectif.x), 2) + pow((objectif.y - pos.y), 2));
            }

            void update_pers(float deltaTime)
            {
                pos.x += (direction.x * deltaTime * speed);
                pos.y += (direction.y * deltaTime * speed);
                circle->setPosition(pos);
                if (get_dist() <= 10.f) {
                   setNewObj();
                }
            }
    };
#endif
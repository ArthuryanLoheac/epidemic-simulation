
#ifndef SIM_H
#define SIM_H

    #include <SFML/Graphics.hpp>
    #include "person.h"
    #include "const.h"

    struct window_game {
        RenderWindow* window;
        Clock* clock;
        float deltaTime;
    };

    void draw(RenderWindow *window, Person** lst);
    void compute_event(Event event, RenderWindow *window);
    window_game* create_window_game();
    void update(Person** heros, window_game* game);
    Person** create_lst_person();
#endif
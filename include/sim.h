
#ifndef SIM_H
#define SIM_H

    #include <SFML/Graphics.hpp>
    #include "person.h"
    #include "const.h"
    #include "color.h"
    #include <string>

    struct stats_game {
        int nb_imune;
        Text* txt_imune;
        int nb_death;
        Text* txt_death;
        int nb_sick;
        Text* txt_sick;
        int nb_not_sick;
        Text* txt_not_sick;
        int nb_alives;
        Text* txt_alives;
        int nb_recovered;
        Text* txt_recovered;
    };

    struct window_game {
        RenderWindow* window;
        Clock* clock;
        float deltaTime;
        stats_game* stats;
        Font* font;
    };

    void draw(window_game *game, Person** lst);
    void compute_event(Event event, RenderWindow *window, Person*** lst);
    window_game* create_window_game();
    void update(Person** heros, window_game* game);
    Person** create_lst_person();
#endif
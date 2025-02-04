
#ifndef SIM_H
#define SIM_H

    #include <SFML/Graphics.hpp>
    #include "person.hpp"
    #include "const.hpp"
    #include "color.hpp"
    #include "interetPoint.hpp"
    #include "housePoint.hpp"
    #include "workPoint.hpp"
    #include <string>
    #include <vector>
    #include <deque>

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
        int Days;
        Text* txt_days;
        float speed;
        Text* txt_speed;

        std::deque<float> percentSick;
        std::deque<float> percentImune;
        std::deque<float> percentRecovered;
        std::deque<float> percentDead;
    };

    void draw(window_game *game, std::vector<Person *> lst,
        std::vector<interetPoint *> lstPoints);
    void compute_event(Event event, window_game *game,std::vector<Person *> &heros,
        std::vector<interetPoint *> &lst);
    window_game* create_window_game();
    void update(std::vector<Person *> &heros, window_game* game,
        std::vector<interetPoint *> &lstInteretPoints);
    void create_lst_person(std::vector<Person *> &lst);
    void init(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints, window_game &game);
    void setListType(std::vector<interetPoint*> &lstSrc,
        std::vector<interetPoint*> &lstDest, interetPoint::TypePoint type);
    void createLstInteretPoints(std::vector<interetPoint *> &lst);
    void assignPerson(std::vector<Person *> &heros,
        std::vector<interetPoint *> &lstInteretPoints);
    void update_all_person(std::vector<Person *> &heros, window_game* game,
        std::vector<interetPoint *> &lstInteretPoints);
    void newDay(std::vector<Person *> &heros,
        std::vector<interetPoint *> &lstInteretPoints, window_game* game);
    Person *create_person(int id, bool imune = false, float x = 0.f, float y = 0.f);
    void assignOnePerson(std::vector<interetPoint *> &lstInteretPoints, Person *hero);

#endif
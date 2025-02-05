
#ifndef SIM_H
#define SIM_H

    #include <SFML/Graphics.hpp>
    #include "person.hpp"
    #include "const.hpp"
    #include "color.hpp"
    #include "interetPoint.hpp"
    #include "housePoint.hpp"
    #include "workPoint.hpp"
    #include "button.hpp"
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

    struct datas {
        int _WIN_WIDTH;
        int _WIN_HEIGHT;
        int _RADIUS_CIRCLE;
        int _NB_HOUSE;
        int _HOUSE_SIZE;
        int _NB_WORK_POINT;
        int _MIN_SECONDS_WORKING;
        int _MAX_SECONDS_WORKING;
        int _NB_PLACE_VISIT_A_DAY;
        int _NUMBER_PERSON;
        int _SPEED_MIN;
        int _SPEED_MAX;
        int _NUMBER_INFECTED_START;
        int _TIME_SICK;
        int _PERCENT_DEAD;
        int _PERCENT_RECOVERED;
        int _PERCENT_TRANSMISSION_WORK;
        int _PERCENT_TRANSMISSION_HOME;
        int _LIFE_TIME;
        int _PERCENT_IMUNE_BORN;
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

        datas actual;
        datas next;
        button *nbPeople;

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
    void create_lst_person(std::vector<Person *> &lst, window_game *game);
    void init(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints, window_game *game);
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
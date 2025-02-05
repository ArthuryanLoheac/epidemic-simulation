#include "sim.hpp"

using namespace sf;

static void compute_speed(Event event, window_game *game)
{
    float speedMax = 20;
    float speedMin = 0;
    float diffSpeed = 0.2f;

    if (event.key.code == Keyboard::Right && event.type == sf::Event::KeyPressed) {
        game->speed += diffSpeed;
        if (game->speed > speedMax)
            game->speed = speedMax;
    }
    if (event.key.code == Keyboard::Left && event.type == sf::Event::KeyPressed) {
        game->speed -= diffSpeed;
        if (game->speed < speedMin)
            game->speed = speedMin;
    }
}

void compute_event(Event event, window_game *game, std::vector<Person *> &heros,
    std::vector<interetPoint *> &lst)
{
    if (event.type == Event::Closed) {
        (*game->window).close();
    }
    if (event.key.code == Keyboard::R && event.type == sf::Event::KeyPressed) {
        init(heros, lst, game);
    }
    compute_speed(event, game);
    game->next._NUMBER_PERSON = game->Peoples->update(event, game->next._NUMBER_PERSON);
    game->next._RADIUS_CIRCLE = game->RadiusCircle->update(event, game->next._RADIUS_CIRCLE);
    game->next._NB_HOUSE = game->Houses->update(event, game->next._NB_HOUSE);
    game->next._HOUSE_SIZE = game->HouseSize->update(event, game->next._HOUSE_SIZE);
    game->next._NB_WORK_POINT = game->Works->update(event, game->next._NB_WORK_POINT);
    game->next._MIN_SECONDS_WORKING = game->MinSecondsWork->update(event, game->next._MIN_SECONDS_WORKING);
    game->next._MAX_SECONDS_WORKING = game->MaxSecondsWork->update(event, game->next._MAX_SECONDS_WORKING);
    game->next._NB_PLACE_VISIT_A_DAY = game->PlaceVisited->update(event, game->next._NB_PLACE_VISIT_A_DAY);
    game->next._NUMBER_INFECTED_START = game->NbInfectedStart->update(event, game->next._NUMBER_INFECTED_START);
    game->next._TIME_SICK = game->DaySick->update(event, game->next._TIME_SICK);
    game->next._PERCENT_DEAD = game->PercentDead->update(event, game->next._PERCENT_DEAD);
    game->next._PERCENT_RECOVERED = game->PercentRecovered->update(event, game->next._PERCENT_RECOVERED);
    game->next._PERCENT_TRANSMISSION_WORK = game->PercentTransmissionWork->update(event, game->next._PERCENT_TRANSMISSION_WORK);
    game->next._PERCENT_TRANSMISSION_HOME = game->PercentTransmissionHome->update(event, game->next._PERCENT_TRANSMISSION_HOME);
    game->next._LIFE_TIME = game->DayLifeTime->update(event, game->next._LIFE_TIME);
    game->next._PERCENT_IMUNE_BORN = game->PercentImuneBorn->update(event, game->next._PERCENT_IMUNE_BORN);

}
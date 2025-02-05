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
    if (game->nbPeoplePlus->update(event))
        game->next._NUMBER_PERSON += 10;
    if (game->nbPeopleMinus->update(event)) {
        game->next._NUMBER_PERSON -= 10;
        if (game->next._NUMBER_PERSON < 0)
            game->next._NUMBER_PERSON = 0;
    }
}
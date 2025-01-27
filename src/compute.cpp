#include "sim.hpp"

using namespace sf;

void compute_event(Event event, window_game *game, std::vector<Person *> &heros,
    std::vector<interetPoint *> &lst)
{
    if (event.type == Event::Closed) {
        (*game->window).close();
    }
    if (event.key.code == Keyboard::R && event.type == sf::Event::KeyPressed) {
        init(heros, lst);
    }
    if (event.key.code == Keyboard::Right && event.type == sf::Event::KeyPressed) {
        game->speed += 0.2f;
        if (game->speed > 5)
            game->speed = 5;
    }
    if (event.key.code == Keyboard::Left && event.type == sf::Event::KeyPressed) {
        game->speed -= 0.2f;
        if (game->speed < 0)
            game->speed = 0;
    }
}
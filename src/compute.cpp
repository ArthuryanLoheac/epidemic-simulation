#include "sim.hpp"

using namespace sf;

void compute_event(Event event, RenderWindow *window, std::vector<Person *> &heros,
    std::vector<interetPoint *> &lst)
{
    if (event.type == Event::Closed) {
        (*window).close();
    }
    if (event.key.code == Keyboard::R && event.type == sf::Event::KeyPressed)
    {
        init(heros, lst);
    }
}
#include "sim.hpp"

using namespace sf;

void compute_event(Event event, RenderWindow *window, std::vector<Person *> lst)
{
    if (event.type == Event::Closed) {
        (*window).close();
    }
    if (event.key.code == Keyboard::R && event.type == sf::Event::KeyPressed)
    {
        create_lst_person(lst);
    }
}
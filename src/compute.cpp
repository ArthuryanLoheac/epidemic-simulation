#include "sim.h"

using namespace sf;

void compute_event(Event event, RenderWindow *window, Person*** lst)
{
    if (event.type == Event::Closed) {
        (*window).close();
    }
    if (event.key.code == Keyboard::R && event.type == sf::Event::KeyPressed)
    {
        *lst = create_lst_person();
    }
}
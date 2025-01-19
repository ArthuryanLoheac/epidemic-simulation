#include "sim.h"

void draw_circles(RenderWindow *window, Person** lst)
{
    int i = 0;

    while(lst[i])
    {
        window->draw(*(lst[i]->circle));
        i++;
    }
}

void draw(RenderWindow *window, Person** lst)
{
    window->clear(DARK_BLUE);

    draw_circles(window, lst);

    window->display();
}
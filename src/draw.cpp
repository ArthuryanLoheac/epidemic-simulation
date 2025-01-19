#include "sim.h"

void draw_circles_dead(RenderWindow *window, Person** lst)
{
    int i = 0;

    while(lst[i])
    {
        if (lst[i]->state == DEAD)
            window->draw(*(lst[i]->circle));
        i++;
    }
}
void draw_circles_other(RenderWindow *window, Person** lst)
{
    int i = 0;

    while(lst[i])
    {
        if (lst[i]->state != DEAD)
            window->draw(*(lst[i]->circle));
        i++;
    }
}

void draw(RenderWindow *window, Person** lst)
{
    window->clear(DARK_BLUE);

    draw_circles_dead(window, lst);
    draw_circles_other(window, lst);

    window->display();
}
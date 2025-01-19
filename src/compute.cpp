#include "sim.h"

using namespace sf;

void compute_event(Event event, RenderWindow *window)
{
    if (event.type == Event::Closed) {
        (*window).close();
    }
}
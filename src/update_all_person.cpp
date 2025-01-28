#include "sim.hpp"
using namespace sf;
using namespace std;

void update_all_person(std::vector<Person *> &heros, window_game* game,
    std::vector<interetPoint *> &lstInteretPoints)
{
    int i = 0;
    for (int i = 0; i < heros.size(); i++)
    {
        if (heros[i]->state != DEAD)
            heros[i]->update_pers(game->deltaTime, heros, lstInteretPoints);
    }
}
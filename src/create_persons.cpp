#include "sim.hpp"

using namespace sf;
using namespace std;

Person *create_person(int id, int radius, int NB_PLACE_VISIT, int LIFE_TIM, bool imune, float x, float y)
{
    return new Person(x, y, id, radius, NB_PLACE_VISIT, LIFE_TIM, imune);
}

void create_lst_person(vector<Person *> &lst, window_game *game)
{
    lst.clear();
    for (int i = 0; i < game->actual._NUMBER_PERSON; i++)
        lst.push_back(create_person(i, game->actual._RADIUS_CIRCLE, game->actual._NB_PLACE_VISIT_A_DAY,
            game->actual._LIFE_TIME));
    for (int i = 0; i < min(NUMBER_INFECTED_START, game->actual._NUMBER_PERSON); i++)
        lst[i]->setSick(); 
}

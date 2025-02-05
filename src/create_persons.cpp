#include "sim.hpp"

using namespace sf;
using namespace std;

Person *create_person(int id, bool imune, float x, float y)
{
    return new Person(x, y, id, imune);
}

void create_lst_person(vector<Person *> &lst, window_game *game)
{
    lst.clear();
    for (int i = 0; i < game->actual._NUMBER_PERSON; i++)
        lst.push_back(create_person(i));
    for (int i = 0; i < min(NUMBER_INFECTED_START, game->actual._NUMBER_PERSON); i++)
        lst[i]->setSick(); 
}

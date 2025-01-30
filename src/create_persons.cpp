#include "sim.hpp"

using namespace sf;
using namespace std;

Person *create_person(int id, float x, float y)
{
    return new Person(x, y, id);
}

void create_lst_person(vector<Person *> &lst)
{
    lst.clear();
    for (int i = 0; i < NUMBER_PERSON; i++) {
        lst.push_back(create_person(i));
    }
    for (int i = 0; i < min(NUMBER_INFECTED_START, NUMBER_PERSON); i++)
        lst[i]->setSick();
}

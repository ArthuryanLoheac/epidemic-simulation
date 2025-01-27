#include "sim.hpp"

using namespace sf;

void createLstInteretPoints(std::vector<interetPoint *> &lst)
{
    for (int i = 0; i < NB_HOUSE; i++) {
        lst.push_back(new housePoint(
            rand() % (WIN_WIDTH - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            rand() % (WIN_HEIGHT - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            HOUSE_SIZE, HOUSE_SIZE));
    }
}

void assignPerson(std::vector<Person *> &heros, std::vector<interetPoint *> &lstInteretPoints)
{
    int id = 0;
    housePoint *house;

    for (int i = 0; i < heros.size(); i++) {
        id = rand() % lstInteretPoints.size();
        if (lstInteretPoints[id]->getType() == interetPoint::HOUSE){
            house = ((housePoint *)(lstInteretPoints[id]));
            house->addHabitant(heros[i]);
            heros[i]->pos = house->getPos() + sf::Vector2f((rand() % HOUSE_SIZE) - (HOUSE_SIZE/2), (rand() % HOUSE_SIZE) - (HOUSE_SIZE/2));
            heros[i]->setNewObj(lstInteretPoints);
        }
    }
}

int main()
{
    window_game* game = create_window_game();
    std::vector<Person *> heros;
    create_lst_person(heros);

    std::vector<interetPoint *> lstInteretPoints;
    createLstInteretPoints(lstInteretPoints);

    assignPerson(heros, lstInteretPoints);

    while (game->window->isOpen())
    {
        Event event;
        while (game->window->pollEvent(event)) {
            compute_event(event, game->window, heros);
        }
        update(heros, game, lstInteretPoints);
        draw(game, heros, lstInteretPoints);
    }
    delete game;
    return 0;
}

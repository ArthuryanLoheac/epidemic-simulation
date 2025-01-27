#include "sim.hpp"

using namespace sf;

void createLstInteretPoints(std::vector<interetPoint *> &lst)
{
    for (int i = 0; i < 5; i++) {
        lst.push_back(new housePoint(
            rand() % (WIN_WIDTH - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            rand() % (WIN_HEIGHT - (HOUSE_SIZE + HOUSE_SIZE/2)) + (HOUSE_SIZE / 2),
            HOUSE_SIZE, HOUSE_SIZE));
    }
}

int main()
{
    window_game* game = create_window_game();
    std::vector<Person *> heros;
    create_lst_person(heros);
    
    std::vector<interetPoint *> lstInteretPoints;
    createLstInteretPoints(lstInteretPoints);

    while (game->window->isOpen())
    {
        Event event;
        while (game->window->pollEvent(event)) {
            compute_event(event, game->window, heros);
        }
        update(heros, game);
        draw(game, heros, lstInteretPoints);
    }
    delete game;
    return 0;
}

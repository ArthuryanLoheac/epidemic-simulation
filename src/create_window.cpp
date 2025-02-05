#include "sim.hpp"

using namespace sf;
using namespace std;

static RenderWindow* create_window()
{
    RenderWindow *window = new RenderWindow(
        VideoMode(WIN_WIDTH, WIN_HEIGHT), "Simulation");

    window->setVerticalSyncEnabled(true);
    return window;
}

static Text* create_text(String txt, Font* fnt, int i, Color c)
{
    Text* text = new Text();

    text->setFont(*fnt);
    text->setString(txt);
    text->setCharacterSize(20);
    text->setFillColor(c);
    text->setStyle(Text::Bold);
    text->setPosition(0, i*24);
    return text;
}

static stats_game* create_stats(Font* fnt)
{
    stats_game *stats = new stats_game();

    stats->nb_imune = 0;
    stats->nb_death = 0;
    stats->nb_sick = 0;
    stats->nb_not_sick = 0;
    stats->nb_alives = 0;
    stats->nb_recovered = 0;
    stats->txt_imune = create_text("Imunes : ",fnt, 3, IMUNE_COLOR);
    stats->txt_recovered = create_text("Recovered : ",fnt, 1, RECOVERED_COLOR);
    stats->txt_alives = create_text("Alives : ",fnt, 5, Color::White);
    stats->txt_death = create_text("Dead : ",fnt, 4, Color::White);
    stats->txt_sick = create_text("Sick : ",fnt, 2, SICK_COLOR);
    stats->txt_not_sick = create_text("Not Sick : ",fnt, 0, NOT_SICK_COLOR);
    return stats;
}

window_game* create_window_game()
{
    srand((unsigned)time(0));
    window_game *game = new window_game();
    sf::Font *f = new sf::Font;
    f->loadFromFile("font/Oswald-Bold.ttf");

    game->Peoples = new Slideur("Nb People", 10, 1);
    game->RadiusCircle = new Slideur("Radius Cirle", 1, 2);
    game->Houses = new Slideur("Nb House", 10, 3);
    game->HouseSize = new Slideur("House Size", 1, 4);
    game->Works = new Slideur("Nb Works", 10, 5);
    game->MinSecondsWork = new Slideur("Min Sec Work", 1, 6);
    game->MaxSecondsWork = new Slideur("Max Sec Work", 1, 7);
    game->PlaceVisited = new Slideur("Place visit/day", 1, 8);
    game->NbInfectedStart = new Slideur("Nb Infected Start", 1, 9);
    game->DaySick = new Slideur("Day sick", 1, 10);
    game->PercentDead = new Slideur("% Deads", 1, 11);
    game->PercentRecovered = new Slideur("% Recover", 1, 12);
    game->PercentTransmissionWork = new Slideur("% Transmission Work", 1, 13);
    game->PercentTransmissionHome = new Slideur("% Transmission Home", 1, 14);
    game->DayLifeTime = new Slideur("Life time (days)", 1, 15);
    game->PercentImuneBorn = new Slideur("% Imune born", 1, 16);

    game->window = create_window();
    game->clock = new Clock();
    game->font = new Font();
    game->font->loadFromFile("font/Oswald-Bold.ttf");
    game->stats = create_stats(game->font);
    game->speed = 1;
    game->Days = 1;
    game->txt_speed = create_text("Speed : x1",game->font, (WIN_HEIGHT / 24) - 1, sf::Color::White);
    game->txt_days = create_text("Days : 1",game->font, (WIN_HEIGHT / 24) - 2, sf::Color::White);

    game->actual._NUMBER_PERSON = NUMBER_PERSON;
    game->actual._RADIUS_CIRCLE = RADIUS_CIRCLE;
    game->actual._NB_HOUSE = NB_HOUSE;
    game->actual._HOUSE_SIZE = HOUSE_SIZE;
    game->actual._NB_WORK_POINT = NB_WORK_POINT;
    game->actual._MIN_SECONDS_WORKING = MIN_SECONDS_WORKING;
    game->actual._MAX_SECONDS_WORKING = MAX_SECONDS_WORKING;
    game->actual._NB_PLACE_VISIT_A_DAY = NB_PLACE_VISIT_A_DAY;
    game->actual._NUMBER_INFECTED_START = NUMBER_INFECTED_START;
    game->actual._TIME_SICK = TIME_SICK;
    game->actual._PERCENT_DEAD = PERCENT_DEAD;
    game->actual._PERCENT_RECOVERED = PERCENT_RECOVERED;
    game->actual._PERCENT_TRANSMISSION_WORK = PERCENT_TRANSMISSION_WORK;
    game->actual._PERCENT_TRANSMISSION_HOME = PERCENT_TRANSMISSION_HOME;
    game->actual._LIFE_TIME = LIFE_TIME;
    game->actual._PERCENT_IMUNE_BORN = PERCENT_IMUNE_BORN;
    game->next = game->actual;
    return game;
}
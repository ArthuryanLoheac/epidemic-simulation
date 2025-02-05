/*
** EPITECH PROJECT, 2025
** MaladieSimulation
** File description:
** slideur
*/

#pragma once
#include "sim.hpp"

class Slideur
{
    private:
        button *nbPeoplePlus;
        sf::Text *txtPeople;
        sf::Text *nbPeople;
        button *nbPeopleMinus;
        int slideVal;
    public:
        Slideur(std::string str, int sVal);
        void setValue(int value);
        void draw(RenderWindow *window);
        int update(sf::Event event, int value);
};


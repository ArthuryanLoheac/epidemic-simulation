#ifndef CONST_H
    #define CONST_H

    #include <SFML/Graphics.hpp>
    using namespace sf;

    const int WIN_WIDTH = 1080;
    const int WIN_HEIGHT = 720;

    const int RADIUS_CIRCLE = 10;
    const int RADIUS_INFECTION = 20;

    const int NUMBER_PERSON = 200;
    const int SPEED_MIN = 30;
    const int SPEED_MAX = 50;

    const int NUMBER_INFECTED_START = 2;
    const int PERCENT_CHANCE_DEAD = 1;
    const int PERCENT_CHANCE_IMUNE = 5;
    const int PERCENT_CHANCE_NOT_SICK = 10;

    const Color DARK_BLUE = Color(41, 40, 49);
    const Color BLUE = Color(51, 63, 88);
    const Color LIGHT_BLUE = Color(74, 122, 150);
    const Color RED = Color(255, 134, 149);
    const Color BEIGE = Color(201, 187, 173);

#endif

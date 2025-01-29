#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class interetPoint
{
    public:
        enum TypePoint {
            NORMAL,
            HOUSE,
            WORK,
        };
    protected:
        sf::Vector2f _pos;
        sf::Vector2f _size;
        sf::RectangleShape _rect;
        interetPoint::TypePoint _type;
        sf::Clock clock;
    public:
        interetPoint(size_t x, size_t y, size_t sizeX, size_t sizeY);
        ~interetPoint();
        interetPoint::TypePoint getType(void);
        sf::Vector2f getPos(void);
        void draw(sf::RenderWindow *window);
        virtual void update(float speed);
};

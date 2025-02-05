#include <SFML/Graphics.hpp>
#include <iostream>

class button
{
    private:
        sf::Texture Texture;
        sf::Sprite Sprite;
        sf::Vector2f pos;
        sf::Vector2i size;
    public:
        button(std::string path);
        button(std::string path, int x, int y);
        void draw(sf::RenderWindow *window);
        bool update(sf::Event event);
        void setPosition(int x, int y);
};

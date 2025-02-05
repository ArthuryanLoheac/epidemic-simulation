#include "button.hpp"

button::button(std::string path)
{
    Texture.loadFromFile(path);
    Texture.setSmooth(true);
    Sprite.setTexture(Texture);
    size.x = Sprite.getGlobalBounds().width;
    size.y = Sprite.getGlobalBounds().height;
}

button::button(std::string path, int x, int y)
{
    Texture.loadFromFile(path);
    Texture.setSmooth(true);
    Sprite.setTexture(Texture);
    Sprite.setScale(x / Sprite.getGlobalBounds().width,
        y / Sprite.getGlobalBounds().height);
    size.x = x;
    size.y = y;
    Sprite.setOrigin(size.x / 2, size.y / 2);
}

void button::draw(sf::RenderWindow *window)
{
    window->draw(Sprite);
}

bool button::update(sf::Event event)
{
    if (event.type != sf::Event::MouseButtonReleased
        || event.mouseButton.button != sf::Mouse::Left)
        return false;
    return Sprite.getGlobalBounds()
        .contains(event.mouseButton.x, event.mouseButton.y);
}

void button::setPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
    Sprite.setPosition(x, y);
}

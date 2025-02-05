#include "slideur.hpp"

static Text* create_text_right(String txt, Font* fnt, float i, Color c, int size)
{
    Text* text = new Text();

    text->setFont(*fnt);
    text->setString(txt);
    text->setCharacterSize(size);
    text->setFillColor(c);
    text->setStyle(Text::Bold);
    text->setPosition(WIN_WIDTH-150, i*24);
    return text;
}

Slideur::Slideur(std::string str, int sVal)
{
    sf::Font *f = new sf::Font;
    f->loadFromFile("font/Oswald-Bold.ttf");
    slideVal = sVal;

    nbPeoplePlus = new button("assets/plus.png", 30, 30);
    nbPeoplePlus->setPosition(WIN_WIDTH-25, 35);
    txtPeople = create_text_right(str, f, 1.5f, sf::Color::White, 16);
    nbPeople = create_text_right("0000", f, 0.6f, sf::Color::White, 20);
    nbPeopleMinus = new button("assets/minus.png", 25, 25);
    nbPeopleMinus->setPosition(WIN_WIDTH-175, 35);
}

void Slideur::setValue(int value)
{
    nbPeople->setString(std::to_string(value));
}

void Slideur::draw(RenderWindow *window)
{
    nbPeoplePlus->draw(window);
    nbPeopleMinus->draw(window);
    window->draw(*txtPeople);
    window->draw(*nbPeople);
}

int Slideur::update(sf::Event event, int value)
{
    if (nbPeoplePlus->update(event))
        return value + slideVal;
    if (nbPeopleMinus->update(event)) {
        if (value < slideVal)
            return 0;
        return value - slideVal;
    }
    return value;
}
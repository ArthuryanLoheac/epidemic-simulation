#include "slideur.hpp"

static Text* create_text_right(String txt, Font* fnt, float i, Color c, int size, bool b = false)
{
    Text* text = new Text();

    text->setFont(*fnt);
    text->setString(txt);
    text->setCharacterSize(size);
    text->setFillColor(c);
    text->setStyle(Text::Bold);
    if (b)
        text->setPosition(WIN_WIDTH-180, i*20 - 5);
    else
        text->setPosition(WIN_WIDTH-150, i*20 - 5);
    return text;
}

Slideur::Slideur(std::string str, int sVal, int i)
{
    sf::Font *f = new sf::Font;
    f->loadFromFile("font/Oswald-Bold.ttf");
    slideVal = sVal;

    nbPeoplePlus = new button("assets/plus.png", 20, 20);
    nbPeoplePlus->setPosition(WIN_WIDTH-15, (i *30));
    txtPeople = create_text_right(str, f, (i * 1.5f), sf::Color::White, 12);
    nbPeople = create_text_right("0000", f, (i * 1.5f), sf::Color::White, 14, true);
    nbPeopleMinus = new button("assets/minus.png", 15, 15);
    nbPeopleMinus->setPosition(WIN_WIDTH-195, (i *30));
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
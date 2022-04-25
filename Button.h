/**
 * @author Vinícius de Oliveira Guimarães
 * Programa : Cabeçalho da classe Button. Para ser utilizado na tela, com texto no centro.
 */

#ifndef BUTTON_H
#define BUTTON_H

using namespace std;
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
    public:
        Button();
        Button(string text, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor);
        ~Button();
        void setFont(sf::Font &fonte);
        void setText(string text);
        float getWidth() const;
        void setDefaultBackgroundColor(sf::Color cor);
        void setBackgroundColor(sf::Color cor);
        void setTextColor(sf::Color cor);
/*         void toggleInvisible();
 */        string getText() const;
        void setPosition(sf::Vector2f pos, bool botaoEnd);
        void drawTo(sf::RenderWindow &window);
        bool isMouseOver(sf::RenderWindow &window);
        void setActive(bool act);
        void toggle();
    private:
        sf::RectangleShape button;
        sf::Text text;
        sf::Color bgColor;
        sf::Color defaultBgColor;
        bool active;
        bool invisible;
};

#endif
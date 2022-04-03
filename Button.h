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
        void setDefaultBackgroundColor(sf::Color cor);
        void setBackgroundColor(sf::Color cor);
        void setTextColor(sf::Color cor);
        void setPosition(sf::Vector2f pos);
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
};
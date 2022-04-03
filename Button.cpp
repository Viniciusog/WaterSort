#include "Button.h"
#include "string"
using namespace std;
#include <iostream>

Button::Button() {
    this->active = false;
}

Button::~Button() {

}


Button::Button(string text, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
    this->text.setString(text);
    this->text.setColor(textColor);
    this->text.setCharacterSize(charSize);
    this->button.setSize(size);
    this->button.setFillColor(bgColor);
    this->bgColor = bgColor;
    this->active = false;
}

void Button::setFont(sf::Font &font) {
    this->text.setFont(font);
}

void Button::setBackgroundColor(sf::Color color) {
    this->bgColor = color;
    this->button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
    this->text.setColor(color);
}

void Button::setText(string text) {
    this->text.setString(text);
}

void Button::setPosition(sf::Vector2f pos) {
    this->button.setPosition(pos);

    //Posições x e y do texto
    float xPos = pos.x + this->button.getLocalBounds().width / 2 - this->text.getLocalBounds().width / 2;
    float yPos = pos.y + this->button.getLocalBounds().height / 2 - this->text.getLocalBounds().height / 2;

    this->text.setPosition({xPos, yPos});
}

void Button::drawTo(sf::RenderWindow &window) {
    if(active) {
        this->button.setFillColor(sf::Color::Green);
    } else {
        this->button.setFillColor(this->bgColor);
    }
    window.draw(button);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnX = this->button.getPosition().x;
    float btnY = this->button.getPosition().y;

    if (mouseX > btnX && mouseX < (btnX + this->button.getLocalBounds().width)
        && mouseY > btnY && mouseY < (btnY + this->button.getLocalBounds().width)) {
            cout << "clique no botão" << endl;
        return true;
    }

    cout << "clique fora do botão" << endl;

    return false;
}

void Button::setActive(bool act) {
    this->active = act;
}

void Button::toggle() {
    this->active = !this->active;
}

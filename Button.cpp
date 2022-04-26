/**
 * @author Vinícius de Oliveira Guimarães
 * Programa : Implementação da classe Button. Para ser utilizado na tela, com texto no centro.
 */
#include "Button.h"
#include "string"
#include <iostream>

using namespace std;

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
    this->defaultBgColor = bgColor;
    this->active = false;
}

void Button::setFont(sf::Font &font) {
    this->text.setFont(font);
}

void Button::setDefaultBackgroundColor(sf::Color color) {
    this->defaultBgColor = color;
}

void Button::setBackgroundColor(sf::Color color) {
    this->bgColor = color;
}

void Button::setTextColor(sf::Color color) {
    this->text.setColor(color);
}

void Button::setText(string text) {
    this->text.setString(text);
}

//Configura a posição das coordenadas do botão e também do texto no centro do botão
void Button::setPosition(sf::Vector2f pos, bool botaoEnd) {
    this->button.setPosition(pos);

    //Posições x e y do texto
    float xPos;
    if (botaoEnd == false) {
        xPos = pos.x + this->button.getLocalBounds().width / 2 - this->text.getLocalBounds().width / 2;
    } else {
        xPos = pos.x;
    }
    float yPos = pos.y + this->button.getLocalBounds().height / 2 - this->text.getLocalBounds().height / 2;

    this->text.setPosition({xPos, yPos});
}

//Desenha o botão dentro de uma tela recebida como parâmetro
void Button::drawTo(sf::RenderWindow &window) {
    if(active) {
        this->button.setFillColor(this->bgColor);
    } else {
        this->button.setFillColor(this->defaultBgColor);
    }
    window.draw(button);
    window.draw(text);
}

//Verifica se o mouse está em cima do botão
bool Button::isMouseOver(sf::RenderWindow &window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnX = this->button.getPosition().x;
    float btnY = this->button.getPosition().y;

    if (mouseX > btnX && mouseX < (btnX + this->button.getLocalBounds().width)
        && mouseY > btnY && mouseY < (btnY + this->button.getLocalBounds().width)) {
        return true;
    }

    return false;
}

float Button::getWidth() const {
    return this->button.getSize().x;
}

void Button::setActive(bool act) {
    this->active = act;
}

void Button::toggle() {
    this->active = !this->active;
}

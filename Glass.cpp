#include "Glass.h"
using namespace std;

Glass::Glass() {

}

Glass::~Glass() {

}

/* void Glass::drawTo(int number, sf::RenderWindow &window) {

    sf::RectangleShape line53(sf::Vector2f(1.f, 220.f));
    line53.setPosition(500.f,530.f);
    sf::RectangleShape line52(sf::Vector2f(52.f, 1.f));
    line52.setPosition(449.f,750.f);
    sf::RectangleShape line51(sf::Vector2f(1.f, 220.f));
    line51.setPosition(449.f,530.f);

    sf::RectangleShape shape54(sf::Vector2f(50.f, 50.f));
    shape54.setFillColor(sf::Color::Black );
    shape54.setPosition(450.f,550.f);

    sf::RectangleShape shape53(sf::Vector2f(50.f, 50.f));
    shape53.setFillColor(sf::Color::Black);
    shape53.setPosition(450.f,600.f);

    sf::RectangleShape shape52(sf::Vector2f(50.f, 50.f));
    shape52.setFillColor(sf::Color::Black);
    shape52.setPosition(450.f,650.f);

    sf::RectangleShape shape51(sf::Vector2f(50.f, 50.f));
    shape51.setFillColor(sf::Color::Black);
    shape51.setPosition(450.f,700.f);

} */

void Glass::setColor(int index, sf::Color color) {
    this->colors[index] = color;
}
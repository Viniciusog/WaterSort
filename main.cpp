#include <SFML/Graphics.hpp>
#include "jogo.h"
#include <iostream>
using namespace std;
#include "Button.h"
#include <string>

void increment(int &qtd) {
    qtd++;
    cout << "QTD: " << qtd << endl;
}
//alguma coisa
int main()
{
    jogo objJogo;
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    sf::Font font;
    font.loadFromFile("Roboto-Medium.ttf");

    Button* buttons[5];
    Glass* potes[5];

    Glass g0;
    Glass g1;
    Glass g2;
    Glass g3;
    Glass g4;

    potes[0] = &g0;
    potes[1] = &g1;
    potes[2] = &g2;
    potes[3] = &g3;
    potes[4] = &g4;

    objJogo.atualizaMatrizCores();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            potes[i]->setColor(j, objJogo.getCorMatriz(i, j));
        }
    }

    Button b0("1", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b1("2", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b2("3", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b3("4", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b4("5", {50, 50}, 20, sf::Color::Blue, sf::Color::White);

    b0.setFont(font);
    b1.setFont(font);
    b2.setFont(font);
    b3.setFont(font);
    b4.setFont(font);

    b0.setPosition({10, 10});
    b1.setPosition({70, 10});
    b2.setPosition({130, 10});
    b3.setPosition({190, 10});
    b4.setPosition({250, 10});

    buttons[0] = &b0;
    buttons[1] = &b1;
    buttons[2] = &b2;
    buttons[3] = &b3;
    buttons[4] = &b4;

    objJogo.atualizaMatrizCores();
    

    int from = -1;
    int to = -1;
        
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        for (int i = 0; i < 5; i++) {
                            // Verifica se o mouse clicou em algum botão
                            if (buttons[i]->isMouseOver(window)) {      
                                if(from == -1) {
                                    from = i;
                                } else if(to == -1) {
                                    to = i;
                                    // fazer a mudança de cores
                                    objJogo.conjunto[from].passarLiquido(objJogo.conjunto[to]);
                                    objJogo.atualizaMatrizCores();
                                } else {
                                    buttons[from]->setActive(false);
                                    buttons[to]->setActive(false);
                                    from = i;
                                    to = -1;
                                }
                                buttons[i]->setActive(true);
                            }
                        } 
                        cout << "From: " << from << ", to: " << to << endl;
                    } 
                break;
            }           
        }
   
        for (int i = 0; i < 5; i++) {
            buttons[i]->drawTo(window);
        }

        //primeira pilha
        sf::RectangleShape line13(sf::Vector2f(1.f, 220.f));
        line13.setPosition(100.f,530.f);
        sf::RectangleShape line12(sf::Vector2f(52.f, 1.f));
        line12.setPosition(49.f,750.f);
        sf::RectangleShape line11(sf::Vector2f(1.f, 220.f));
        line11.setPosition(49.f,530.f);

        sf::RectangleShape shape14(sf::Vector2f(50.f, 50.f));
        shape14.setFillColor(objJogo.getCorMatriz(0, 3));
        shape14.setPosition(50.f,550.f);

        sf::RectangleShape shape13(sf::Vector2f(50.f, 50.f));
        shape13.setFillColor(objJogo.getCorMatriz(0, 2));
        shape13.setPosition(50.f,600.f);

        sf::RectangleShape shape12(sf::Vector2f(50.f, 50.f));
        shape12.setFillColor(objJogo.getCorMatriz(0, 1));
        shape12.setPosition(50.f,650.f);

        sf::RectangleShape shape11(sf::Vector2f(50.f, 50.f));
        shape11.setFillColor(objJogo.getCorMatriz(0, 0));
        shape11.setPosition(50.f,700.f);

        //segunda pilha
        sf::RectangleShape line23(sf::Vector2f(1.f, 220.f));
        line23.setPosition(200.f,530.f);
        sf::RectangleShape line22(sf::Vector2f(52.f, 1.f));
        line22.setPosition(149.f,750.f);
        sf::RectangleShape line21(sf::Vector2f(1.f, 220.f));
        line21.setPosition(149.f,530.f);

        sf::RectangleShape shape24(sf::Vector2f(50.f, 50.f));
        shape24.setFillColor(objJogo.getCorMatriz(1, 3));
        shape24.setPosition(150.f,550.f);

        sf::RectangleShape shape23(sf::Vector2f(50.f, 50.f));
        shape23.setFillColor(objJogo.getCorMatriz(1, 2) );
        shape23.setPosition(150.f,600.f);

        sf::RectangleShape shape22(sf::Vector2f(50.f, 50.f));
        shape22.setFillColor(objJogo.getCorMatriz(1, 1));
        shape22.setPosition(150.f,650.f);

        sf::RectangleShape shape21(sf::Vector2f(50.f, 50.f));
        shape21.setFillColor(objJogo.getCorMatriz(1, 0));
        shape21.setPosition(150.f,700.f);

        //terceira pilha
        sf::RectangleShape line33(sf::Vector2f(1.f, 220.f));
        line33.setPosition(300.f,530.f);
        sf::RectangleShape line32(sf::Vector2f(52.f, 1.f));
        line32.setPosition(249.f,750.f);
        sf::RectangleShape line31(sf::Vector2f(1.f, 220.f));
        line31.setPosition(249.f,530.f);

        sf::RectangleShape shape34(sf::Vector2f(50.f, 50.f));
        shape34.setFillColor(objJogo.getCorMatriz(2, 3));
        shape34.setPosition(250.f,550.f);

        sf::RectangleShape shape33(sf::Vector2f(50.f, 50.f));
        shape33.setFillColor(objJogo.getCorMatriz(2, 2));
        shape33.setPosition(250.f,600.f);

        sf::RectangleShape shape32(sf::Vector2f(50.f, 50.f));
        shape32.setFillColor(objJogo.getCorMatriz(2, 1));
        shape32.setPosition(250.f,650.f);

        sf::RectangleShape shape31(sf::Vector2f(50.f, 50.f));
        shape31.setFillColor(objJogo.getCorMatriz(2, 0));
        shape31.setPosition(250.f,700.f);

        //quarta pilha
        sf::RectangleShape line43(sf::Vector2f(1.f, 220.f));
        line43.setPosition(400.f,530.f);
        sf::RectangleShape line42(sf::Vector2f(52.f, 1.f));
        line42.setPosition(349.f,750.f);
        sf::RectangleShape line41(sf::Vector2f(1.f, 220.f));
        line41.setPosition(349.f,530.f);

        sf::RectangleShape shape44(sf::Vector2f(50.f, 50.f));
        shape44.setFillColor(objJogo.getCorMatriz(3, 3));
        shape44.setPosition(350.f,550.f);

        sf::RectangleShape shape43(sf::Vector2f(50.f, 50.f));
        shape43.setFillColor(objJogo.getCorMatriz(3, 2));
        shape43.setPosition(350.f,600.f);

        sf::RectangleShape shape42(sf::Vector2f(50.f, 50.f));
        shape42.setFillColor(objJogo.getCorMatriz(3, 1));
        shape42.setPosition(350.f,650.f);

        sf::RectangleShape shape41(sf::Vector2f(50.f, 50.f));
        shape41.setFillColor(objJogo.getCorMatriz(3, 0));
        shape41.setPosition(350.f,700.f);

        //quinta pilha
        sf::RectangleShape line53(sf::Vector2f(1.f, 220.f));
        line53.setPosition(500.f,530.f);
        sf::RectangleShape line52(sf::Vector2f(52.f, 1.f));
        line52.setPosition(449.f,750.f);
        sf::RectangleShape line51(sf::Vector2f(1.f, 220.f));
        line51.setPosition(449.f,530.f);

        sf::RectangleShape shape54(sf::Vector2f(50.f, 50.f));
        shape54.setFillColor(objJogo.getCorMatriz(4, 3));
        shape54.setPosition(450.f,550.f);

        sf::RectangleShape shape53(sf::Vector2f(50.f, 50.f));
        shape53.setFillColor(objJogo.getCorMatriz(4, 2));
        shape53.setPosition(450.f,600.f);

        sf::RectangleShape shape52(sf::Vector2f(50.f, 50.f));
        shape52.setFillColor(objJogo.getCorMatriz(4, 1));
        shape52.setPosition(450.f,650.f);

        sf::RectangleShape shape51(sf::Vector2f(50.f, 50.f));
        shape51.setFillColor(objJogo.getCorMatriz(4, 0));
        shape51.setPosition(450.f,700.f);

        //j.input();
        //primeira pilha
        window.draw(line11);
        window.draw(line12);
        window.draw(line13);

        window.draw(shape11);
        window.draw(shape12);
        window.draw(shape13);
        window.draw(shape14);

        //segunda pilha
        window.draw(line21);
        window.draw(line22);
        window.draw(line23);

        window.draw(shape21);
        window.draw(shape22);
        window.draw(shape23);
        window.draw(shape24);

        //terceira pilha
        window.draw(line31);
        window.draw(line32);
        window.draw(line33);

        window.draw(shape31);
        window.draw(shape32);
        window.draw(shape33);
        window.draw(shape34);

        //quarta pilha
        window.draw(line41);
        window.draw(line42);
        window.draw(line43);

        window.draw(shape41);
        window.draw(shape42);
        window.draw(shape43);
        window.draw(shape44);

        //quinta pilha
        window.draw(line51);
        window.draw(line52);
        window.draw(line53);

        window.draw(shape51);
        window.draw(shape52);
        window.draw(shape53);
        window.draw(shape54);

        window.display();
        window.clear();
    }

    return 0;
}
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
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Font font;
    font.loadFromFile("ariblk.ttf");

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
    Button botaoFim("Fim, aperte ENTER para reiniciar!", {800, 600}, 40, sf::Color::White, sf::Color::Green);

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

    int ok = 1;
    bool fim = 0;

    int xPilha = 100;
    int yPilha = 300;
    int xPote = xPilha + 1;
    int yPote = yPilha + 20;
    int ladoQuadrado = 40;
        
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
                                    buttons[from]->setBackgroundColor(sf::Color::Green);
                                } else if(to == -1) {
                                    to = i;
                                    // fazer a mudança de cores
                                    buttons[to]->setBackgroundColor(sf::Color::Magenta);
                                    ok = objJogo.conjunto[from].passarLiquido(objJogo.conjunto[to]);
                                    fim = objJogo.fimDoJogo();
                                    cout << "ok? " << ok << endl;
                                    cout << "fim? " << fim << endl;
                                } else {
                                    buttons[from]->setActive(false);
                                    buttons[to]->setActive(false);
                                    from = i;
                                    buttons[from]->setBackgroundColor(sf::Color::Green);
                                    to = -1;
                                }
                                buttons[i]->setActive(true);
                            }
                        } 
                    } 
                break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        fim = false;
                        objJogo.iniciaJogo();
                        buttons[from]->setActive(false);
                        buttons[to]->setActive(false);
                        from = -1;
                        to = -1;
                        cout << "REINICIAR O JOGO" << endl;
                    }
            }           
        }
   
        for (int i = 0; i < 5; i++) {
            buttons[i]->drawTo(window);
        }

        for(int i = 0; i < 5; i++) {
            sf::RectangleShape linha1(sf::Vector2f(1.f, 20 + 4*ladoQuadrado));
            linha1.setPosition(xPilha, yPilha);
            sf::RectangleShape linha2(sf::Vector2f(ladoQuadrado + 2, 1.f));
            linha2.setPosition(xPilha, yPote + 4*ladoQuadrado); 
            sf::RectangleShape linha3(sf::Vector2f(1.f, 20 + 4*ladoQuadrado));
            linha3.setPosition(xPilha + ladoQuadrado + 1, yPilha);
            window.draw(linha1);
            window.draw(linha2);
            window.draw(linha3);
            for (int j = 3; j >= 0; j--) {
                sf::RectangleShape shape1(sf::Vector2f(ladoQuadrado, ladoQuadrado));
                shape1.setFillColor(objJogo.getCorDePote(i, j));
                shape1.setPosition(xPote, yPote);
                window.draw(shape1);
                yPote += ladoQuadrado;
            }
            xPilha += ladoQuadrado + 1 + 100;
            yPote = yPilha + 20;
            xPote = xPilha + 1;
        }
        yPilha = 300;
        xPilha = 100;
        yPote = yPilha + 20;
        xPote = xPilha + 1;

        if (fim) {
            cout << "é o fim" << endl;
            botaoFim.setFont(font);
            botaoFim.setPosition(sf::Vector2f(0, 0));
            botaoFim.drawTo(window);
        }

        window.display();
        window.clear();
    }

    return 0;
}
/**
 * @author Maria Luiza Edwards de M Cordeiro
 * @author Vinícius de Oliveira Guimarães
 * Programa : Desenho de todos os componentes do jogo na tela.
 */

#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include <iostream>
#include "Button.h"
#include <string>

using namespace std;

int main()
{
    int nVidros = 5;
    int nCores = 4;
    Jogo objJogo(nVidros, nCores);
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Water sort!");

    sf::Font font;
    font.loadFromFile("./util/ariblk.ttf");

    //Botões para controlar passagem dos líquidos
    Button* buttons[5];
    Button b0("1", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b1("2", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b2("3", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b3("4", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button b4("5", {50, 50}, 20, sf::Color::Blue, sf::Color::White);
    Button botaoFim("Fim, aperte ENTER para reiniciar!", {800, 600}, 40, sf::Color::Black, sf::Color::Green);

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
    

    // Aqui começa o controle da passagem de líquidos entre os potes
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
                                //Se não tiver doador ainda    
                                if(from == -1) {
                                    from = i;
                                    buttons[from]->setBackgroundColor(sf::Color::Green);
                                } 
                                //Se não tiver receptor ainda
                                else if(to == -1) {
                                    to = i;
                                    // Faz a mudança de cores
                                    buttons[to]->setBackgroundColor(sf::Color(255,127,39));
                                    ok = objJogo.getVidro(from).passarLiquido(objJogo.getVidro(to));
                                    fim = objJogo.fimDoJogo();
                                    cout << "Passagem ok? " << ok << endl;
                                    cout << "Fim do jogo? " << fim << endl;
                                } 
                                //Se a mudança de cores já foi feita
                                else {
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
                    //Controla a inicialização do jogo
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

        //Desenha os 5 potes na tela de forma automática, sem precisar ser manualmente.
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

        //Se for o fim do jogo
        if (fim) {
            cout << "FIM DE JOGO" << endl;
            botaoFim.setFont(font);
            botaoFim.setPosition(sf::Vector2f(0, 0));
            botaoFim.drawTo(window);
        }
        window.display();
        window.clear();
    }
    return 0;
}
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

int main() {
    int fase = 1;
    Jogo objJogo(fase);
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Water sort!");
    sf::Texture textura;
    textura.loadFromFile(objJogo.getBackground());
    sf::Sprite sprite(textura);

    sf::Font font;
    font.loadFromFile("./util/ariblk.ttf");

    // Botoes de potes
    Button* buttons[7];

    sf::Color cor(0,0,128);
    //Botões para controlar passagem dos líquidos
    Button botaoFim("Fim de jogo! Aperte ENTER para continuar!", {1080, 0}, 25, sf::Color::Black, cor);
    botaoFim.setPosition({230, 0}, true);

    for (int i = 0; i < /* objJogo.getNVidros() */ 7; i++) {
        Button * novoBotao = new Button (to_string(i+1), {50, 50}, 20, sf::Color::Blue, sf::Color::White);
        novoBotao->setFont(font);
        buttons[i] = novoBotao;
    }
        
<<<<<<< HEAD

    // Aqui começa o controle da passagem de líquidos entre os potes
    int from = -1;
    int to = -1;

    int ok = 1;

=======
    //Aqui começa o controle da passagem de líquidos entre os potes
    int xCor, yCor, xPote, yPote, alturaVidro, larguraVidro, alturaCor, larguraCor;
>>>>>>> teste
        
    while (window.isOpen())
    {
        sf::Event event;
        

        
        while (window.pollEvent(event))
        {
            cout << "Vidros: " << objJogo.getNVidros() << endl;
            cout << "Cores: " << objJogo.getNCores() << endl;
            cout << "Vidros vazios: " << objJogo.getNVidrosVazios() << endl;
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        for (int i = 0; i < objJogo.getNVidros(); i++) {
                            //Verifica se o mouse clicou em algum botão
                            if (buttons[i]->isMouseOver(window)) {  
                                //Se não tiver doador ainda    
                                if(objJogo.getDoador() == -1) {
                                    objJogo.atualizaDoador(i);
                                    buttons[objJogo.getDoador()]->setBackgroundColor(sf::Color::Green);
                                } 
                                //Se não tiver receptor ainda
                                else if(objJogo.getReceptor() == -1) {
                                    objJogo.atualizaReceptor(i);
                                    // Faz a mudança de cores
                                    buttons[objJogo.getReceptor()]->setBackgroundColor(sf::Color(255,127,39));
                                    objJogo.getVidro(objJogo.getDoador()).passarLiquido(objJogo.getVidro(objJogo.getReceptor()));
                                }
                                //Se a mudança de cores já foi feita
                                else {
                                    buttons[objJogo.getDoador()]->setActive(false);
                                    buttons[objJogo.getReceptor()]->setActive(false);
                                    objJogo.atualizaDoador(i);
                                    buttons[objJogo.getDoador()]->setBackgroundColor(sf::Color::Green);
                                    objJogo.atualizaReceptor(-1);
                                }
                                buttons[i]->setActive(true);
                            }
                        } 
                    } 
                    break;
                case sf::Event::KeyPressed:
                    //Controla a inicialização do jogo
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        fase++;
                        objJogo.iniciaJogo(fase);
                        buttons[objJogo.getDoador()]->setActive(false);
                        buttons[objJogo.getReceptor()]->setActive(false);
                        objJogo.atualizaDoador(-1);
                        objJogo.atualizaReceptor(-1);
                    }  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        objJogo.iniciaJogo(fase);
                        buttons[objJogo.getDoador()]->setActive(false);
                        buttons[objJogo.getReceptor()]->setActive(false);
                        objJogo.atualizaDoador(-1);
                        objJogo.atualizaReceptor(-1);
                    } 
            }           
        }

        /*Desenhando o background*/
        window.draw(sprite);

        /*Desenhando os botoes*/
        for (int i = 0; i < objJogo.getNVidros(); i++) {
            buttons[i]->drawTo(window);
        }

        desenhaVidros(window, objJogo, buttons);

        //Se for o fim do jogo
        if (objJogo.fimDoJogo()) {
            cout << "FIM DE JOGO" << endl;
            /*setando botao do fim*/
            botaoFim.setFont(font);
            botaoFim.drawTo(window);

            /* for (int i = 0; i < objJogo.getNVidros(); i++) {
                buttons[i]->toggleInvisible();
            } */
        }
        window.display();
        window.clear();
    }
    return 0;
}
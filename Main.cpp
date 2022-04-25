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

int main(){
    int fase = 1;
    Jogo objJogo;
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Water sort!");
    sf::Texture textura;
    textura.loadFromFile(objJogo.getBackground());
    sf::Sprite sprite(textura);

    sf::Font font;
    font.loadFromFile("./util/ariblk.ttf");

    //botoes de potes
    Button* buttons[objJogo.getNVidros()];

    //Botões para controlar passagem dos líquidos
    Button botaoFim("Parabens! precione enter para passar para a proxima fase", {40, 30}, 40, sf::Color::Black, sf::Color::Green);


    for(int i = 0; i < objJogo.getNVidros(); i++){
        Button * novoBotao = new Button (to_string(i+1), {50, 50}, 20, sf::Color::Blue, sf::Color::White);
        novoBotao->setFont(font);
        novoBotao->setPosition({(float)10 + 60 * i, 10});
        buttons[i] = novoBotao;
    }
    
    objJogo.atualizaMatrizCores();
    

    // Aqui começa o controle da passagem de líquidos entre os potes
    int from = -1;
    int to = -1;

    int ok = 1;

        
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
                        for (int i = 0; i < objJogo.getNVidros() ; i++) {
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
                                    cout << "Passagem ok? " << ok << endl;
                                    cout << "Fim do jogo? " << objJogo.fimDoJogo() << endl;
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
                        fase++;
                        objJogo.iniciaJogo(fase);
                        buttons[from]->setActive(false);
                        buttons[to]->setActive(false);
                        from = -1;
                        to = -1;
                        cout << "REINICIAR O JOGO" << endl;
                    }
            }           
        }
        /*Desenhando o background*/
        window.draw(sprite);


        /*Desenhando os botoes*/
        for (int i = 0; i < objJogo.getNVidros(); i++) {
            buttons[i]->drawTo(window);
        }

        desenhaVidros(window, objJogo);


        //Se for o fim do jogo
        if (objJogo.fimDoJogo()) {

            
            
            cout << "FIM DE JOGO" << endl;

            /*setando botao do fim*/
            botaoFim.setFont(font);
            botaoFim.setPosition(sf::Vector2f(0, 0));
            botaoFim.drawTo(window);
        }
        window.display();
        window.clear();
    }
    return 0;
}
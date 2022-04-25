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

/*nao funciona*/
Button ** criaBotoes(int nVidros){
    /*fonte*/
    sf::Font font;
    font.loadFromFile("./util/ariblk.ttf");

    /*botoes*/
    Button ** buttons;
    for(int i = 0; i < nVidros; i++){
        Button * botao = new Button (to_string(i+1), {50, 50}, 20, sf::Color::Blue, sf::Color::White);
        botao->setFont(font);
        botao->setPosition({(float)10 + 60 * i, 10});
        buttons[i] = botao;
    }

    return buttons;
}


int main(){
    int fase = 3;
    Jogo objJogo(fase);
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Water sort!");
    sf::Texture textura;
    textura.loadFromFile(objJogo.getBackground());
    sf::Sprite sprite(textura);

    sf::Font font;
    font.loadFromFile("./util/ariblk.ttf");

    //Botões para controlar passagem dos líquidos
    Button botaoFim("Fim, aperte ENTER para reiniciar!", {800, 600}, 40, sf::Color::Black, sf::Color::Green);

    Button* buttons[objJogo.getNVidros()];
    //buttons = criaBotoes(nVidros);

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

    int xCor, yCor, xPote, yPote, alturaVidro, larguraVidro, alturaCor, larguraCor;
        
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
                        objJogo.iniciaJogo();
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
            /*desalocando os botoes*/
            
            for(int i = 0; i < objJogo.getNVidros(); i++)
                delete buttons[i];
            
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
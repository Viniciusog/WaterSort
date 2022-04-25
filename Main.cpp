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



int main()
{
    Jogo objJogo;
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Water sort!");
    sf::Texture textura;
    textura.loadFromFile("background/imageFase1.jpg");
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
    bool fim = 0;

    int xCor = 100;
    int yCor = 300;
    int xPote = xCor + 1;
    int yPote = yCor + 20;
    int alturaVidro = 240;
    int larguraVidro = 80;
    int larguraCor = larguraVidro;
    int alturaCor = alturaVidro / objJogo.getNCores();

        
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
        /*Desenhando o background*/
        window.draw(sprite);


        /*Desenhando os botoes*/
        for (int i = 0; i < objJogo.getNVidros(); i++) {
            buttons[i]->drawTo(window);
        }

        //Desenha os 5 potes na tela de forma automática
        for(int i = 0; i < objJogo.getNVidros(); i++) {
            /*parede esquerda do vidro*/
            sf::RectangleShape linha1(sf::Vector2f(1.f, 20 + alturaVidro));
            linha1.setPosition(xCor, yCor);
            

            /*parede de baixo do vidro*/
            sf::RectangleShape linha2(sf::Vector2f(larguraVidro + 2, 1.f));
            linha2.setPosition(xCor, yPote + alturaVidro); 

            /*parede direita do vidro*/
            sf::RectangleShape linha3(sf::Vector2f(1.f, 20 + alturaVidro));
            linha3.setPosition(xCor + larguraVidro + 1, yCor);

            /*desenhando as paredes*/
            window.draw(linha1);
            window.draw(linha2);
            window.draw(linha3);

            /*desenhando as cores*/
            for (int j = objJogo.getNCores() -1; j >= 0; j--) {
                sf::RectangleShape shape1(sf::Vector2f(larguraCor, alturaCor));
                shape1.setFillColor(objJogo.getCorDePote(i, j));
                shape1.setPosition(xPote, yPote);
                window.draw(shape1);
                yPote += alturaCor;
            }

            xCor += alturaCor + 1 + 100;
            yPote = yCor + 20;
            xPote = xCor + 1;
        }

        yCor = 300;
        xCor = 100;
        yPote = yCor + 20;
        xPote = xCor + 1;


        //Se for o fim do jogo
        if (fim) {
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
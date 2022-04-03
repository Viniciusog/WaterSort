/*
Autor: Augusto dos Santos Gomes Vaz
Programa : cabeçalho da implementação da pilha jogada do jogo water sort
*/
#ifndef PILHA_H
#define PILHA_H
#include <SFML/Graphics.hpp>

class pilha{
    public:
        /*funcoes primitivas*/
        pilha();//construtor
        ~pilha();//sem muita função aqui
        bool push(sf::Color novoElemento);//empilha
        bool pop(sf::Color * auxSaida);//desempilha

        /*funcoes uteis*/
        bool peek(sf::Color *auxSaida);//devolve o elemento de cima da pilha
        bool vazia();//retorna se a pilha está vazia
        bool cheia();//retorna se a pilha está cheia
        int getTopo();//retorna onde está o indicador de topo
        sf::Color getColorAtPosition(int position);
    private:
        sf::Color vetor[4];
        int topo;
};
        

#endif /*PILHA_H*/
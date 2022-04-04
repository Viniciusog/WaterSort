/*
Autor: Augusto dos Santos Gomes Vaz
Programa : cabeçalho da implementação da classe jogável do jogo water sort
*/
#include "vidro.h"
#include "pilha.h"
#include "jogada.h"
#include "Glass.h"
#include <SFML/Graphics.hpp>

class jogo{
    public:
        jogo();//embaralha as cores entre os potes e deixa tudo pronto para começar
        ~jogo();//sem muita função
        void iniciaJogo();//inicia o jogo
        void atualizaMatrizCores();//desenha os quadrados na tela
        void input();//recebe do jogador qual é a próxima jogada
        void desenha(Glass* &glasses);
        bool fimDoJogo();//define quando o jogo chegou ao fim, ou seja, foi concluido
        sf::Color getCorMatriz(int conjunto, int elemento);
        sf::Color getCorDePote(int numConjunto, int elemento);
                /*passar para private*/
        vidro conjunto[5];
    private:
        
        bool embaralha();//ainda nao feito
        sf::Color matrizDeCores[5][4];//
        
        jogada j;//define qual vidro deve passar e qual deve receber
};
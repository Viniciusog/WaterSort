/*
Autor: Augusto dos Santos Gomes Vaz
Programa : cabeçalho da implementação da classe jogável do jogo water sort
*/
#include "vidro.h"
#include "pilha.h"
#include "jogada.h"

class jogo{
    public:
        jogo();//embaralha as cores entre os potes e deixa tudo pronto para começar
        ~jogo();//sem muita função
        bool iniciaJogo();//inicia o jogo
        bool desenha();//desenha os quadrados na tela
        void input();//recebe do jogador qual é a próxima jogada
    private:
        vidro conjunto[4];
        bool fimDoJogo();//define quando o jogo chegou ao fim, ou seja, foi concluido
        bool embaralha();//ainda nao feito
        
        jogada j;//define qual vidro deve passar e qual deve receber
};
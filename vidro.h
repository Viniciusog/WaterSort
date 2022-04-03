/*
Autor: Augusto dos Santos Gomes Vaz
Programa : cabeçalho da implementação da classe vidro do jogo water sort
*/
#ifndef VIDRO_H
#define VIDRO_H

#include "pilha.h"

class vidro : public pilha{
    public:
        vidro();
        ~vidro();
        bool setVidro(pilha&);
        bool passarLiquido(vidro &);
        bool getConcluida();
        bool verificaConcluida();
    //private:
        bool concluido;
};


#endif/*VIDRO_H*/
/**
* @author Augusto dos Santos Gomes Vaz
* Programa : cabeçalho da implementação da classe vidro do jogo water sort
*/
#ifndef VIDRO_H
#define VIDRO_H
#include "Pilha.h"

class Vidro : public Pilha {
    public:
        Vidro();
        ~Vidro();
        bool setVidro(Pilha&);
        bool passarLiquido(Vidro &);
        bool getConcluida();
        bool coresSaoIguais(sf::Color &cor1, sf::Color &cor2);
        bool verificaConcluida();
    private:
        bool concluido;
};

#endif
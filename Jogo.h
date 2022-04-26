/**
* @author Augusto dos Santos Gomes Vaz
* Programa: cabeçalho da implementação da classe jogável do jogo water sort
*/
#ifndef JOGO_H
#define JOGO_H

#include "Vidro.h"
#include "Pilha.h"
#include "Jogada.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class Jogo {
    public:
        Jogo(int fase);
        ~Jogo();
        void iniciaJogo(int fase);
        bool fimDoJogo(); // Define quando o jogo chegou ao fim, ou seja, foi concluido
        sf::Color getCorDePote(int numConjunto, int elemento); // Pega uma cor que está em um dos potes
        Vidro& getVidro(int numConjunto);
        /* Pega todas as informacoes necessaria pra criar a fase */
        bool getFase();
        bool getVidros();
        /* Getters de informacoes da fase */
        int getNVidros();
        int getNVidrosVazios();
        int getNCores();
        void atualizaDoador(int doador);
        void atualizaReceptor(int recp);
        int getDoador() const;
        int getReceptor() const;
        std::string getBackground();
    private:
        Vidro **conjunto;
        int nVidros;
        int nVidrosVazios;
        int nCores;
        int fase;
        std::string background;
        Jogada jogada; // Define qual vidro deve passar e qual deve receber
    friend sf::Color retornaCor(std::string nomeCor);
    friend void desenhaVidros(sf::RenderWindow & window, Jogo &objJogo, Button **buttons);
};

#endif
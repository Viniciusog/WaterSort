/**
* @author Augusto dos Santos Gomes Vaz
* Programa: cabeçalho da implementação da classe jogável do jogo water sort
*/
#ifndef JOGO_H
#define JOGO_H

#include "Vidro.h"
#include "Pilha.h"
#include "Jogada.h"
#include <SFML/Graphics.hpp>

class Jogo {

    public:
        Jogo();
        ~Jogo();
        void iniciaJogo();
        void atualizaMatrizCores(); //Define as cores para os quadrados da tela
        //void input(); //Recebe do jogador qual é a próxima jogada
        bool fimDoJogo(); //Define quando o jogo chegou ao fim, ou seja, foi concluido
        sf::Color getCorMatriz(int conjunto, int elemento); // Pega uma cor que está na matriz de cores
        sf::Color getCorDePote(int numConjunto, int elemento); // Pega uma cor que está em um dos potes
        Vidro& getVidro(int numConjunto);
        /*Pega todas as informacoes necessaria pra criar a fase*/
        bool getFase(/*int nArquivo*/);
        bool getVidros();

        /*getters de informacoes da fase*/
        int getNVidros();
        int getNVidrosVazios();
        int getNCores();
    private:
        sf::Color ** matrizDeCores;//[potes][liquidos]
        Vidro ** conjunto;
        int nVidros;
        int nVidrosVazios;
        int nCores;
        Jogada jogada;//define qual vidro deve passar e qual deve receber

    /*retorna a cor dada pela string*/
    friend sf::Color retornaCor(std::string nomeCor);
};

#endif
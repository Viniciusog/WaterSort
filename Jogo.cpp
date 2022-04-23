/**
* @author Augusto dos Santos Gomes Vaz
* Programa: Implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "Jogo.h"
#include <SFML/Graphics.hpp>
using namespace std;

Jogo::Jogo(int nVidros, int nCores){
    this->nVidros = nVidros;
    this->nCores = nCores;
    /*Alocando o conjunto*/
    conjunto = new Vidro *[nVidros];
    for(int i = 0; i < nVidros; i++)
        conjunto[i] = new Vidro (nCores);

    matrizDeCores = new sf::Color * [nVidros];
    for(int i = 0; i < nVidros; i++)
        matrizDeCores[i] = new sf::Color;


    iniciaJogo();
}

Jogo::~Jogo() {
    for(int i = 0; i < nVidros; i++)
        delete [] conjunto[i];
    delete [] conjunto;

    for(int i = 0; i < nVidros; i++)
        delete [] matrizDeCores[i];
    delete [] matrizDeCores;

}

void Jogo::iniciaJogo() {
    // Primeiro temos que remover todos os elementos de todas as pilhas
    for (int i = 0; i < 5; i++) {
         while(!conjunto[i]->vazia()) {
             sf::Color color;
             conjunto[i]->pop(color);
         }
    }
    // Insere as cores dentro dos potes
    sf::Color verde(34, 177, 76);
    sf::Color vermelho(210, 0, 5);
    sf::Color azul(0, 5, 201);
    sf::Color amarelo(197, 206, 4);

    conjunto[0]->push(verde);
    conjunto[0]->push(verde);
    conjunto[0]->push(verde);
    conjunto[0]->push(vermelho);

    conjunto[1]->push(vermelho);
    conjunto[1]->push(vermelho);
    conjunto[1]->push(vermelho);
    conjunto[1]->push(verde);

    conjunto[2]->push(azul);
    conjunto[2]->push(azul);
    conjunto[2]->push(azul);
    conjunto[2]->push(amarelo);

    conjunto[3]->push(amarelo);
    conjunto[3]->push(amarelo);
    conjunto[3]->push(amarelo);
    conjunto[3]->push(azul);
}

//Retorna true se 4 dos 5 potes estiverem completos
//(Um dos potes sempre irá ficar vazio ao final do jogo)
bool Jogo::fimDoJogo(){
    int qtdSucesso = 0;
    for (int i = 0; i < 5; i++){
        if(conjunto[i]->verificaConcluida())
            qtdSucesso++;
    }
    return qtdSucesso == 4;
}

//Usado para testar o jogo no console
//Seta o doador e o receptor dentro da jogada
/*
void Jogo::input() {
    int aux;
    cout << "Digite qual vidro voce quer retirar: " << endl;
    cin >> aux;
    if (aux < 0 || aux > 4) {
        do {
            cout << "Digite um valor válido"<<endl;
            cin >> aux;
        } while (aux < 0 || aux > 4);
    }
        

    jogada.setDoador(aux);//definindo o doador
    cout << "Digite qual vidro voce quer receber: " << endl;
    cin >> aux;
    if (aux < 0 || aux > 4) {
        do {
            cout << "Digite um valor válido" << endl;
            cin >> aux;
        } while(aux < 0 || aux > 4);
    }
        
    jogada.setReceptor(aux);//definindo o receptor

    cout << "Deu certo? " << conjunto[jogada.getDoador()].passarLiquido(conjunto[jogada.getReceptor()]) << endl;
}
*/

//Retorna uma cor de um dos potes
sf::Color Jogo::getCorDePote(int numConjunto, int elemento) {
    if (numConjunto > 4) {
        cout << "Não existe pote com o número: " << numConjunto << endl;
    }

    // Se estamos pegando de uma posição que tem cor, então retorna a cor. Se não, retorna preto
    if (elemento < conjunto[numConjunto]->getTopo()) {
        return conjunto[numConjunto]->getColorAtPosition(elemento);
    } else {
        return sf::Color::Black;
    }
}

//Atualiza as cores dentro da matriz de cores
void Jogo::atualizaMatrizCores(){
    Pilha<sf::Color> ** vetorPilhasAux; //Guarda os elementos tirados da 
    vetorPilhasAux = new Pilha<sf::Color> * [5];

    for(int i = 0; i < 5; i++){
        vetorPilhasAux[i] = new Pilha<sf::Color> (4);
    }



    sf::Color auxSaida;
    //Desempilhando, lendo e guardando os valores das cores
    for (int i = 0; i < 5; i++) {
        int j = 0;
        for (int j = 0; j < 4; j++) {
            if(!conjunto[i]->vazia()) {
                // Sendo printados com j(altura) invertidos, pois a ordem de retirada e de baixo pra cima
                conjunto[i]->pop(matrizDeCores[i][3-j]);

                vetorPilhasAux[i]->push(matrizDeCores[i][3-j]); //Empilhando na pilha aux
            } else
                matrizDeCores[i][3-j] = sf::Color(0, 0, 0);
        }
    }

    //Empilhando novamente e anotando os valores
    for (int i = 0; i < 5; i++){
        while(!vetorPilhasAux[i]->vazia()) {
            vetorPilhasAux[i]->pop(auxSaida);//Passa para a matriz de linha(vidro) i, coluna(nivel j)
            conjunto[i]->push(auxSaida);//Reempilhando na pilha original 

        }
    }
}

Vidro& Jogo::getVidro(int numConjunto) {
    return *conjunto[numConjunto];
}

//Retorna uma cor de dentro da matriz de cores
sf::Color Jogo::getCorMatriz(int conjunto, int elemento) {
    return this->matrizDeCores[conjunto][elemento];
}
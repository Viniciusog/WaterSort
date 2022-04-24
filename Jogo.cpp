/**
* @author Augusto dos Santos Gomes Vaz
* Programa: Implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;

sf::Color retornaCor(string nomeCor){

    /*Tabela de cores*/
    sf::Color verde (34, 177, 76);
    sf::Color lima(0, 255, 0);
    sf::Color vermelho(210, 0, 5);
    sf::Color salmao(250, 128, 114);
    sf::Color fuchsia(255, 0, 255);
    sf::Color roxo(128, 0, 128);
    sf::Color rosa(255, 20, 147);
    sf::Color azul(0, 5, 201);
    sf::Color navy(0, 0, 128);
    sf::Color ciano(0, 255, 255);
    sf::Color amarelo(197, 206, 4);
    sf::Color laranja(255, 69, 0);
    sf::Color preto(0, 0, 0);
    sf::Color branco(255, 255, 255);

    /*determinacao da saida*/
    if(nomeCor == "verde"){
        return verde;
    }
    
    if(nomeCor == "lima")
        return lima;
    if(nomeCor == "vermelho")
        return vermelho;
    if(nomeCor == "salmao")
        return verde;
    if(nomeCor == "salmao")
        return verde;
    if(nomeCor == "fuchsia")
        return fuchsia;
    if(nomeCor == "roxo")
        return roxo;
    if(nomeCor == "rosa")
        return rosa;
    if(nomeCor == "azul")
        return azul;
    if(nomeCor == "navy")
        return navy;
    if(nomeCor == "ciano")
        return ciano;
    if(nomeCor == "amarelo")
        return amarelo;
    if(nomeCor == "laranja")
        return laranja;
    if(nomeCor == "preto")
        return preto;

    /*Caso nao esteja listado, retorna branco*/
    return branco;
    
}



Jogo::Jogo(){
    getFase();
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
    /*Alocando o conjunto*/
    conjunto = new Vidro *[nVidros];
    for(int i = 0; i < nVidros; i++)
        conjunto[i] = new Vidro (nCores);

    matrizDeCores = new sf::Color * [nVidros];
    for(int i = 0; i < nVidros; i++)
        matrizDeCores[i] = new sf::Color;


    getVidros();
}



//Retorna true se 4 dos 5 potes estiverem completos
//(Um dos potes sempre irá ficar vazio ao final do jogo)
bool Jogo::fimDoJogo(){
    int qtdSucesso = 0;
    for (int i = 0; i < nVidros; i++){
        if(conjunto[i]->verificaConcluida())
            qtdSucesso++;
    }
    return qtdSucesso == nVidros - nVidrosVazios;
}

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
    vetorPilhasAux = new Pilha<sf::Color> * [nVidros];

    for(int i = 0; i < nVidros; i++){
        vetorPilhasAux[i] = new Pilha<sf::Color> (nCores);
    }



    sf::Color auxSaida;
    //Desempilhando, lendo e guardando os valores das cores
    for (int i = 0; i < nVidros; i++) {
        int j = 0;
        for (int j = 0; j < nCores; j++) {
            if(!conjunto[i]->vazia()) {
                // Sendo printados com j(altura) invertidos, pois a ordem de retirada e de baixo pra cima
                conjunto[i]->pop(matrizDeCores[i][nCores-1-j]);

                vetorPilhasAux[i]->push(matrizDeCores[i][nCores-1-j]); //Empilhando na pilha aux
            } else
                matrizDeCores[i][nCores-1-j] = sf::Color(0, 0, 0);
        }
    }

    //Empilhando novamente e anotando os valores
    for (int i = 0; i < nVidros; i++){
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

bool Jogo::getVidros(){
    fstream arquivo;
    arquivo.open("fases/fase1.txt", ios::in);
    if(!arquivo)
        return false;

    for (int i = 0; i < nVidros; i++) {
         while(!conjunto[i]->vazia()) {
             sf::Color color;
             conjunto[i]->pop(color);
         }
    }

    for(int k = 0; k < 3; k++){
                int aux;
                arquivo>>aux;
    }
    /*Recebendo informacoes dos vidros*/
    for(int i = 0; i < nVidros; i++){//percorre os vidros
        cout<<"vidro: "<<i+1<<endl;
        for(int j = 0; j < nCores; j++){//em cada vidro empilha o numero de cores que cabe em cada pilha
            
            string nomeCor;
            arquivo>>nomeCor;
            if(nomeCor != "blank"){
                conjunto[i]->push(retornaCor(nomeCor));
                cout<<"cor : "<<j+1<<endl;
                cout<<"empilhando cor : "<< nomeCor<<endl;
            }
        }
    }

    arquivo.close();
    return true;
}

/*Pega todas as informacoes de cada fase*/
bool Jogo::getFase(/*int nArquivo*/){
    /*Determinacao da fase
    cout<<"Qual sera a fase ? ";
    cin>>nArquivo;
    fstream arquivo;
    arquivo.open("fases/fase"+to_string(nArquivo)+".txt", ios::in);
    */

   fstream arquivo;
    arquivo.open("fases/fase1.txt", ios::in);


    if(!arquivo)
        return false;

    /*Recebendo parametros gerais*/
    arquivo>>nVidros;
    arquivo>>nVidrosVazios;
    arquivo>>nCores;

    cout<<nVidros<<endl;
    cout<<nVidrosVazios<<endl;
    cout<<nCores<<endl;

    arquivo.close();
    return true;
}


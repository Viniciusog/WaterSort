/*
Autor: Augusto dos Santos Gomes Vaz
Programa : implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "jogo.h"
#include <SFML/Graphics.hpp>

using namespace std;

jogo::jogo(){
   iniciaJogo();
}

jogo::~jogo(){}//nao tem função por hora

void jogo::iniciaJogo(){
    //primeiro temos que remover todos os elementos de todas as pilhas
    for (int i = 0; i < 5; i++) {
         while(!conjunto[i].vazia()) {
             sf::Color color;
             conjunto[i].pop(&color);
         }
    }

    sf::Color verde(34, 177, 76);
    sf::Color vermelho(210, 0, 5);
    sf::Color azul(0, 5, 201);
    sf::Color amarelo(197, 206, 4);

    conjunto[0].push(verde);
    conjunto[0].push(verde);
    conjunto[0].push(verde);
    conjunto[0].push(vermelho);

    conjunto[1].push(vermelho);
    conjunto[1].push(vermelho);
    conjunto[1].push(vermelho);
    conjunto[1].push(verde);

    conjunto[2].push(azul);
    conjunto[2].push(azul);
    conjunto[2].push(azul);
    conjunto[2].push(amarelo);

    conjunto[3].push(amarelo);
    conjunto[3].push(amarelo);
    conjunto[3].push(amarelo);
    conjunto[3].push(azul);
}

bool jogo::fimDoJogo(){
    int qtdSucesso = 0;
    for (int i = 0; i < 5; i++){//caso todas pilhas estejam concluidas da como fim de jogo
        if(conjunto[i].verificaConcluida())
            qtdSucesso++;
    }
    return qtdSucesso == 4;
}

//seta qual a jogada
void jogo::input() {
    int aux;
    cout<<"Digite qual vidro voce quer retirar: "<<endl;
    cin>>aux;
    if(aux < 0 || aux > 4)
        do{
            cout<<"digite um valor valido"<<endl;
            cin>>aux;
        }while(aux < 0 || aux > 4);

    j.setDoador(aux);//definindo o doador
    cout<<"Digite qual vidro voce quer receber: "<<endl;
    cin>>aux;
    if(aux < 0 || aux > 4)
        do{
            cout<<"digite um valor valido"<<endl;
            cin>>aux;
        }while(aux < 0 || aux > 4);

    j.setReceptor(aux);//definindo o receptor

    cout<<"deu certo? "<<conjunto[j.getDoador()].passarLiquido(conjunto[j.getReceptor()])<<endl;
}

sf::Color jogo::getCorDePote(int numConjunto, int elemento) {
    if (numConjunto > 4) {
        cout << "NÃO EXISTE O POTE COM O NÚMERO: " << numConjunto << endl;
    }

    // Se estamos pegando de uma posição que tem cor, então retorna a cor. Se não, retorna preto
    if (elemento < conjunto[numConjunto].getTopo()) {
        return conjunto[numConjunto].getColorAtPosition(elemento);
    } else {
        return sf::Color::Black;
    }
}

//desenha os vidros
void jogo::atualizaMatrizCores(){//as cores podem ser = 0
    pilha vetorPilhasAux[5];//guarda os elementos tirados da 
    sf::Color auxSaida;
    //desempilhand, lendo e guardando os valores das cores
    for (int i = 0; i < 5; i++) {
        int j = 0;
        for (int j = 0; j < 4; j++) {
            if(!conjunto[i].vazia()){
                conjunto[i].pop(&matrizDeCores[i][3-j]);//sendo printados com j(altura) invertidos, pois a ordem de retirada e de baixo pra cima
                vetorPilhasAux[i].push(matrizDeCores[i][3-j]);//empilhando na pilha aux
            } else
                matrizDeCores[i][3-j] = sf::Color(0, 0, 0);
        }
    }

    //empilhando novamente e anotando os valores
    for (int i = 0; i < 5; i++){
        while(!vetorPilhasAux[i].vazia()) {
            vetorPilhasAux[i].pop(&auxSaida);//passa para a matriz de linha(vidro) i, coluna(nivel j)
            conjunto[i].push(auxSaida);//reempilhando na pilha original 
        }
    }
}

sf::Color jogo::getCorMatriz(int conjunto, int elemento) {
    return this->matrizDeCores[conjunto][elemento];
}

/* void jogo::desenha(Glass* &glasses, int size) {
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout<<"|"<<matrizDeCores[j][i]<<"| ";
        }
        cout<<endl;
    }
} */
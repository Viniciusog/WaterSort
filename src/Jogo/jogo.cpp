/*
Autor: Augusto dos Santos Gomes Vaz
Programa : implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "jogo.h"

using namespace std;

jogo::jogo(){
    //setando aos vidros como iguais para teste 
    
    for(int i = 0; i < 2; i++){//todos tem 3 "0s", precisam de 4
        conjunto[0].push(1);
        conjunto[1].push(2);
        conjunto[2].push(1);
        //potes livres
        conjunto[3].push(1);
        conjunto[4].push(2);
    }

    //setando a matriz de cores pela primeira vez
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            matrizDeCores[i][j] = 0;
        }
    }
    
    //atualizando de acordo com as mudancas 
    
}

jogo::~jogo(){}//nao tem função por hora

bool jogo::iniciaJogo(){
        while(!fimDoJogo()){//enquanto nao acontecer o final do jogo, fica recebendo inputs e fazendo as jogadas
            atualizaMatrizCores();
            desenha();
            input();
            cout<<"deu certo? "<<conjunto[j.getDoador()].passarLiquido(conjunto[j.getReceptor()])<<endl;
        //atualizando de acordo com as mudancas 
        
    }
    cout<<"parabens, voce ganhou o jogo!"<<endl;
    return true;
}

bool jogo::fimDoJogo(){
    for (int i = 0; i < 3; i++){//caso todas pilhas estejam concluidas da como fim de jogo
        if(!conjunto[i].verificaConcluida())
            return false;
    }
    return true;
}

//seta qual a jogada
void jogo::input(){
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
}

//desenha os vidros
void jogo::atualizaMatrizCores(){//as cores podem ser = 0
    pilha vetorPilhasAux[5];//guarda os elementos tirados da 
    int auxSaida;
    //desempilhand, lendo e guardando os valores das cores
    for (int i = 0; i < 5; i++){
        int j = 0;
        for (int j = 0; j < 4; j++){
            if(!conjunto[i].vazia()){
                conjunto[i].pop(&matrizDeCores[i][3-j]);//sendo printados com j(altura) invertidos, pois a ordem de retirada e de baixo pra cima
                vetorPilhasAux[i].push(matrizDeCores[i][3-j]);//empilhando na pilha aux
            }else
                matrizDeCores[i][3-j] = 0;
            
        }
    }

    //empilhando novamente e anotando os valores
    for (int i = 0; i < 5; i++){
        while(!vetorPilhasAux[i].vazia()){
            vetorPilhasAux[i].pop(&auxSaida);//passa para a matriz de linha(vidro) i, coluna(nivel j)
            conjunto[i].push(auxSaida);//reempilhando na pilha original 
        }
    }
}

void jogo::desenha(){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout<<"|"<<matrizDeCores[j][i]<<"| ";
        }
        cout<<endl;
    }
}
/*
Autor: Augusto dos Santos Gomes Vaz
Programa : implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "jogo.h"

using namespace std;

jogo::jogo(){
    //setando aos vidros como iguais para teste 
    for(int i = 0; i < 4; i++){
        conjunto[0].push(0);
        conjunto[1].push(0);
        conjunto[2].push(0);
        conjunto[3].push(0);
    }
    
    //desenha();
}

jogo::~jogo(){}//nao tem função por hora

bool jogo::iniciaJogo(){
    if(fimDoJogo())
        return false;

    while(!fimDoJogo()){//enquanto nao acontecer o final do jogo, fica recebendo inputs e fazendo as jogadas
        input();
        conjunto[j.getReceptor()].passarLiquido(conjunto[j.getReceptor()]);
        //desenha();
    }
    cout<<"parabens, voce ganhou o jogo!"<<endl;
    return true;
}

bool jogo::fimDoJogo(){
    for (int i = 0; i < 4; i++){//caso todas pilhas estejam concluidas da como fim de jogo
        if(!conjunto[i].verificaConcluida())
            return true;
    }
    return false;
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
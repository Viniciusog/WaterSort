/*
Autor: Augusto dos Santos Gomes Vaz
Programa : implementação da classe jogada do jogo water sort
*/
//inclusao das bibliotecas
#include <iostream>
#include "jogada.h"
//namespace
using namespace std;

//define qual vai ser o doador na jogada
void jogada::setDoador(int vidroDoador){
    this->vidroDoador = vidroDoador;
}

//define qual vai ser o receptor na jogada
void jogada::setReceptor(int vidroReceptor){
    this->vidroReceptor = vidroReceptor;
}

//devolve o doador
int jogada::getDoador(){
    return vidroDoador;
}

//devolve o receptor
int jogada::getReceptor(){
    return vidroReceptor;
}
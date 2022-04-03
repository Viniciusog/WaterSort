/*
Autor : Augusto dos Santos Gomes Vaz
Programa : Implementação de uma TAD pilha
*/

//bibliotecas
#include <iostream>
#include "pilha.h"
#include <SFML/Graphics.hpp>

//namespace
using namespace std;

//construtor da pilha
pilha::pilha(){
    topo = 0;
}

//destrutor da pilha
pilha::~pilha(){}

//teste de pilha vazia
bool pilha::vazia(){
    return topo == 0;
}

//teste de pilha cheia
bool pilha::cheia(){
    return topo == 4;
}

//função de empilhar
bool pilha::push(sf::Color novoElemento){
    if(!cheia()){
        vetor[topo++] = novoElemento;
        return true;
    }
    return false;
}

//função de desempilhar
bool pilha::pop(sf::Color * auxSaida){
    if(!vazia()){
        *auxSaida = vetor[--topo];
        return true;
    }
    return false;
}

//função de espiar o topo
bool pilha::peek(sf::Color * auxSaida){
    if(!vazia()){
        *auxSaida = vetor[topo-1];
        return true;
    }
    return false;
}

//função de retornar o índice
int pilha::getTopo(){
    return topo -1;
}
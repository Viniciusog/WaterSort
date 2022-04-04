/**
* @author Augusto dos Santos Gomes Vaz
* Programa : Implementação de uma TAD Pilha
*/
#include <iostream>
#include "Pilha.h"
#include <SFML/Graphics.hpp>
using namespace std;

Pilha::Pilha(){
    topo = 0;
}

Pilha::~Pilha() {
    
}

bool Pilha::vazia(){
    return topo == 0;
}

bool Pilha::cheia(){
    return topo == 4;
}

// Função de empilhar
bool Pilha::push(sf::Color novoElemento){
    if(!cheia()){
        vetor[topo++] = novoElemento;
        return true;
    }
    return false;
}

// Função de desempilhar
bool Pilha::pop(sf::Color * auxSaida){
    if(!vazia()){
        *auxSaida = vetor[--topo];
        return true;
    }
    return false;
}

// Função de espiar o topo
bool Pilha::peek(sf::Color * auxSaida){
    if(!vazia()){
        *auxSaida = vetor[topo-1];
        return true;
    }
    return false;
}

sf::Color Pilha::getColorAtPosition(int position) {
    return vetor[position];
}

//função de retornar o índice
int Pilha::getTopo(){
    return topo;
}
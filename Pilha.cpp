/**
* @author Augusto dos Santos Gomes Vaz
* Programa : Implementação de uma TAD Pilha
*/
#include <iostream>
#include "Pilha.h"
#include <SFML/Graphics.hpp>
using namespace std;

template <class T>
Pilha<T>::Pilha(int tamanho){
    this->tamanho = tamanho;
    vetor = new T [this->tamanho];
    topo = 0;
}

template <class T>
Pilha<T>::~Pilha() {
    
}

template <class T>
bool Pilha<T>::vazia(){
    return topo == 0;
}

template <class T>
bool Pilha<T>::cheia(){
    return topo == tamanho;
}

// Função de empilhar
template <class T>
bool Pilha<T>::push(T novoElemento){
    if(!cheia()){
        vetor[topo++] = novoElemento;
        return true;
    }
    return false;
}

// Função de desempilhar
template <class T>
bool Pilha<T>::pop(T &auxSaida){
    if(!vazia()){
        auxSaida = vetor[--topo];
        return true;
    }
    return false;
}

// Função de espiar o topo
template <class T>
bool Pilha<T>::peek(T & auxSaida){
    if(!vazia()){
        auxSaida = vetor[topo-1];
        return true;
    }
    return false;
}

template <class T>
T Pilha<T>::getColorAtPosition(int position) {
    return vetor[position];
}

//função de retornar o índice
template <class T>
int Pilha<T>::getTopo(){
    return topo;
}
/**
* @author Augusto dos Santos Gomes Vaz
* Programa: cabeçalho da implementação da pilha jogada do jogo water sort
*/

#ifndef PILHA_H
#define PILHA_H
#include <SFML/Graphics.hpp>

template <class T>
class Pilha{
    public:
        /*funcoes primitivas*/
        Pilha(int tamanho);//construtor
        ~Pilha();//sem muita função aqui
        bool push(T novoElemento);//empilha
        bool pop(T &auxSaida);//desempilha

        /*funcoes uteis*/
        bool peek(T &auxSaida);//devolve o elemento de cima da pilha
        bool vazia();//retorna se a pilha está vazia
        bool cheia();//retorna se a pilha está cheia
        int getTopo();//retorna onde está o indicador de topo
        int getTamanho();
        T getColorAtPosition(int position);
    private:
        T* vetor;
        int topo;
        int tamanho;
};

template <class T>
Pilha<T>::Pilha(int tamanho){
    this->tamanho = tamanho;
    vetor = new T [this->tamanho];
    topo = 0;
}

template <class T>
Pilha<T>::~Pilha() {
    delete[] vetor;
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


template<class T>
int Pilha<T>::getTamanho(){
    return tamanho;
}

#endif 
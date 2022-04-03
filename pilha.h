/*
Autor: Augusto dos Santos Gomes Vaz
Programa : cabeçalho da implementação da pilha jogada do jogo water sort
*/
#ifndef PILHA_H
#define PILHA_H

class pilha{
    public:
        /*funcoes primitivas*/
        pilha();//construtor
        ~pilha();//sem muita função aqui
        bool push(int novoElemento);//empilha
        bool pop(int * auxSaida);//desempilha

        /*funcoes uteis*/
        bool peek(int *auxSaida);//devolve o elemento de cima da pilha
        bool vazia();//retorna se a pilha está vazia
        bool cheia();//retorna se a pilha está cheia
        int getTopo();//retorna onde está o indicador de topo
    private:
        int vetor[4];
        int topo;
};
        

#endif /*PILHA_H*/
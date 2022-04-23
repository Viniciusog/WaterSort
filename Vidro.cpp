/**
* @author Augusto dos Santos Gomes Vaz
* Programa : implementação da classe Vidro do jogo water sort
*/
#include <iostream>
#include "Vidro.h"
#include "Pilha.h"
#include <SFML/Graphics.hpp>
using namespace std;

// Construtor de Vidro, seta que nao foi concluido, ou seja, nao tem todas as cores iguais

Vidro::Vidro(): Pilha(4){
    concluido = false;
}

Vidro::Vidro(int tamanho): Pilha(tamanho){
    concluido = false;
}

Vidro::~Vidro() {

}

// Permite que se sete o Vidro a partir de uma pilha
void Vidro::setVidro(Pilha& pilhaAux) {
    sf::Color aux;
    while(!pilhaAux.vazia()){
        pilhaAux.pop(aux);
        push(aux);
    }
}

// Verifica se todos os elementos do Vidro tem a mesma cor
bool Vidro::verificaConcluida() {
    // Declarações locais
    Pilha pilhaAux (getTamanho());
    sf::Color auxSaida1, auxSaida2;
    
    // Caso esteja vazia, nao está concluida
    if(!cheia())
        concluido = false;
    else
        concluido = true;
    

    while(!vazia() && concluido){
        pop(auxSaida1); //Desempilha o topo e compara com o elemento de baixo
        peek(auxSaida2);

        //Caso o topo seja diferente do antecessor, considera falso
        if (auxSaida1 != auxSaida2) {
            concluido = false;
        }
        pilhaAux.push(auxSaida1); //Joga o elemento para a pilha auxiliar
    }

    //Devolvendo a pilha aux para a pilha antiga
    while(!pilhaAux.vazia()){
        pilhaAux.pop(auxSaida1);
        push(auxSaida1);
    }

    return concluido;
}

//Devolve se o Vidro foi concluido
bool Vidro::getConcluida(){
    return concluido;
}

bool Vidro::coresSaoIguais(sf::Color &cor1, sf::Color &cor2) {
    if (cor1.r == cor2.r && cor1.g == cor2.g && cor1.g == cor2.g) {
        return true;
    }
    return false;
}

//Passa o liquido do Vidro atual para o Vidro recebido como parâmetro
bool Vidro::passarLiquido(Vidro& VidroReceptor) {
    //Se o Vidro receptor estiver cheio ou o Vidro doador estiverem vazios não é possível transferir
    if (!VidroReceptor.vazia()) {
        sf::Color aux1, aux2;
        VidroReceptor.peek(aux1);
        peek(aux2);
        // Verificando se o liquido que vai ser passado é igual ao do topo do que está recebendo
        if(!(aux2 == aux1))
            return false;
        /*
        if(!coresSaoIguais(aux1, aux2)) 
            return false;
        */
    }
    
    if (!VidroReceptor.cheia() && !vazia()) {
        sf::Color auxSaida;
        pop(auxSaida);                     //desempilha do doador
        VidroReceptor.push(auxSaida);       //empilha no receptor
        VidroReceptor.verificaConcluida();  //verifica se esta concluida
        return true;
    }
    return false;
}
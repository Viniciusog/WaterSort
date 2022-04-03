/*
Autor: Augusto dos Santos Gomes Vaz
Programa : implementação da classe vidro do jogo water sort
*/

//inclusao das bibliotecas
#include <iostream>
#include "vidro.h"
#include <SFML/Graphics.hpp>
//namespace
using namespace std;

//construtor de vidro, seta que nao foi concluido, ou seja, nao tem todas as cores iguais
vidro::vidro() {
    concluido = false;
}

//sem muita função por hora
vidro::~vidro(){}

/*PRECISA MELHORAR*/
//permite que se sete o vidro a partir de uma pilha
bool vidro::setVidro(pilha& pilhaAux){//seta o vidro de acordo com a pilha passada
    sf::Color aux;
    while(!pilhaAux.vazia()){
        pilhaAux.pop(&aux);
        push(aux);
    }
}

//verifica se todos os elementos do vidro tem a mesma cor
bool vidro::verificaConcluida(){
    //declarações locais
    pilha pilhaAux;
    sf::Color auxSaida1, auxSaida2;
    
    //caso esteja vazia, nao está concluida
    if(!cheia())
        concluido = false;
    else
        concluido = true;
    

    while(!vazia() && concluido){
        pop(&auxSaida1);//desempilha o topo e compara com o elemento de baixo
        peek(&auxSaida2);
        if(auxSaida1 != auxSaida2){//caso o topo seja diferente do antecessor, considera falso
            concluido = false;
        }
        pilhaAux.push(auxSaida1);//joga o elemento para a pilha auxiliar
    }

    //devolvendo a pilha aux para a pilha antiga
    while(!pilhaAux.vazia()){
        pilhaAux.pop(&auxSaida1);
        push(auxSaida1);
    }

    return concluido;
}

//devolve se o vidro foi concluido
bool vidro::getConcluida(){//ok
    return concluido;
}

bool vidro::coresSaoIguais(sf::Color &cor1, sf::Color &cor2) {
    if (cor1.r == cor2.r && cor1.g == cor2.g && cor1.g == cor2.g) {
        return true;
    }
    return false;
}

//passa o liquido do vidro atual para o vidro recebido como parâmetro
bool vidro::passarLiquido(vidro& vidroReceptor){
    //se o vidro receptor estiver cheio ou o vidro doador estiverem vazios não é possível transferir
    if(!vidroReceptor.vazia()){
        sf::Color aux1, aux2;
        vidroReceptor.peek(&aux1);
        peek(&aux2);
        if(!coresSaoIguais(aux1, aux2)) //verificando se o liquido que vai ser passado é igual ao do topo do que está recebendo
            return false;
    }
    
    if(!vidroReceptor.cheia() && !vazia()){

        sf::Color auxSaida;
        pop(&auxSaida);//desempilha do doador
        vidroReceptor.push(auxSaida);//empilha no receptor
        vidroReceptor.verificaConcluida();//verifica se esta concluida
        return true;
    }
    return false;
}






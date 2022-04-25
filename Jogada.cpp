/**
 * @author Augusto dos Santos Gomes Vaz
 * Programa: Implementação da classe Jogada do jogo water sort
 */

#include <iostream>
#include "Jogada.h"
using namespace std;

//Define qual vai ser o doador na jogada
void Jogada::setDoador(int vidroDoador){
    this->vidroDoador = vidroDoador;
}

//Define qual vai ser o receptor na jogada
void Jogada::setReceptor(int vidroReceptor){
    this->vidroReceptor = vidroReceptor;
}

int Jogada::getDoador() const {
    return vidroDoador;
}

int Jogada::getReceptor() const {
    return vidroReceptor;
}
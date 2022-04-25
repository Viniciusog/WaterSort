/**
* @author Augusto dos Santos Gomes Vaz
* Programa: Implementação da classe jogável do jogo water sort
*/
#include <iostream>
#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Button.h"
using namespace std;

sf::Color retornaCor(string nomeCor){

    /*Tabela de cores*/
    sf::Color verde (34, 177, 76);
    sf::Color lima(0, 255, 0);
    sf::Color vermelho(210, 0, 5);
    sf::Color salmao(250, 128, 114);
    sf::Color fuchsia(255, 0, 255);
    sf::Color roxo(128, 0, 128);
    sf::Color rosa(255, 20, 147);
    sf::Color azul(0, 5, 201);
    sf::Color navy(0, 0, 128);
    sf::Color ciano(0, 255, 255);
    sf::Color amarelo(197, 206, 4);
    sf::Color laranja(255, 69, 0);
    sf::Color preto(0, 0, 0);
    sf::Color branco(255, 255, 255);

    /* Determinacao da saida*/
    if (nomeCor == "verde")
        return verde;
    if (nomeCor == "lima")
        return lima;
    if (nomeCor == "vermelho")
        return vermelho;
    if (nomeCor == "salmao")
        return verde;
    if (nomeCor == "salmao")
        return verde;
    if (nomeCor == "fuchsia")
        return fuchsia;
    if (nomeCor == "roxo")
        return roxo;
    if (nomeCor == "rosa")
        return rosa;
    if (nomeCor == "azul")
        return azul;
    if (nomeCor == "navy")
        return navy;
    if (nomeCor == "ciano")
        return ciano;
    if (nomeCor == "amarelo")
        return amarelo;
    if (nomeCor == "laranja")
        return laranja;
    if (nomeCor == "preto")
        return preto;
    /*Caso nao esteja listado, retorna branco*/
    return branco;   
}

Jogo::Jogo(int fase=1) {
    this->fase = fase;
    iniciaJogo(this->fase);
    jogada.setDoador(-1);
    jogada.setReceptor(-1);
}

Jogo::~Jogo() {
    cout << "Chamada do destrutor" << endl;
}

void Jogo::iniciaJogo(int fase) {
        this->fase = fase;
        getFase();

        /*Alocando o conjunto*/
        conjunto = new Vidro *[7];
        for (int i = 0; i < 7; i++) {
            conjunto[i] = new Vidro(nCores);
        }   
        getVidros();
}

//Retorna true se 4 dos 5 potes estiverem completos
//(Um dos potes sempre irá ficar vazio ao final do jogo)
bool Jogo::fimDoJogo() {
    int qtdSucesso = 0;
    for (int i = 0; i < nVidros; i++){
        if(conjunto[i]->verificaConcluida())
            qtdSucesso++;
    } 
    if (qtdSucesso == nVidros - nVidrosVazios){
        return true;
    }        
    return false;
}

//Retorna uma cor de um dos potes
sf::Color Jogo::getCorDePote(int numConjunto, int elemento) {
    if (numConjunto > nVidros) {
        cout << "Não existe pote com o número: " << numConjunto << endl;
    }

    // Se estamos pegando de uma posição que tem cor, então retorna a cor. Se não, retorna preto
    if (elemento < conjunto[numConjunto]->getTopo()) {
        return conjunto[numConjunto]->getColorAtPosition(elemento);
    } else {
        return sf::Color::Black;
    }
}

Vidro& Jogo::getVidro(int numConjunto) {
    return *conjunto[numConjunto];
}

bool Jogo::getVidros() {
    fstream arquivo;
    arquivo.open("fases/fase"+to_string(fase)+".txt", ios::in);
    if (!arquivo)
        return false;

    for (int i = 0; i < 7; i++) {
         while(!conjunto[i]->vazia()) {
             sf::Color color;
             conjunto[i]->pop(color);
         }
    }

    /*Pulandos os 4 primeiros termos que sao os parametros do jogo*/
    for (int k = 0; k < 4; k++){
        string aux;
        arquivo >> aux;
    }
    /*Recebendo informacoes dos vidros*/
    for (int i = 0; i < 7; i++){   //percorre os vidros
        for (int j = 0; j < nCores; j++) { //em cada vidro empilha o numero de cores que cabe em cada pilha
            string nomeCor;
            arquivo>>nomeCor;
            if (nomeCor != "blank") {
                conjunto[i]->push(retornaCor(nomeCor));
            }
        }
    }
    arquivo.close();
    return true;
}

/*Pega todas as informacoes de cada fase */
bool Jogo::getFase() {
    fstream arquivo;
    arquivo.open("fases/fase"+to_string(fase)+".txt", ios::in);

    if (!arquivo) {
        return false;
    }

    /*Recebendo parametros gerais*/
    arquivo>>nVidros;
    arquivo>>nVidrosVazios;
    arquivo>>nCores;
    arquivo>>background;
    arquivo.close();
    return true;
}

int Jogo::getNVidros() {
    return nVidros;
}

int Jogo::getNVidrosVazios() {
    return nVidrosVazios;
}

int Jogo::getNCores() {
    return nCores;
}

string Jogo::getBackground() {
    return background;
}

void Jogo::atualizaDoador(int doador) {
    jogada.setDoador(doador);
}

void Jogo::atualizaReceptor(int recp) {
    jogada.setReceptor(recp);
}

int Jogo::getDoador() const {
    return jogada.getDoador();
}

int Jogo::getReceptor() const {
    return jogada.getReceptor();
}

/*Desenha os vidros na tela*/
void desenhaVidros(sf::RenderWindow & window, Jogo &objJogo, Button **buttons) {

        int nVidros = objJogo.getNVidros();
        /*Determinando as posicoes*/
        int larguraVidro = 78;
        int alturaVidro = 240;
        int larguraCor = larguraVidro;
        int alturaCor = alturaVidro / objJogo.getNCores();
        
        int tamanhoTotal = nVidros * (larguraVidro + 2) + (nVidros - 1) * (136-larguraVidro);
        int xCentro = 540;

        int xCor = xCentro - (tamanhoTotal / 2);
        int yCor = 300;
        int xPote = xCor + 1;
        int yPote = yCor + 20;
       
        //Desenha os 5 potes na tela de forma automática
        for(int i = 0; i < objJogo.getNVidros(); i++) {
            /*Parede esquerda do vidro*/
            sf::RectangleShape linha1(sf::Vector2f(1.f, 20 + alturaVidro));
            linha1.setPosition(xCor, yCor);
            
            /*Parede de baixo do vidro*/
            sf::RectangleShape linha2(sf::Vector2f(larguraVidro + 2, 1.f));
            linha2.setPosition(xCor, yPote + alturaVidro); 

            /*Parede direita do vidro*/
            sf::RectangleShape linha3(sf::Vector2f(1.f, 20 + alturaVidro));
            linha3.setPosition(xCor + larguraVidro + 1, yCor);

            float yBotao = yPote + alturaVidro + 30;
            float xBotao = xCor + (larguraVidro + 2 - buttons[i]->getWidth()) / 2;
            buttons[i]->setPosition({xBotao, yBotao}, false);
            buttons[i]->drawTo(window);

            /*Desenhando as paredes*/
            window.draw(linha1);
            window.draw(linha2);
            window.draw(linha3);

            /*Dsenhando as cores*/
            for (int j = objJogo.getNCores() -1; j >= 0; j--) {
                sf::RectangleShape shape1(sf::Vector2f(larguraCor, alturaCor));

                /*Caso a cor nao seja vazia*/
                if(objJogo.getCorDePote(i, j) != sf::Color(0, 0, 0)){
                    shape1.setFillColor(objJogo.getCorDePote(i, j));
                    shape1.setPosition(xPote, yPote);
                    window.draw(shape1);
                }    
                yPote += alturaCor;
            }
            //Incrementando os valores  das posicoes dos potes
            xCor += 1 + 135;
            yPote = yCor + 20;
            xPote = xCor + 1;
        }
}
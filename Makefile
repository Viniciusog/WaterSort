all: compile link

compile:
	g++ -Isrc/include -c main.cpp jogada.cpp jogo.cpp pilha.cpp jogada.cpp testeJogo.cpp vidro.cpp Button.cpp glass.cpp
link:
	g++ main.o jogada.o jogo.o pilha.o vidro.o button.o glass.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

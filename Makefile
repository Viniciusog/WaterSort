all: compile link

compile:
	g++ -Isrc/include -c ./main.cpp ./src/Jogo/jogada.cpp ./src/Jogo/jogo.cpp ./src/Jogo/pilha.cpp ./src/Jogo/jogada.cpp ./src/Jogo/testeJogo.cpp ./src/Jogo/vidro.cpp 
link:
	g++ main.o jogada.o jogo.o pilha.o vidro.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

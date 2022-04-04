all: compile link

compile:
	g++ -Isrc/include -c Main.cpp Jogada.cpp Jogo.cpp Pilha.cpp Jogada.cpp  Vidro.cpp Button.cpp
link:
	g++ Main.o Jogada.o Jogo.o Pilha.o Vidro.o Button.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

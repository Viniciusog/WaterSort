all: compile link

compile:
	g++ -Isrc/include -c MainTeste.cpp Jogada.cpp Jogo.cpp Jogada.cpp Vidro.cpp Button.cpp
link:
	g++ MainTeste.o Jogada.o Jogo.o Vidro.o Button.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

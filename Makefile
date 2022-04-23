all: compile link

compile:
	g++ -Isrc/include -c Main.cpp Jogo.cpp Vidro.cpp Button.cpp Jogada.cpp
link:
	g++ Main.o Jogo.o Vidro.o Button.o Jogada.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

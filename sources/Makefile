OBJS = main.o bola.o funcoes.o jogo.o tabuleiro.o player1.o player2.o
all: jogo
jogo: $(OBJS)
	g++  $(OBJS) -o ../bin/$@; cd ..
main.o: main.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
bola.o: bola.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
funcoes.o: funcoes.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
jogo.o: jogo.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
tabuleiro.o: tabuleiro.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
player1.o: player1.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
player2.o: player2.cpp
	g++ -c $< -o $@ -Wall -std=c++17 -g
clean:
	rm *.o ../bin/jogo
run:
	cd ../bin; ./jogo

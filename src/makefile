CC = g++
CFLAGS = -Wall -pedantic

all: fila.o pilha.o

fila.o: fila.cpp fila.hpp
	$(CC) $(CFLAGS) -c fila.cpp

pilha.o: pilha.cpp pilha.hpp
	$(CC) $(CFLAGS) -c pilha.cpp

clean:
	rm -f *.o *.out

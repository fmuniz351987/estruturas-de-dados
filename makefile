CC = g++
CFLAGS = -Wall -pedantic

specs: fila_spec.out pilha_spec.out

fila_spec.out: fila_spec.o fila.o
	$(CC) $(CFLAGS) -o fila_spec.out fila.o fila_spec.o
fila_spec.o: fila_spec.cpp fila.o
	$(CC) $(CFLAGS) -c fila_spec.cpp
fila.o: fila.cpp fila.hpp
	$(CC) $(CFLAGS) -c fila.cpp

pilha_spec.out: pilha_spec.o pilha.o
	$(CC) $(CFLAGS) -o pilha_spec.out pilha_spec.o pilha.o
pilha_spec.o: pilha_spec.cpp pilha.o
	$(CC) $(CFLAGS) -c pilha_spec.cpp
pilha.o: pilha.cpp pilha.hpp
	$(CC) $(CFLAGS) -c pilha.cpp

clean:
	rm -f *.o *.out

CC = g++
CFLAGS = -Wall -pedantic

all: fila_spec.out pilha_spec.out

fila_spec.out: fila_spec.o
	$(CC) $(CFLAGS) -o fila_spec.out fila_spec.o ../src/fila.o
fila_spec.o: fila_spec.cpp ../src/fila.o 
	$(CC) $(CFLAGS) -c fila_spec.cpp

pilha_spec.out: pilha_spec.o
	$(CC) $(CFLAGS) -o pilha_spec.out pilha_spec.o ../src/pilha.o
pilha_spec.o: pilha_spec.cpp ../src/pilha.o
	$(CC) $(CFLAGS) -c pilha_spec.cpp

clean:
	rm -f *.o *.out

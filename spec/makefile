CC = g++ -Wall -pedantic

stack_spec.out: stack_spec.o
	$(CC) stack_spec.o -o stack_spec.out
stack_spec.o: stack_spec.cpp ../src/stack.hpp
	$(CC) -c stack_spec.cpp
clean:
	rm -f *.o *.out

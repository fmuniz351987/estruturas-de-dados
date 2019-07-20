CC = g++ -Wall -pedantic

spec/stack_spec.out: spec/stack_spec.cpp lib/stack.hpp
	$(CC) spec/stack_spec.cpp -o spec/stack_spec.out

clean:
	rm -f spec/*.o spec/*.out

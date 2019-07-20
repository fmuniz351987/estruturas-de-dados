CC = g++ -Wall -pedantic

all: spec/queue_spec.out spec/stack_spec.out spec/list_spec.out spec/hash_spec.out

spec/stack_spec.out: spec/stack_spec.cpp lib/stack.hpp
	$(CC) spec/stack_spec.cpp -o spec/stack_spec.out
spec/queue_spec.out: spec/queue_spec.cpp lib/queue.hpp
	$(CC) spec/queue_spec.cpp -o spec/queue_spec.out
spec/list_spec.out: spec/list_spec.cpp lib/list.hpp
	$(CC) spec/list_spec.cpp -o spec/list_spec.out
spec/hash_spec.out: spec/hash_spec.cpp lib/list.hpp lib/hash.hpp
	$(CC) spec/hash_spec.cpp -o spec/hash_spec.out

clean:
	rm -f spec/*.o spec/*.out

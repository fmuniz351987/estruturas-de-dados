#include <iostream>
#include "../lib/queue.hpp"

typedef Queue<int> IntQueue;

int tests = 0;
int errors = 0;

bool assert(bool expr) {
    tests++;
    if (!expr) {
        errors++;
        return false;
    }
    return true;
}

void test_init_empty() {
    IntQueue queue;
    assert(queue.get_size() == 0);
    assert(queue.empty());
}

void test_enqueue() {
    IntQueue queue;
    for (int i = 0; i < 100; i++) {
        queue.enqueue(new int(i));
    }
    assert(queue.get_size() == 100);
    assert(!queue.empty());
}

void test_dequeue() {
    IntQueue queue;
    int *removed;
    for (int i = 0; i < 100; i++) {
        queue.enqueue(new int(i));
    }
    for (int i = 0; i < 20; i++) {
        removed = queue.dequeue();
        assert(i == *removed);
        delete removed;
    }
    assert(queue.get_size() == 80);
}

void test_clear() {
    IntQueue queue;
    for (int i = 0; i < 100; i++)
        queue.enqueue(new int(i));
    queue.clear();
    assert(queue.get_size() == 0);
}

void test_string_cast() {
    IntQueue queue;
    for (int i = 0; i < 10; i++)
        queue.enqueue(new int(i));
    std::cout << std::string(queue) << std::endl;
    std::cout << queue << std::endl;
}

void print_results() {
    std::clog << "Total tests: " << tests << std::endl;
    std::clog << "Total errors: " << errors << std::endl;
}

int main() {
    test_init_empty();
    test_enqueue();
    test_dequeue();
    test_clear();
    test_string_cast();
    print_results();
    return 0;
}

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
    IntQueue iq;
    assert(iq.get_size() == 0);
    assert(iq.empty());
}

void test_enqueue() {
    IntQueue iq;
    for (int i = 0; i < 100; i++) {
        iq.enqueue(new int(i));
    }
    assert(iq.get_size() == 100);
    assert(!iq.empty());
}

void test_dequeue() {
    IntQueue iq;
    int *removed;
    for (int i = 0; i < 100; i++) {
        iq.enqueue(new int(i));
    }
    for (int i = 0; i < 20; i++) {
        removed = iq.dequeue();
        assert(i == *removed);
        delete removed;
    }
    assert(iq.get_size() == 80);
}

void test_clear() {
    IntQueue iq;
    for (int i = 0; i < 100; i++)
        iq.enqueue(new int(i));
    iq.clear();
    assert(iq.get_size() == 0);
}

void test_string_cast() {
    IntQueue iq;
    for (int i = 0; i < 10; i++)
        iq.enqueue(new int(i));
    std::cout << std::string(iq) << std::endl;
    std::cout << iq << std::endl;
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

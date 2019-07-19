#include <iostream>
#include "../src/stack.hpp"

typedef stack::Stack<int> IntStack;

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
    IntStack istack;
    assert(istack.empty());
}

void test_push_items() {
    IntStack istack;
    for (int i = 0; i < 100; i++) 
        istack.push(new int(i));
    assert(istack.get_size() == 100);
}

void test_pop_empty() {
    IntStack istack;
    assert(istack.pop() == nullptr);
    assert(istack.get_size() == 0);
}

void test_push_and_pop() {
    IntStack istack;
    int *removido;
    for (int i = 0; i < 100; i++) {
        istack.push(new int(i));
    }
    for (int i = 0; i < 20; i++) {
        removido = istack.pop();
        assert(*removido == 99 - i);
        delete removido;
    }
    assert(*istack.peek() == 79);
    assert(istack.get_size() == 80);
}

void print_results() {
    std::clog << "Total tests: " << tests << std::endl;
    std::clog << "Total errors: " << errors << std::endl;
}

int main() {
    test_init_empty();
    test_push_items();
    test_pop_empty();
    test_push_and_pop();

    print_results();
    return 0;
}

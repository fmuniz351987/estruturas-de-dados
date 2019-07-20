#include <iostream>
#include "../lib/stack.hpp"

typedef Stack<int> IntStack;

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
    IntStack stack;
    assert(stack.empty());
}

void test_push_items() {
    IntStack stack;
    for (int i = 0; i < 100; i++) 
        stack.push(new int(i));
    assert(stack.get_size() == 100);
}

void test_pop_empty() {
    IntStack stack;
    assert(stack.pop() == nullptr);
    assert(stack.get_size() == 0);
}

void test_push_and_pop() {
    IntStack stack;
    int *removido;
    for (int i = 0; i < 100; i++) {
        stack.push(new int(i));
    }
    for (int i = 0; i < 20; i++) {
        removido = stack.pop();
        assert(*removido == 99 - i);
        delete removido;
    }
    assert(*stack.peek() == 79);
    assert(stack.get_size() == 80);
}

void test_string_cast() {
    IntStack stack;
    for (int i = 0;i < 10; i++) 
        stack.push(new int(i));
    std::cout << std::string(stack) << std::endl;
    std::cout << stack << std::endl;
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
    test_string_cast();
    print_results();
    return 0;
}

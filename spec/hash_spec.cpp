#include <iostream>
#include <string>
#include "../lib/hash.hpp"

typedef Hash<int, unsigned> IntHash;

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

void print_results() {
    std::clog << "Total tests: " << tests << std::endl;
    std::clog << "Total errors: " << errors << std::endl;
}

void test_init() {
    IntHash hash(10);
    tests++;
}

void test_hash_function() {
    IntHash hash(10);
    assert(hash.hash(123019) == 9);
}

void test_insertion() {
    IntHash hash(10);
    hash.insert(new int(11), 101);
    assert(hash.get_size() == 1);
}

void test_multiple_insertions() {
    IntHash hash(10);
    for (unsigned i = 0; i < 100; i++)
        hash.insert(new int(i), i);
    assert(hash.get_size() == 100);
}

void test_search() {
    IntHash hash(10);
    for (unsigned i = 0; i < 100; i++)
        hash.insert(new int(i), i);
    for (int i: {10, 11, 17, 25, 99})
        assert(*hash.search(i) == i);
}

void test_remove() {
    IntHash hash(10);
    for (unsigned i = 0; i < 100; i++) 
        hash.insert(new int(i), i);
    for (unsigned i: {11, 20, 37})
        assert(*hash.remove(i) == (int) i);
    assert(hash.get_size() == 97);
}

int main() {
    test_init();
    test_hash_function();
    test_insertion();
    test_search();
    test_remove();
    print_results();
    return 0;
}

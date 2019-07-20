#include <iostream>
#include <string>
#include "../lib/list.hpp"

typedef List<int> IntList;

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
    IntList list;
    assert(list.empty());
}


void test_insert_items() {
    IntList list;
    for (int i = 0; i < 100; i++)
        list.insert(new int(i));
    assert(list.get_size() == 100);
    assert(!list.empty());
}

void test_search_items() {
    IntList list;
    for (int i = 0; i < 100; i++)
        list.insert(new int(i));
    assert(*list.search(73)->item == 73);
}

void test_remove_items() {
    IntList list;
    IntList::Node *node;
    for (int i = 0; i < 100; i++)
        list.insert(new int(i));
    for (int i = 0; i < 100; i+=10) {
        node = list.search(i);
        list.remove(node);
        delete node->item;
        delete node;
    }
    assert(list.get_size() == 90);
}

void test_remove_empty() {
    IntList list;
    IntList::Node *node;

    list.insert(new int(10));
    assert(list.get_size() == 1);

    node = list.search(0);
    node = list.remove(node);
    assert(node != nullptr);
    assert(list.get_size() == 0);

    assert(list.remove(node) == nullptr);
    assert(list.get_size() == 0);

    delete node->item;
    delete node;
}

void test_string_cast() {
    IntList list;
    std::clog << std::string(list) << std::endl;
    for (int i = 0; i < 10; i++)
        list.insert(new int (i));
    std::clog << std::string(list) << std::endl;
    std::clog << list << std::endl;
}

void print_results() {
    std::clog << "Total tests: " << tests << std::endl;
    std::clog << "Total errors: " << errors << std::endl;
}

void test_insert_with_keys() {
    IntList list;
    list.insert(new int(100), 11);
    list.insert(new int(20), 99);
    list.insert(new int(2000), 1);
    assert(*list.search(11)->item == 100);
}

int main() {
    test_init_empty();
    test_insert_items();
    test_search_items();
    test_remove_items();
    test_remove_empty();
    test_string_cast();
    test_insert_with_keys();
    print_results();
    return 0;
}

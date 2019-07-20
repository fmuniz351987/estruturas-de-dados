#pragma once
#include <iostream>
#include <string>

template <typename ItemType> class Stack {
    class Node {
        friend class Stack<ItemType>;
        ItemType *item = nullptr;
        Node *next = nullptr;

        Node () {}

        Node(ItemType *item) {
            this->item = item;
        }
    };

    unsigned size = 0;
    Node *head = new Node;

    public:
    Stack() {}

    ~Stack() {
        clear();
        delete head;
    }

    bool empty() {
        return size == 0;
    }

    unsigned get_size() {
        return size;
    }

    void push(ItemType *item) {
        Node *node = new Node(item);
        node->next = head->next;
        head->next = node;
        size++;
    }

    ItemType *pop() {
        if (empty()) return nullptr;
        Node *node = head->next;
        ItemType *item = node->item;
        head->next = node->next;
        delete node;
        size--;
        return item;
    }

    ItemType *peek() {
        if (empty()) return nullptr;
        return head->next->item;
    }

    void clear() {
        ItemType *item;
        while(!empty()) {
            item = pop();
            delete item;
        }
    }

    operator std::string() {
        std::string s;
        if(empty()) return s;
        Node *node = head->next;
        for(unsigned i = 0; i < size - 1; i++) {
            s += std::to_string(*node->item);
            s += ' ';
            node = node->next;
        }
        s += std::to_string(*node->item);
        return s;
    }
};

template <typename T> std::ostream& operator<<(std::ostream& out, Stack<T>& s) {
    return out << std::string(s);
}

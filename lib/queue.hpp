#pragma once
#include <iostream>

template <typename ItemType> class Queue {
    class Node {
        friend class Queue<ItemType>;
        ItemType *item = nullptr;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node() {}

        Node(ItemType *item) {
            this->item = item;
        }

        Node *get_next() {return next;}
        Node *get_prev() {return prev;}
        void set_next(Node* next) {this->next = next;}
        void set_prev(Node* prev) {this->prev = prev;}
    };

    Node *sentinel = new Node;
    unsigned size = 0;

    public:
    Queue() {
        sentinel->set_next(sentinel);
        sentinel->set_prev(sentinel);
    }

    ~Queue() {
        clear();
        delete sentinel;
    }

    bool empty() {
        return size == 0;
    }

    unsigned get_size() {
        return size;
    }

    void enqueue(ItemType *item) {
        Node *last = sentinel->get_prev(),
                       *new_node = new Node(item);
        new_node->set_prev(last);
        new_node->set_next(sentinel);
        sentinel->set_prev(new_node);
        last->set_next(new_node);
        size++;
    }

    ItemType *dequeue() {
        if (empty()) return nullptr;
        Node *removed_node = sentinel->get_next();
        ItemType *removed_item = removed_node->item;
        sentinel->set_next(removed_node->get_next());
        sentinel->get_next()->set_prev(sentinel);
        delete removed_node;
        size--;
        return removed_item;
    }

    ItemType *peek() {
        return sentinel->get_next();
    }

    void clear() {
        ItemType *item;
        while (!empty()) {
            item = dequeue();
            delete item;
        }
    }

    operator std::string() {
        std::string s;
        Node *node = sentinel->next;
        for(unsigned i = 0; i < size - 1; i++) {
            s += std::to_string(*node->item);
            s += ' ';
            node = node->next;
        }
        s += std::to_string(*node->item);
        return s;
    }
};

template <typename T> std::ostream& operator<<(std::ostream& out, Queue<T>& q) {
    return out << std::string(q);
}

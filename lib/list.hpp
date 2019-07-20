#pragma once
#include <iostream>
#include <string>

template <typename ItemType> class List {
    public:

    class Node {
        friend class List<ItemType>;
        Node *next = nullptr;
        Node *prev = nullptr;
        List<ItemType> *list;

        public:
        ItemType *item = nullptr;

        Node() {}

        Node(ItemType *item) {
            this->item = item;
        }

        Node *get_next() {return next;}
        Node *get_prev() {return prev;}
        void set_next(Node* next) {this->next = next;}
        void set_prev(Node* prev) {this->prev = prev;}
    };

    private:

    Node* create_node(ItemType *item = nullptr) {
        Node* new_node = new Node(item);
        new_node->list = this;
        return new_node;
    }

    unsigned size = 0;
    Node *sentinel = create_node();

    public:

    List() {
        sentinel->set_next(sentinel);
        sentinel->set_prev(sentinel);
    }

    ~List() {
        clear();
        delete sentinel;
    }

    bool empty() {
        return size == 0;
    }

    unsigned get_size() {return size;}

    void swap(Node* node1, Node* node2) {
        Node aux = *node1;
        node1->item = node2->item;
        node1.set_prev(node2->get_prev());
        node1.set_next(node2->get_next());

        node2->item = aux.item;
        node2->set_prev(aux.get_prev());
        node2->set_next(aux.get_next());
    }

    Node* search(unsigned id) {
        Node *node = sentinel;
        if (empty()) return nullptr;
        id %= size;
        for (unsigned i = 0; i <= id; i++) {
            node = node->get_next();
        }
        return node;
    }

    Node *insert(ItemType *item) {
        Node *new_node = create_node(item),
             *last = sentinel->get_prev();
        sentinel->set_prev(new_node);
        new_node->set_next(sentinel);
        new_node->set_prev(last);
        last->set_next(new_node);
        size++;
        return new_node;
    }

    Node *remove(Node* node) {
        if (node->list != this) return nullptr;
        Node *next, *prev;
        prev = node->get_prev();
        next = node->get_next();
        prev->set_next(next);
        next->set_prev(prev);
        size--;
        node->list = nullptr;
        return node;
    }

    void clear() {
        Node *aux;
        while (!empty()) {
            aux = search(0);
            remove(aux);
            delete aux->item;
            delete aux;
        }
    }

    operator std::string() {
        std::string s;
        if(empty()) return s;
        Node *node = sentinel->next;
        for (unsigned i = 0; i < size - 1; i++) {
            s += std::to_string(*node->item);
            s += ' ';
            node = node->next;
        }
        s += std::to_string(*node->item);
        return s;
    }
};

template <typename T> std::ostream& operator<<(std::ostream& out, List<T>& list) {
    return out << std::string(list);
}

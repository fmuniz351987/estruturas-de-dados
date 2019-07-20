#pragma once
#include <iostream>
#include <string>

template <typename ItemType, typename KeyType = unsigned> class List {
    public:

    class Node {
        friend class List<ItemType>;
        Node *next = nullptr;
        Node *prev = nullptr;
        List<ItemType> *list;

        public:
        ItemType *item = nullptr;
        KeyType key;

        Node() {}

        Node(ItemType *item, KeyType key) {
            this->item = item;
            this->key = key;
        }

        Node *get_next() {return next;}
        Node *get_prev() {return prev;}
        void set_next(Node* next) {this->next = next;}
        void set_prev(Node* prev) {this->prev = prev;}
    };

    private:

    Node* create_node(ItemType *item = nullptr) {
        Node* new_node = new Node(item, current_key);
        new_node->list = this;
        return new_node;
    }

    Node* create_node(ItemType *item, KeyType key) {
        Node* new_node = new Node(item, key);
        new_node->list = this;
        return new_node;
    }

    unsigned size = 0;
    unsigned current_key = 0;
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

    Node *search(KeyType key) {
        Node *curr = first();
        while (curr != sentinel) {
            if (curr->key == key) return curr;
            curr = curr->get_next();
        }
        return nullptr;
    }

    Node *first() {
        return sentinel->get_next();
    }

    Node *last() {
        return sentinel->get_prev();
    }

    Node *insert(ItemType *item, KeyType key) {
        if (search(key)) return nullptr;    //falha se o node já existe
        Node *new_node = create_node(item, key),
             *old_last = this->last();
        sentinel->set_prev(new_node);
        new_node->set_next(sentinel);
        new_node->set_prev(old_last);
        old_last->set_next(new_node);
        size++;
        if (key > current_key) 
            current_key = key; 
        current_key++;
        return new_node;
    }

    Node *insert(ItemType *item) {
        return insert(item, current_key);
    }

    Node *update(ItemType *item, KeyType key) {
        Node *node = search(key);
        if (!node) return nullptr;  // falha se o node não existe
        delete node->item;
        node->item = item;
        return node;
    }

    Node *remove(KeyType key) {
        Node *node = search(key);
        if (!node) return nullptr;
        return remove(node);
    }

    Node *remove(Node *node) {
        if (node->list != this) return nullptr; // o node não pertence a essa lista; nada a fazer.
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
            aux = first();
            remove(aux);
            delete aux->item;
            delete aux;
        }
    }

    operator std::string() {
        std::string s;
        if(empty()) return s;
        Node *curr = first();
        for (unsigned i = 0; i < size - 1; i++) {
            s += std::to_string(*curr->item);
            s += ' ';
            curr = curr->next;
        }
        s += std::to_string(*curr->item);
        return s;
    }
};

template <typename T, typename K> std::ostream& operator<<(std::ostream& out, List<T, K>& list) {
    return out << std::string(list);
}

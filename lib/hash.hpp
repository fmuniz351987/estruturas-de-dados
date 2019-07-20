#pragma once
#include <iostream>
#include <string>
#include "list.hpp"

template <typename ItemType, typename KeyType> class Hash {
    typedef List<ItemType, KeyType> HashList;
    typedef typename HashList::Node Node;

    unsigned table_size;
    unsigned size = 0;
    HashList *lists;

    HashList *search_list(KeyType key) {
        return &(lists[hash(key)]);
    }

    public:
    Hash(unsigned table_size) {
        this->table_size = table_size;
        lists = new List<ItemType, KeyType>[table_size];
    }

    ~Hash() {
        delete[] lists;
    }

    unsigned get_size() {return size;}

    unsigned hash(KeyType key) {
        return key % table_size;
    }

    void insert(ItemType *item, KeyType key) {
        search_list(key)->insert(item, key);
        size++;
    }

    ItemType *search(KeyType key) {
        Node *node;
        node = search_list(key)->search(key);
        if (!node) return nullptr;
        return node->item;
    }

    ItemType *remove(KeyType key) {
        Node *node = search_list(key)->remove(key);
        ItemType *item;
        if (!node) return nullptr;    
        item = node->item;
        size--;
        delete node;
        return item;
    }
};

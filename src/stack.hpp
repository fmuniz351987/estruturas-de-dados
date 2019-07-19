#pragma once

namespace stack {
    template <typename ItemType> class Node {
        template <typename U> friend class Stack;

        ItemType *item = nullptr;
        Node<ItemType> *next = nullptr;

        Node () {}

        Node(ItemType *item) {
            this->item = item;
        }
    };

    template <typename ItemType> class Stack {
        unsigned size = 0;
        Node<ItemType> *head = new Node<ItemType>;

        public:
        Stack() {}

        ~Stack() {
            ItemType *item;

            while(!empty()) {
                item = pop();
                delete item;
            }
            delete head;
        }

        bool empty() {
            return size == 0;
        }

        unsigned get_size() {
            return size;
        }

        void push(ItemType *item) {
            Node<ItemType> *node = new Node<ItemType>(item);
            node->next = head->next;
            head->next = node;
            size++;
        }

        ItemType *pop() {
            if (empty()) return nullptr;
            Node<ItemType> *node = head->next;
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
    };
}

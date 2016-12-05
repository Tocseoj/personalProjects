//
//  LinkedList.hpp
//  DataStructures
//
//  Created by Joseph Marshall on 12/1/16.
//  Copyright © 2016 Joseph Marshall. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

template<typename T>
class LinkedList {
    class Node {
    public:
        Node(T _value, Node *_next = NULL) : value(_value), next(_next) {}
        void insert (T _value) {
            next = new Node(_value, next);
        }
        T value;
        Node *next;
    };
    
    Node *root;
public:
    LinkedList() : root(0) {}
    ~LinkedList() {
        Node *n = root;
        while (n != NULL) {
            Node *temp = n;
            n = n->next;
            delete temp;
        }
    }
    // Return if list is empty
    bool empty() const {
        return root == NULL;
    }
    // Returns size
    int size() const {
        int i = 0;
        Node *n = root;
        while (n != NULL) {
            i++;
            n = n->next;
        }
        return i;
    }
    // Inserts front without pos specified else after node at pos
    void insert(T _value, Node *pos = 0) {
        if (pos == 0)
            root = new Node(_value, root);
        else
            pos->insert(_value);
    }
    // Removes value if in list
    void remove(T _value) {
        if (root == NULL) return;
        if (_value == root->value) {
            Node *temp = root;
            root = root->next;
            delete temp;
            return;
        }
        Node *n = root;
        while (n->next != NULL && n->next->value != _value)
            n = n->next;
        if (n->next == NULL) return;
        Node *temp = n->next;
        n->next = n->next->next;
        delete temp;
    }
    // Overrides first node with valueOld to valueNew
    void replace(T _valueOld, T _valueNew) {
        Node *n = root;
        while (n != NULL) {
            if (n->value == _valueOld) {
                n->value = _valueNew;
                return;
            }
            n = n->next;
        }
    }
    // Returns the kth element's value
    T element_k(int k) {
        int i = 0;
        Node *n = root;
        while (n != NULL && i < k) {
            n = n->next;
            i++;
        }
        if (n == NULL) return NULL;
        return n->value;
    }
    
    int list(T *elements) {
        int i = 0;
        Node *n = root;
        while (n != NULL) {
            elements[i++] = n->value;
            n = n->next;
        }
        return i;
    }
};

#endif /* LinkedList_hpp */

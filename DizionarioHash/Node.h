//
// Node 2.0
// Created by Gianfranco
//

#ifndef NODE_NODE_H
#define NODE_NODE_H

#include <iostream>

template<typename T>
class Node {
public:
    Node() {
        next = nullptr;
    };

    Node(T value) {
        this->value = value;
        next = nullptr;
    }

    ~Node() = default;

    T getValue() {
        return value;
    }

    Node *getNext() {
        return next;
    }

    T setValue(T value) {
        this->value = value;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    void printNode() {
        std::cout << "Value: " << value << "\tAddress: " << this << "\tNext: " << next << "\n";
    }

private:
    T value;
    Node *next;
};

#endif //NODE_NODE_H

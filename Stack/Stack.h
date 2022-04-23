#ifndef PILAPTR_PILAPTR_H
#define PILAPTR_PILAPTR_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(T value) {
        this->value = value;
        next = nullptr;
    }

    T getValue() {
        return value;
    }
};

template<typename T>
class Stack {
public:
    Stack();

    bool isEmpty();

    T readStack();
    void pop();
    void push(T value);
    void printStack();

private:
    int size;
    Node<T> *head;
};

#endif //PILAPTR_PILAPTR_H

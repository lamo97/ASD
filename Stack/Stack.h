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
    Stack() {
        size = 0;
        head = nullptr;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    T readStack() {
        return head->value; //resituisce il valore dell'elemento in testa
    }

    void pop() {
        head = head->next;  //testa punta al secondo elemento, escludendo il primo
        size--; //decrementa la dimensione della pila
    }

    void push(T value) {
        Node<T> *toAdd = new Node<T>(value);    //crea il nodo da aggiungere
        toAdd->next = head; //il nuovo nodo punta al vecchio nodo in testa
        head = toAdd;   //il puntatore di testa punta al nuovo nodo
        size++; //incrementa la dimensione della pila
    }

    void printStack() {
        Node<T> *toPrint = head;
        for (int i = 0; i < size; i++) {
            std::cout << i+1 << ": " << toPrint->value << " " << toPrint << "\n";
            toPrint = toPrint->next;
        }
        std::cout << "---------------------\n";
    }

private:
    int size;
    Node<T> *head;
};

#endif //PILAPTR_PILAPTR_H

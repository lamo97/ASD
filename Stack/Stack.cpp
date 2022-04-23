#include "Stack.h"

template<typename T>
Stack<T>::Stack() {
    size = 0;
    head = nullptr;
}

template<typename T>
bool Stack<T>::isEmpty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
T Stack<T>::readStack() {
    return head->value; //resituisce il valore dell'elemento in testa
}

template<typename T>
void Stack<T>::pop() {
    head = head->next;  //testa punta al secondo elemento, escludendo il primo
    size--; //decrementa la dimensione della pila
}

template<typename T>
void Stack<T>::push(T value) {
    auto *toAdd = new Node<T>(value);    //crea il nodo da aggiungere
    toAdd->next = head; //il nuovo nodo punta al vecchio nodo in testa
    head = toAdd;   //il puntatore di testa punta al nuovo nodo
    size++; //incrementa la dimensione della pila
}

template<typename T>
void Stack<T>::printStack() {
    Node<T> *toPrint = head;
    for (int i = 0; i < size; i++) {
        std::cout << i+1 << ": " << toPrint->value << " " << toPrint << "\n";
        toPrint = toPrint->next;
    }
    std::cout << "---------------------\n";
}


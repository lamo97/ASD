#include "Queue.h"

template<typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
T Queue<T>::leggiValore() {
    if (isEmpty() == true) {
        cout << "La coda e vuota!" << endl;
        return NULL;
    }

    return head->data;
}

template<typename T>
void Queue<T>::inserisci(T data) {
    auto *toAdd = new Node<T>(data);

    if (size == 0) {
        //coda vuota
        head = toAdd;
        tail = toAdd;
    } else {
        //coda con n>0 elementi
        tail->next = toAdd;
        tail = toAdd;
    }

    size++;
}

template<typename T>
void Queue<T>::inserisci(Node<T> *toAdd) {
    if (size == 0) {
        //coda vuota
        head = toAdd;
        tail = toAdd;
    } else {
        //coda con n>0 elementi
        getTail()->next = toAdd;
        tail = toAdd;
    }

    size++;
}

template<typename T>
void Queue<T>::cancella() {
    if (isEmpty() == true) {
        cout << "La coda e vuota!" << endl;
        return;
    }

    Node<T> *toDelete = head;
    head = head->next;
    size--;

    delete toDelete;
}

template<typename T>
bool Queue<T>::isEmpty() {
    if (size == 0)
        return true;
    else
        return false;
}

template<typename T>
void Queue<T>::stampaCoda() {
    Node<T> *toPrint = head;

    for (int i = 0; i < size; i++) {
        cout << i << " - " << "Value: " << toPrint->data << "\tAddress: "
             << toPrint << "\tNext: " << toPrint->next << endl;

        toPrint = toPrint->next;
    }

    cout << "---" << endl;

    delete toPrint;
}

template<typename T>
void Queue<T>::stampaValori() {
    Node<T> *toPrint = head;

    for (int i = 0; i < size; i++) {
        cout << toPrint->data << " ";
        toPrint = toPrint->next;
    }

    cout << "\n---" << endl;

    delete toPrint;
}

template<typename T>
int Queue<T>::getSize() {
    return size;
}

template<typename T>
Node<T>* Queue<T>::getHead() {
    return head;
}

template<typename T>
Node<T>* Queue<T>::getTail() {
    return tail;
}

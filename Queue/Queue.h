// Implementazione della struttura coda con puntatori

#ifndef CODAPTR_QUEUE_H
#define CODAPTR_QUEUE_H

#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = nullptr;
    }

    ~Node() = default;
};

template<typename T>
class Queue {
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Queue() = default;

    //legge il valore in testa
    T leggiValore() {
        if (isEmpty() == true) {
            cout << "La coda e vuota!" << endl;
            return NULL;
        }

        return head->data;
    }

    void inserisci(T data) {
        Node<T> *toAdd = new Node<T>(data);

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

    void inserisci(Node<T> *toAdd) {
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

    //elimina l'elemento in testa
    void cancella() {
        if (isEmpty() == true) {
            cout << "La coda e vuota!" << endl;
            return;
        }

        Node<T> *toDelete = head;
        head = head->next;
        size--;

        delete toDelete;
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    //stampa valori ed indirizzi della coda
    void stampaCoda() {
        Node<T> *toPrint = head;

        for (int i = 0; i < size; i++) {
            cout << i << " - " << "Value: " << toPrint->data << "\tAddress: "
                 << toPrint << "\tNext: " << toPrint->next << endl;

            toPrint = toPrint->next;
        }

        cout << "---" << endl;

        delete toPrint;
    }

    //stampa i valori nella coda in ordine
    void stampaValori() {
        Node<T> *toPrint = head;

        for (int i = 0; i < size; i++) {
            cout << toPrint->data << " ";
            toPrint = toPrint->next;
        }

        cout << "\n---" << endl;

        delete toPrint;
    }

    int getSize() {
        return size;
    }

    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

#endif //CODAPTR_QUEUE_H

// Implementazione della struttura coda con puntatori

#ifndef CODAPTR_QUEUE_H
#define CODAPTR_QUEUE_H

#include <iostream>

using namespace std;

template<typename T>
struct QNode {
    T data;
    QNode *next;

    QNode(T data) {
        this->data = data;
        next = nullptr;
    }

    ~QNode() = default;
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
        QNode<T> *toAdd = new QNode<T>(data);

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

    void inserisci(QNode<T> *toAdd) {
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

        QNode<T> *toDelete = head;
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

    bool appartiene(T data) {
        QNode<T> *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->data == data) {
                return true;
            } else {
                temp = temp->next;
            }
        }
        return false;
    }

    //stampa valori ed indirizzi della coda
    void stampaCoda() {
        QNode<T> *toPrint = head;

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
        QNode<T> *toPrint = head;

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

    QNode<T> *getHead() {
        return head;
    }

    QNode<T> *getTail() {
        return tail;
    }

private:
    QNode<T> *head;
    QNode<T> *tail;
    int size;
};

#endif //CODAPTR_QUEUE_H

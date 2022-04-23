#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

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
    Queue();
    ~Queue() = default;


    T leggiValore();    //legge il valore in testa

    void inserisci(T data); //inserisce un elemento in coda
    void inserisci(Node<T> *toAdd); //inserisce un nodo in coda
    void cancella();    //elimina l'elemento in testa

    bool isEmpty();
    void stampaCoda();  //stampa valori ed indirizzi della coda (funzione di test)
    void stampaValori();    //stampa i valori nella coda in ordine

    int getSize();
    Node<T> *getHead();
    Node<T> *getTail();

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

#endif //QUEUE_QUEUE_H

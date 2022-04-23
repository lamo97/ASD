#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

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
class LinkedList {
public:
    LinkedList();

    ~LinkedList() = default;

    void inserisci(T data, int position);   //inserisce l'elemento in una posizione specifica
    void inserisci(T data); //inserisce l'elemento in coda alla lista
    void cancella(int position);    //rimuove l'elemento dalla posizione specificata
    T leggiValore(int position);

    bool appartiene(Node<T> *toCheck);  //controlla l'apparteneza di uno specifico nodo alla lista
    bool isEmpty();

    void stampaLista(); //stampa posizioni, valori e indirizzi (funzione di test)
    void stampaValori();    //stampa solo i valori

    LinkedList<T> *concatena(LinkedList<T> l2); //concatena due liste

    int getSize();
    Node<T> *getFirst();
    Node<T> *getLast();
    Node<T> *getNode(int position);

private:
    Node<T> *head;  //puntatore di testa
    int size;       //dimensione della lista
};


#endif //LINKEDLIST_LINKEDLIST_H

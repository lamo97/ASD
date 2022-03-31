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
    //costruttore;
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() = default;

    //inserisce l'elemento in una posizione specifica
    void inserisci(T data, int position) {
        Node<T> *toAdd = new Node<T>(data);

        //controllo sul parametro posizione
        if (position > size || position < 0) {
            cout << "Posizione non valida!" << endl;
            delete toAdd;
            return;
        }

        if (size == 0 && position == 0) {
            //lista vuota, aggiunta in testa
            head = toAdd;
        } else if (size == position) {
            //aggiunta in coda
            getNode(size - 1)->next = toAdd;
        } else if (size > 0 && position < size && position > 0) {
            //aggiunta tra altri elementi esistenti
            toAdd->next = getNode(position);
            getNode(position - 1)->next = toAdd;
        }

        size++;
    }

    //inserisce l'elemento in coda alla lista
    void inserisci(T data) {
        Node<T> *toAdd = new Node<T>(data);

        if (size == 0) {
            //lista vuota, aggiunta in testa
            head = toAdd;
        } else {
            getNode(size - 1)->next = toAdd;
        }

        size++;
    }

    void cancella(int position) {
        //controllo sul parametro posizione
        if (position >= size || position < 0) {
            cout << "Posizione non valida!" << endl;
            return;
        }

        if (size == 0) {
            cout << "Lista vuota!" << endl;
            return;
        }

        if (position == 0) {
            Node<T> *toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            Node<T> *toDelete = getNode(position);
            getNode(position-1)->next = getNode(position)->next;
            delete toDelete;
        }

        size--;
    }

    T leggiValore(int position) {
        if (position >= size || position < 0) {
            cout << "Posizione non valida!" << endl;
            return NULL;
        }

        return getNode(position)->data;
    }

    bool appartiene(Node<T> *toCheck) {
        for (int i = 0; i < size; i++) {
            if (toCheck == getNode(i))
                return true;
        }

        return false;
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    //stampa posizioni, valori e indirizzi
    void stampaLista() {
        Node<T> *temp;
        for (int i = 0; i < size; i++) {
            temp = getNode(i);
            cout << i << " - " << "Value: " << temp->data << "\tAddress: " << temp << "\tNext: " << temp->next << endl;
        }
        cout << "---" << endl;

        temp = temp->next;  /*passaggio necessario, altrimenti l'ultimo nodo nella lista
                            viene cancellato, visto che temp punta ancora a quello*/
        delete temp;
    }

    //stampa solo i valori
    void stampaValori() {
        Node<T> *temp;
        for (int i = 0; i < size; i++) {
            temp = getNode(i);
            cout << temp->data << " ";
        }
        cout << "\n---" << endl;

        temp = temp->next;  /*passaggio necessario, altrimenti l'ultimo nodo nella lista
                            viene cancellato, visto che temp punta ancora a quello*/
        delete temp;
    }

    int getSize() {
        return size;
    }

    Node<T> *getFirst() {
        return head;
    }

    Node<T> *getLast() {
        return getNode(size - 1);
    }

    Node<T> *getNode(int position) {
        if (position > size || position < 0) {
            cout << "Posizione non valida!" << endl;
            return nullptr;
        }

        Node<T> *temp = head;
        //scorre la lista fino alla posizione desiderata, copiando il nodo in temp
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }

        return temp;
    }

private:
    Node<T> *head;  //puntatore di testa
    int size;
};


#endif //LINKEDLIST_LINKEDLIST_H

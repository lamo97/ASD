//
// LinkedList 2.0
// Created by Gianfranco
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList {
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    //controlla se la lista è vuota
    bool emptyList() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    //restituisce il valore di un elemento ad una data posizione
    T readValue(int position) {
        if (size == 0) {
            std::cout << "La lista e vuota! \n\n";
        } else if (position > size || position < 0) {
            std::cout << "Posizione non valida! \n\n";
        } else if (position == 0) {
            return head->getValue();
        } else {
            return (getNode(position)->getValue());
        }
    }

    void modifyValue(T value, int position) {
        if (size == 0) {
            std::cout << "La lista e vuota! \n\n";
        } else if (position > size || position < 0) {
            std::cout << "Posizione non valida! \n\n";
        } else if (position == 0) {
            return head->setNext(value, position);
        } else {
            return (getNode(position)->setValue(value, position));
        }
    }

    void add(T value, int position) {
        Node<T> *toAdd = new Node<T>(value);

        if (size == 0 && position == 0) {
            //primo elemento
            head = toAdd;
        } else if (position > size || position < 0) {
            std::cout << "Posizione non valida! \n\n";
        } else if (position == size && position != 0) {
            //aggiunta in coda
            getNode(position - 1)->setNext(toAdd);
        } else if (size > 0 && position == 0) {
            //aggiunta in testa
            toAdd->setNext(head);
            head = toAdd;
        } else {
            //aggiunta tra elementi già esistenti (aggiunta+spostamento)
            Node<T> *prev = new Node<T>();
            prev = getNode(position - 1);   //prende il nodo precedente a quello da aggiungere
            toAdd->setNext(getNode(position));      //il nuovo nodo punta a quello nella posizione che lui prenderà
            prev->setNext(toAdd);                   //il nodo precedente punta al nuovo nodo
        }

        size++;
    }

    void cancel(int position) {
        if (size == 0) {
            std::cout << "La lista e vuota! \n\n";
        } else if (position == 0 && size == 1) {
            //rimozione ultimo elemento in lista
            delete getNode(position);
            head = nullptr;
        } else {
            //rimozione da coda o dal centro
            Node<T> *prev = new Node<T>();
            Node<T> *temp = new Node<T>();

            prev = getNode(position - 1);   //prende il nodo precedente a quello da aggiungere
            temp = getNode(position);   //prende il nodo da elminare
            prev->setNext(temp->getNext()); //connette il precedente al successivo del nodo da eleminare

            delete temp;
        }

        size--;
    }

    void printList() {
        if (size == 0) {
            std::cout << "Lista vuota!\n";
        } else {
            Node<T> *toPrint = new Node<T>();
            toPrint = head;

            for (int i = 0; i < size; i++) {
                std::cout << i << ": ";
                toPrint->printNode();
                toPrint = toPrint->getNext();
            }
        }

        std::cout << "---\n\n";
    }

private:
    int size;
    Node<T> *head;

    Node<T> *getNode(int position) {
        Node<T> *temp = new Node<T>();
        temp = head;

        //scorre i nodi fino alla posizione desiderata
        for (int i = 0; i < position; i++) {
            temp = temp->getNext();
        }

        return temp;
    }
};

#endif //LINKEDLIST_LINKEDLIST_H

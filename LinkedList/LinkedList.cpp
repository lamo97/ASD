#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<typename T>
void LinkedList<T>::inserisci(T data, int position) {
    auto *toAdd = new Node<T>(data);

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

template<typename T>
void LinkedList<T>::inserisci(T data) {
    Node<T> *toAdd = new Node<T>(data);

    if (size == 0) {
        //lista vuota, aggiunta in testa
        head = toAdd;
    } else {
        getNode(size - 1)->next = toAdd;
    }

    size++;
}

template<typename T>
void LinkedList<T>::cancella(int position) {
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

template<typename T>
T LinkedList<T>::leggiValore(int position) {
    if (position >= size || position < 0) {
        cout << "Posizione non valida!" << endl;
        return NULL;
    }

    return getNode(position)->data;
}

template<typename T>
bool LinkedList<T>::appartiene(Node<T> *toCheck) {
    for (int i = 0; i < size; i++) {
        if (toCheck == getNode(i))
            return true;
    }

    return false;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    if (size == 0)
        return true;
    else
        return false;
}

template<typename T>
void LinkedList<T>::stampaLista() {
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

template<typename T>
void LinkedList<T>::stampaValori() {
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

template<typename T>
LinkedList<T>* LinkedList<T>::concatena(LinkedList<T> l2){
    auto *merged = new LinkedList<T>();
    for(int i = 0; i< this->size; i++){
        merged->inserisci(this->leggiValore(i));
    }

    for(int i = 0; i< l2.size; i++){
        merged->inserisci(l2.leggiValore(i));
    }

    return merged;
}

template<typename T>
int LinkedList<T>::getSize() {
    return size;
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() {
    return head;
}

template<typename T>
Node<T>* LinkedList<T>::getLast() {
    return getNode(size - 1);
}

template<typename T>
Node<T> *LinkedList<T>::getNode(int position) {
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


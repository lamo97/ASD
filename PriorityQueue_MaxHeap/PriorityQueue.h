#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <iostream>

#define MAX_SIZE 20

using namespace std;

template<typename T>
struct Node {
    T data;
    int priority;

    Node() {
        priority = 0;
    }

    Node(T data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    //overloading dell'operatore = di assegnazione relativo a Node
    Node<T> &operator=(const Node<T> toCopy) {
        this->data = toCopy.data;
        this->priority = toCopy.priority;

        return *this;
    }
};

template<typename T>
class PriorityQueue {
public:
    PriorityQueue() {
        size = 0;
        maxSize = 20;
        heap = new Node<T>[maxSize];
    }

    PriorityQueue(int maxSize) {
        size = 0;
        this->maxSize = maxSize;
        heap = new Node<T>[maxSize];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void inserisci(Node<T> toAdd) {
        if (size + 1 > maxSize) {
            cout << "Dimensione massima superata!" << endl;
            return;
        }

        //inserimento come foglia nel binary heap
        heap[size + 1] = toAdd;
        size++;

        //cout << "Stampa: " << heap[size].data << ", " << heap[size].priority << endl;

        //l'heap viene riordinato
        Node<T> temp;
        int i = size;
        while (i > 1 && heap[i].priority > heap[i / 2].priority) {
            temp = heap[i];
            //cout << "Temp: " << temp.data << ", " << temp.priority << endl;
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    void inserisci(T data, int priority) {
        if (size + 1 > maxSize) {
            cout << "Dimensione massima superata!" << endl;
            return;
        }

        //inserimento come foglia nel binary heap
        heap[size + 1].data = data;
        heap[size + 1].priority = priority;
        size++;

        //l'heap viene riordinato
        Node<T> temp;
        int i = size;
        while (i > 1 && heap[i].priority > heap[i / 2].priority) {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    void rimuovi() {
        if (isEmpty() == true) {
            cout << "La coda e vuota!" << endl;
            return;
        }

        heap[1]=heap[size];
        size--;

        Node<T> temp;
        int i = 0;
        int pos = 1;

        while(heap[pos].priority < heap[2*pos].priority && 2*pos<= size
        || heap[pos].priority < heap[2*pos+1].priority && 2*pos+1<= size){
            //figlio di sinistra > di quello di destra
            if(heap[2*pos].priority > heap[2*pos+1].priority){
                temp = heap[pos];  //copia il vecchio nodo padre
                heap[pos] = heap[2*pos];    //il nodo padre divente il figlio di sinistra
                heap[2*pos] = temp; //il figlio di sinistra diventa il vecchio nodo padre
            } else if(heap[2*pos].priority < heap[2*pos+1].priority){
                //figlio di destra > di quello di sinistra
                temp = heap[pos];  //copia il vecchio nodo padre
                heap[pos] = heap[2*pos+1];    //il nodo padre divente il figlio di destra
                heap[2*pos+1] = temp; //il figlio di destra diventa il vecchio nodo padre
            }
        }
    }

    //overloading dell'operatore == per il confronto tra code
    bool operator==(const PriorityQueue<T> queue) {
        if (this->size == queue.size) {
            for (int i = 1; i < size; i++) {
                if (this->heap[i].data != queue.heap[i].data && this->heap[i].priority != queue.heap[i].priority)
                    return false;
            }
        } else {
            return false;
        }

        return true;
    }

    bool contenuto(Node<T> toCheck) {
        for (int i = 0; i < size; i++) {
            if (heap[i].data == toCheck.data && heap[i].priority == toCheck.priority)
                return true;
        }
        return false;
    }

    bool contenuto(T toCheck) {
        for (int i = 0; i < size; i++) {
            if (heap[i].data == toCheck && heap[i].priority == toCheck)
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

    void stampaCoda() {
        for (int i = 1; i <= size; i++) {
            cout << i << ":\tData: " << heap[i].data << "\tPriorita: " << heap[i].priority;
            if(2*i <= size){
                cout << "\tLeft: " << 2*i << " ";
            }
            if(2*i+1 <= size){
                cout << "\tRight: " << 2*i+1;
            }
            cout << endl;
        }
    }

private:
    Node<T> *heap;
    int size;
    int maxSize;
};


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

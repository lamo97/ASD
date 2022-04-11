#ifndef MAXPRIORITYQUEUE_MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_MAXPRIORITYQUEUE_H

#include <iostream>

#define MAX_SIZE 20

using namespace std;

template<typename T>
struct QNode {
    T data;
    int priority;

    QNode() {
        priority = -1;
    }

    QNode(T data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    //overloading dell'operatore = di assegnazione relativo a QNode
    QNode<T> &operator=(const QNode<T> toCopy) {
        this->data = toCopy.data;
        this->priority = toCopy.priority;

        return *this;
    }

    bool operator==(QNode<T> toCompare) {
        if (this->data == toCompare.data && this->priority == toCompare.priority) {
            return true;
        } else {
            return false;
        }
    }
};

template<typename T>
class MaxPriorityQueue {
public:
    MaxPriorityQueue() {
        size = 0;
        maxSize = 20;
        heap = new QNode<T>[maxSize];
    }

    MaxPriorityQueue(int maxSize) {
        size = 0;
        this->maxSize = maxSize;
        heap = new QNode<T>[maxSize];
    }

    void inserisci(QNode<T> toAdd) {
        if (size + 1 > maxSize) {
            cout << "Dimensione massima superata!" << endl;
            return;
        }

        //inserimento come foglia nel binary heap
        heap[size + 1] = toAdd;
        size++;

        //cout << "Stampa: " << heap[size].data << ", " << heap[size].priority << endl;

        //l'heap viene riordinato
        QNode<T> temp;
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
        QNode<T> temp;
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

        heap[1] = heap[size];
        size--;

        QNode<T> temp;
        int i = 0;
        int pos = 1;

        while (heap[pos].priority < heap[2 * pos].priority && 2 * pos <= size
               || heap[pos].priority < heap[2 * pos + 1].priority && 2 * pos + 1 <= size) {
            //figlio di sinistra > di quello di destra
            if (heap[2 * pos].priority > heap[2 * pos + 1].priority) {
                temp = heap[pos];  //copia il vecchio nodo padre
                heap[pos] = heap[2 * pos];    //il nodo padre divente il figlio di sinistra
                heap[2 * pos] = temp; //il figlio di sinistra diventa il vecchio nodo padre
            } else if (heap[2 * pos].priority < heap[2 * pos + 1].priority) {
                //figlio di destra > di quello di sinistra
                temp = heap[pos];  //copia il vecchio nodo padre
                heap[pos] = heap[2 * pos + 1];    //il nodo padre divente il figlio di destra
                heap[2 * pos + 1] = temp; //il figlio di destra diventa il vecchio nodo padre
            }
        }
    }

    QNode<T> leggiTesta() {
        if (isEmpty() == true) {
            cout << "La coda e vuota!" << endl;
            QNode<T> temp(-1, -1);
            return temp;
        }
        return heap[1];
    }

    bool contenuto(QNode<T> toCheck) {
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

    //stampa dell'heap con riferimenti ai nodi
    void stampaHeap() {
        for (int i = 1; i <= size; i++) {
            cout << i << ":\tData: " << heap[i].data << "\tPriorita: " << heap[i].priority;
            if (2 * i <= size) {
                cout << "\tLeft: " << 2 * i << " ";
            }
            if (2 * i + 1 <= size) {
                cout << "\tRight: " << 2 * i + 1;
            }
            cout << endl;
        }
    }

    //stampa della coda
    void stampaCoda() {
        MaxPriorityQueue<T> temp;
        temp.size = this->size;

        for(int i = 1; i<=size; i++){
            temp.heap[i] = this->heap[i];
        }

        int i = 1;
        while(temp.size>0){
            cout << i << ": " << temp.leggiTesta().data << endl;
            temp.rimuovi();
            i++;
        }

        /*MaxPriorityQueue<T> *temp = new MaxPriorityQueue<T>();
        temp = &*this;


        for (int i = 1; i <= temp.size; i++) {
            cout << i << ": " << temp.leggiTesta().data << endl;
            temp.rimuovi();
        }

        //delete temp;*/
        cout << "-------" << endl;
    }

    //overloading dell'operatore == per il confronto tra code
    bool operator==(const MaxPriorityQueue<T> queue) {
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

private:
    QNode<T> *heap;
    int size;
    int maxSize;
};


#endif //MAXPRIORITYQUEUE_MAXPRIORITYQUEUE_H

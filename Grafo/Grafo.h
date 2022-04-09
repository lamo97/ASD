/* Implementazione di un grafo orientato con lista di adiacenza.
 * Il nodo avrà ID pari alla sua posizione nel vettore; le informazioni
 * sul nodo stesso come eventuali dati che può contenere vengono memorizzate
 * nella posizione 0 della relativa lista di adiacenza.
 * Tutte le posizioni successive, invece, sono riservate agli altri verici adiacenti.
 * Quando viene aggiunto un vertice adiacente, questo sarà una copia del verice originale.
 * La classe permette di definire archi con o senza etichetta ed archi
 * pesati e non.
 * Il peso dell'arco (u,v) e la sua etichetta vengono memorizzati con la copia del nodo
 * v al momento dell'aggiunta nella lista di adiacenza.
 */

#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

#define SIZE 20

#include "LinkedList.h"

template<typename T>
struct GNode {
    int id;
    T data;
    int weight;
    string label;

    GNode() {
        id = 0;
        weight = 0;
    }

    //nodo non etichettato con arco non pesato
    GNode(int id) {
        this->id = id;
        weight = 0;
    }

    //nodo non etichettato con arco pesato
    GNode(int id, int weight) {
        this->id = id;
        this->weight = weight;
    }


    string toString(){
        string res = "ID: ";
        res = res + to_string(id);

        if(data != "")
            res = res + "\tData: " + data;

        if(weight > 0)
            res = res + "\tWeight: " + to_string(weight);

        if(label != "")
            res = res + "\tLabel: " + label;

        return res;
    }
};

template<typename T>
class Grafo{
public:
    Grafo();
    bool isEmpty();
    void inserisciNodo(GNode<T> *node);
    void inserisciArco(GNode<T> *from, GNode<T> to, int weight = 0, string label = "");
    void cancellaNodo(GNode<T> *node);
    void cancellaArco(GNode<T> *from, GNode<T> to);
    LinkedList<GNode<T>*> adiacenti(int id);
    bool esisteNodo(GNode<T> node);
    bool esisteArco(GNode<T> *from, GNode<T> to);
    //legginodo
    //scrivinodo
    void stampaDFS(GNode<T> *node, int* visitati = nullptr,bool flag = false);
    void stampaGrafo();

private:
    LinkedList<GNode<T>*> arrayVertici[SIZE];
    int vertici;
};

#endif //GRAFO_GRAFO_H

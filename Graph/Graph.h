#include <iostream>
#include "LinkedList.h"

struct Edge {
    int destination;
    int weight;

    Edge(int destination, int weight = 1) {
        this->destination = destination;
        this->weight = weight;
    }
};

template<typename T>
struct Vertex {
    int id;
    string label;
    T data;
    LinkedList<Edge *> edgeList;

    //tutti i vertici vengono inzializzati a -1, per indicare l'assenza del verice prima dell'aggiunta
    Vertex(int id = -1, string label = "", T data = NULL) {
        this->id = id;
        this->label = label;
        this->data = data;
    }

    void printVertex() {
        string vertex = "";
        vertex = vertex + to_string(id);
        if (!label.empty())
            vertex = vertex + "\t" + label;

        cout << vertex << endl;
    }
};

template<typename T>
class Graph {
public:
    Graph(int size) {
        if (size <= 0) {
            cout << "Dimesione non valida! Inizializzazione con size = 20..." << endl;
            this->size = 20;
            vertexArray = new Vertex<T>[size]();
        }
        this->size = size;
        vertexArray = new Vertex<T>[size]();
    }

    void inserisciNodo(Vertex<T> toAdd) {
        if (esisteNodo(toAdd.id) == true) {
            cout << "Esiste già un nodo con id " << toAdd.id << endl;
            return;
        }

        vertexArray[toAdd.id] = toAdd;
    }

    void inserisciNodo(int id, string label = "", T data = NULL) {
        if (esisteNodo(id) == true) {
            cout << "Esiste già un nodo con id " << id << endl;
            return;
        }

        Vertex<T> toAdd(id, label, data);
        vertexArray[toAdd.id] = toAdd;
    }

    void inserisciArco(int from, Edge *toAdd) {
        int to = toAdd->destination;

        if (esisteNodo(from) == false || esisteNodo(to) == false) {
            cout << "Uno dei due nodi non appartiene al grafo!" << endl;
            return;
        }

        if (esisteArco(from, to)) {
            cout << "Esiste già un arco analogo!" << endl;
            return;
        }

        vertexArray[from].edgeList.inserisci(toAdd);
    }

    void inserisciArco(int from, int to, int weight = 1) {
        Edge *toAdd = new Edge(to, weight);

        if (esisteNodo(from) == false || esisteNodo(to) == false) {
            cout << "Uno dei due nodi non appartiene al grafo!" << endl;
            return;
        }

        if (esisteArco(from, to)) {
            cout << "Esiste gia un arco analogo!" << endl;
            return;
        }

        vertexArray[from].edgeList.inserisci(toAdd);
    }

    void cancellaNodo(int id) {
        if (esisteNodo(id) == false) {
            cout << "Il nodo non appartiene al grafo!" << endl;
            return;
        }

        //rimozione dalle liste di adiacenza di altri nodi
        for (int i = 0; i < size; i++) {
            //se il vertice esite ed ha vicini, avvia il contollo
            if (vertexArray[i].id != -1 && vertexArray[i].edgeList.getSize() > 0) {
                //itera tra tutti i vicini in cerca di adiacenze
                for (int j = 0; j < vertexArray[i].edgeList.getSize(); j++) {
                    if (vertexArray[i].edgeList.leggiValore(j)->destination == id)
                        vertexArray[i].edgeList.cancella(j);
                }
            }
        }

        //eliminzaione vertice dall'array
        vertexArray[id] = Vertex<T>();
    }

    void cancellaArco(int from, int to) {
        if (esisteNodo(from) == false || esisteNodo(to) == false) {
            cout << "Uno dei due nodi non appartiene al grafo!" << endl;
            return;
        }

        if (esisteArco(from, to) == false) {
            cout << "L'arco specificato non esiste!" << endl;
            return;
        }

        for (int i = 0; i < vertexArray[from].edgeList.getSize(); i++) {
            if (vertexArray[from].edgeList.leggiValore(i)->destination == to) {
                vertexArray[from].edgeList.cancella(i);
                return;
            }
        }
    }

    LinkedList<Edge *> adiacenti(int id) {
        if (esisteNodo(id) == false) {
            cout << "Il nodo non appartiene al grafo!" << endl;
            LinkedList<Edge *> empty;
            return empty;
        } else if (vertexArray[id].edgeList.getSize() == 0) {
            cout << "Il nodo non ha vicini!" << endl;
            LinkedList<Edge *> empty;
            return empty;
        }

        return vertexArray[id].edgeList;
    }

    //controlla l'esistenza di un nodo dato il suo ID
    bool esisteNodo(int id) {
        if (id < 0 || id >= size) {
            cout << "Dimensione non valida!" << endl;
            return false;
        }

        if (vertexArray[id].id != -1)
            return true;
        else
            return false;
    }

    bool esisteArco(int from, int to) {
        if (esisteNodo(from) == false || esisteNodo(to) == false) {
            return false;
        }

        int listSize = vertexArray[from].edgeList.getSize();    //dimensione della lista di adiacenza
        if (listSize == 0) {
            //se la dimensione della lista di adiacenza è pari a 0 allora non esiste nessun arco
            return false;
        }

        //se la lista non è vuota si controlla il contenuto
        for (int i = 0; i < listSize; i++) {
            if (vertexArray[from].edgeList.leggiValore(i)->destination == to) {
                return true;
            }
        }

        return false;
    }

    bool isEmpty() {
        for (int i = 0; i < size; i++) {
            if (vertexArray[i].id != -1)
                return false;
        }
        return true;
    }

    void tmpPrint() {
        for (int i = 0; i < size; i++) {
            if (vertexArray[i].id != -1) {
                cout << vertexArray[i].id;
            }
            if (vertexArray[i].label.empty() == false) {
                cout << "\t" << vertexArray[i].label;
            }
            if (vertexArray[i].edgeList.getSize() > 0) {
                cout << "\t->\t";
                for (int j = 0; j < vertexArray[i].edgeList.getSize(); j++) {
                    cout << vertexArray[i].edgeList.leggiValore(j)->destination << " w: "
                         << vertexArray[i].edgeList.leggiValore(j)->weight << ", ";
                }
            }
            if (vertexArray[i].id != -1) {
                cout << endl;
            }
        }
        cout << endl;
    }

private:
    Vertex<T> *vertexArray;
    int size;
};

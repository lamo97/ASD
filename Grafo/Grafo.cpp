#include <iostream>
#include "Grafo.h"

using namespace std;

template<typename T>
Grafo<T>::Grafo() {
    vertici = 0;
}

template<typename T>
bool Grafo<T>::isEmpty() {
    if (vertici == 0)
        return true;
    else
        return false;
}

template<typename T>
void Grafo<T>::inserisciNodo(GNode<T> *node) {
    if (node->id < 1 || node->id > SIZE) {
        cout << "ID/posizione vettore non valida!" << endl;
        return;
    } else if (esisteNodo(*node) == true) {
        cout << "Esiste gia un nodo con questo specifico ID!" << endl;
        return;
    } else {
        int position = node->id;
        /*inserimento delle informazioni del nodo identificato dall'indice pari a ID
        nella posizione 0 della lista di adiacenza*/
        arrayVertici[position].inserisci(node, 0);
        vertici++;
    }
}

template<typename T>
void Grafo<T>::inserisciArco(GNode<T> *from, GNode<T> to, int weight, string label) {
    if (esisteNodo(*from) == false || esisteNodo(to) == false) {
        cout << "Uno o entrambi i nodi non sono presenti nel grafo!" << endl;
        return;
    }

    if (esisteArco(from, to) == true) {
        cout << "Esiste gia un arco da u a v!" << endl;
        return;
    }

    //crea una copia del nodo nel quale entra l'arco ed inserisce le eventuali informazioni
    GNode<T> *n2 = &to;
    n2->weight = weight;
    n2->label = label;

    int position = from->id;

    //inserisce la copia del nodo nella lista di adiacenza
    arrayVertici[position].inserisci(n2);
}

template<typename T>
void Grafo<T>::cancellaNodo(GNode<T> *node) {
    if (esisteNodo(*node) == false) {
        cout << "Il nodo non e presente nel grafo!" << endl;
        return;
    }

    for (int i = 1; i < SIZE; i++) {
        if (arrayVertici[i].isEmpty() == false && arrayVertici[i].leggiValore(0)->id == node->id) {
            while (arrayVertici[i].isEmpty() == false) {
                arrayVertici[i].cancella(0);
            }
        }
    }

    //rimozione dell'elemento dalla lista di adiacenza per ogni vertice
    for (int i = 1; i < SIZE; i++) {
        /* se la lista degli adiacenti è vuota, prima posizione compresa,
        * la posizone nel vettore  vuota e l'elemento non è li */
        if (arrayVertici[i].getSize() != 0) {
            for (int j = 1; j < arrayVertici[i].getSize(); j++) {
                if (arrayVertici[i].leggiValore(j)->id == node->id) {
                    arrayVertici[i].cancella(j);
                }
            }
        }
    }

    vertici--;
}

template<typename T>
void Grafo<T>::cancellaArco(GNode<T> *from, GNode<T> to) {
    if (esisteNodo(*from) == false || esisteNodo(to) == false) {
        cout << "Uno o entrambi i nodi non sono presenti nel grafo!" << endl;
        return;
    }

    if (esisteArco(from, to) == false) {
        cout << "Non esiste nessun arco da u a v!" << endl;
        return;
    }

    int position = from->id;
    for (int i = 1; i < SIZE; i++) {
        if (arrayVertici[position].leggiValore(i)->id == to.id) {
            //rimuove l'elemento dalla lista di adiacenza del primo nodo
            arrayVertici[position].cancella(i);
            return;
        }
    }
}

template<typename T>
bool Grafo<T>::esisteNodo(GNode<T> node) {
    int position = node.id;

    /*una posizione dell'array è vuota se la corrispondente lista è vuota
    (quindi non esiste nemmeno il nodo con ID pari all'indice dell'array)*/
    if (arrayVertici[position].isEmpty() == true)
        return false;
    else
        return true;
}

template<typename T>
bool Grafo<T>::esisteArco(GNode<T> *from, GNode<T> to) {
    //controlla l'esistenza di entrambi i nodi
    if (esisteNodo(*from) == false || esisteNodo(to) == false) {
        cout << "Uno o entrambi i nodi non sono presenti nel grafo!" << endl;
        return false;
    }

    //posizione del nodo da cui parte l'arco nel vettore
    int position = from->id;

    //cerca l'arco nella lista corrispondente del nodo indicato, scandendo tutti gli elementi della lista
    for (int i = 1; i < arrayVertici[position].getSize(); i++) {
        if (arrayVertici[position].leggiValore(i)->id == to.id)
            return true;
    }

    return false;
}

template<typename T>
LinkedList<GNode<T> *> Grafo<T>::adiacenti(int id) {
    LinkedList<GNode<T> *> vicini;

    //controlla che il nodo abbia vicini, altrimenti restituisce una lista vuota
    if (arrayVertici[id].getSize() <= 1) {
        cout << "Il nodo non ha vicini!" << endl;
        return vicini;
    }

    /*copia gli elementi dalla lista nella posizione del nodo a quella dei vicini
    tralasciando il primo elemento che contiene informazioni sul nodo stesso*/
    for (int i = 1; i < arrayVertici[id].getSize(); i++) {
        vicini.inserisci(arrayVertici[id].leggiValore(i));
    }

    return vicini;
}

template<typename T>
void Grafo<T>::stampaGrafo() {
    cout << "------------------------------------------------------" << endl;
    for (int i = 1; i < SIZE; i++) {
        if (arrayVertici[i].isEmpty() == false) {
            cout << arrayVertici[i].leggiValore(0)->toString();
            for (int j = 1; j < arrayVertici[i].getSize(); j++) {
                cout << "\t" << arrayVertici[i].leggiValore(j)->toString() << endl;
            }
            cout << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}

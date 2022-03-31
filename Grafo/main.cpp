#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"

int main() {
    Grafo<string> g1;
    cout << "isEmpty: " << g1.isEmpty() << endl;

    auto *n1 = new GNode<string>(1);
    g1.inserisciNodo(n1);


    auto *n2 = new GNode<string>(2);
    g1.inserisciNodo(n2);

    auto *n3 = new GNode<string>(3);
    g1.inserisciNodo(n3);

    g1.inserisciArco(n1,*n2, 10, "test");
    g1.inserisciArco(n1,*n1, 5, "test");
    g1.inserisciArco(n1, *n3, 20);
    g1.inserisciArco(n3, *n2);
    g1.inserisciArco(n2,*n1);
    g1.inserisciArco(n3,*n1);
    g1.stampaGrafo();

    g1.cancellaNodo(n2);
    g1.cancellaArco(n3,*n1);
    g1.stampaGrafo();

    LinkedList<GNode<string>*> vicini = g1.adiacenti(1);
    cout << vicini.leggiValore(0)->id << endl;
}

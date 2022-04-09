#include <iostream>
#include "Graph.h"

int main() {
    Graph<int> g1(20);
    cout << "isEmpty: " << g1.isEmpty() << endl;

    g1.inserisciNodo(0, "primo");

    Vertex<int> v1(1, "secondo");
    g1.inserisciNodo(v1);
    /*
    g1.tmpPrint();
    cout << "Test esiste arco: " << g1.esisteArco(0,1) << endl;

    g1.inserisciArco(0,1);
    cout << "Test esiste arco: " << g1.esisteArco(0,1) << endl;

    cout << "Eliminazione 1: " << endl;
    g1.cancellaNodo(1);
    g1.tmpPrint();

    g1.inserisciArco(0,1);
    cout << "Test esiste arco: " << g1.esisteArco(0,1) << endl;
    */
    /*
    g1.inserisciNodo(2, "terzo");
    g1.inserisciNodo(3, "quarto");
    g1.inserisciNodo(4, "quinto");

    g1.inserisciArco(0,1);
    g1.inserisciArco(0,2);
    g1.inserisciArco(1,3);
    g1.inserisciArco(2,1);
    g1.inserisciArco(3,2);
    g1.inserisciArco(3,4);
    g1.inserisciArco(4,2);

    g1.tmpPrint();

    cout << "Esiste arco 0,2: " << g1.esisteArco(0,2) << endl;
    cout << "Rimozione arco 0,2..." << endl;
    g1.cancellaArco(0,2);
    cout << "Esiste arco 0,2: " << g1.esisteArco(0,2) << endl;
    g1.visitaDFS();

    //g1.cancellaArco(0,1);
    //g1.inserisciArco(0,4);
    g1.visitaDFS();
    g1.visitaBFS();
    */

    g1.inserisciNodo(0);
    g1.inserisciNodo(1);
    g1.inserisciNodo(2);
    g1.inserisciNodo(3);
    g1.inserisciNodo(4);
    g1.inserisciNodo(5);

    g1.inserisciArco(0,1);
    g1.inserisciArco(0,2);
    g1.inserisciArco(0,3);
    g1.inserisciArco(1,3);
    g1.inserisciArco(1,4);
    g1.inserisciArco(2,4);
    g1.inserisciArco(3,1);

    g1.visitaDFS();
    g1.visitaBFS();

}

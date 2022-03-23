#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> l;
    l.inserisci(10);
    l.inserisci(20);
    l.inserisci(30,2);
    l.inserisci(15,1);

    l.stampaValori();
    l.stampaLista();
    l.cancella(1);
    l.stampaValori();
    l.stampaLista();

    LinkedList<string> l2;
    l2.inserisci("Francesco");
    l2.inserisci("Luca");
    l2.inserisci("Marco");
    l2.stampaValori();
    l2.cancella(1);
    l2.stampaValori();
}

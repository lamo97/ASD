#include <iostream>
#include <typeinfo>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> c1;
    c1.inserisci(10);
    c1.inserisci(20);
    c1.inserisci(30);
    c1.stampaCoda();
    c1.stampaCoda();
    c1.stampaValori();
    c1.stampaValori();
    c1.cancella();
    c1.stampaValori();
    c1.cancella();
    c1.cancella();
    c1.stampaValori();
    return 0;
}

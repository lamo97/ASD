#include <iostream>
#include "Set.h"

int main() {
    Set<int> i1;
    i1.inserisci(10);
    i1.inserisci(20);
    i1.inserisci(30);
    i1.inserisci(40);

    cout << "i1: ";
    i1.stampaInsieme();

    Set<int> i3;
    i3.inserisci(15);
    i3.inserisci(25);
    i3.inserisci(30);
    i3.inserisci(45);

    cout << "i3: ";
    i3.stampaInsieme();

    Set<int> unione;
    unione = unione.unione(i1, i3);
    cout << "Unione: ";
    unione.stampaInsieme();

    Set<int> intersezione;
    intersezione = intersezione.intersezione(i1,i3);
    cout << "Intersezione: ";
    intersezione.stampaInsieme();

    Set<int> diff;
    diff = diff.differenza(i1,i3);
    cout << "Differenza: ";
    diff.stampaInsieme();

    struct Test {
        int data;
    };

    Test *t1 = new Test();
    t1->data = 10;

    Test *t2 = new Test();
    t1->data = 20;

    Test *t3 = new Test();
    t1->data = 30;

    Test *t4 = new Test();
    t1->data = 40;

    Set<Test *> i2;
    i2.inserisci(t1);
    i2.inserisci(t2);

    Set<Test *> i4;
    i4.inserisci(t2);
    i4.inserisci(t3);
    i4.inserisci(t4);

    Set<Test *> iJoin;
    cout << "i2: ";
    i2.stampaInsieme();
    cout << "i4: ";
    i4.stampaInsieme();

    iJoin = iJoin.unione(i2, i4);
    cout << "Unione: ";
    iJoin.stampaInsieme();

    Set<Test*> iInters;
    iInters = iInters.intersezione(i2,i4);
    cout << "Intersezione: ";
    iInters.stampaInsieme();

    Set<Test*> df;
    df = df.differenza(i2,i4);
    cout << "Diffrenza: ";
    df.stampaInsieme();

}

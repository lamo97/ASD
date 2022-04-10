#include <iostream>
#include "NTree.h"

int main() {
    NTree<int> t1;
    auto *r1 = new TNode<int>(1);
    auto *n2 = new TNode<int>(2);
    auto *n3 = new TNode<int>(3);
    auto *n4 = new TNode<int>(4);
    auto *n5 = new TNode<int>(5);
    auto *n6 = new TNode<int>(6);
    auto *n7 = new TNode<int>(7);
    auto *n8 = new TNode<int>(8);
    auto *n9 = new TNode<int>(9);

    t1.inserisciRadice(r1);
    t1.inserisciFiglio(r1,n2);
    t1.inserisciFiglio(r1,n3);
    t1.inserisciFiglio(r1,n4);

    t1.inserisciFiglio(n2,n5);
    t1.inserisciFiglio(n2,n6);

    t1.inserisciFiglio(n6,n7);

    t1.inserisciFiglio(n3,n8);

    t1.inserisciFratello(n8,n9);

    t1.stampaPrevisita();
    t1.stampaPostvisita();

    //t1.cancellaNodo(n3);
    //t1.stampaPrevisita();

    //t1.cancellaNodo(n2);
    //t1.stampaPrevisita();

    cout << "Primo Figlio: " << t1.getPrimoFiglio(r1)->data << endl;
    cout << "Ultimo Fratello(4): " << t1.isUltimoFratello(n4) << endl;
    cout << "Ultimo Fratello(3): " << t1.isUltimoFratello(n3) << endl;
    cout << "Prossimo Fratello(3): " << t1.getProssimoFratello(n3)->data << endl;


    TNode<int> *n10 = new TNode<int>(10);
    t1.inserisciFiglio(n7,n10);

    cout << "Profondita(8): " << t1.profonditaNodo(n8) << endl;
    cout << "Profondita(7): " << t1.profonditaNodo(n7) << endl;
    cout << "Profondita(10): " << t1.profonditaNodo(n10) << endl;

    cout << "Stampa per livello(4): ";
    t1.stampaLivello(t1.getRoot(), 4);
    cout << endl;

    cout << "Profondita Massima: " << t1.profonditaMassima() << endl;
    t1.cancellaNodo(n10);
    cout << "Profondita Massima: " << t1.profonditaMassima() << endl;

    struct Test{
        int data;
    };

    NTree<Test*> t2;
    Test *s1 = new Test();
    Test *s2 = new Test();

    auto s11 = new TNode<Test*>(s1);
    TNode<Test*>* s22 = new TNode<Test*>(s2);

    t2.inserisciRadice(s11);
    t2.inserisciFiglio(s11, s22);
    t2.stampaPrevisita();
}

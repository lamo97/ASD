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
}

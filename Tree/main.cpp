#include <iostream>
#include "Tree.cpp"
#include "Tree.h"
int main() {
    auto *n1 = new TNode<int>(1);
    auto *n11 = new TNode<int>(2);
    auto *n12 = new TNode<int>(3);
    auto *n2 = new TNode<int>(10);
    auto *n21 = new TNode<int>(11);
    auto *n22 = new TNode<int>(12);

    Tree<int> t1;
    t1.inserisciRadice(n1);
    t1.inserisciFiglio(t1.getRoot(), n11);
    t1.inserisciFiglio(t1.getRoot(), n12);

    t1.inserisciFiglio(n11, n2);
    t1.inserisciFiglio(n11, n21);
    t1.inserisciFiglio(n12, n22);

    t1.stampaPrevisita(t1.getRoot());
    cout << "Postvisita: " << endl;
    t1.stampaPostvisita(t1.getRoot());
    cout << "Invisita: " << endl;
    t1.stampaInvisita(t1.getRoot());
}

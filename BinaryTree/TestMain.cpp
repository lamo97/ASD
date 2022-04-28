#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<int> b1;

    auto *n = new TNode<int>(1);
    auto *n1 = new TNode<int>(10);
    auto *n2 = new TNode<int>(11);
    auto *n3 = new TNode<int>(12);
    auto *n4 = new TNode<int>(13);
    auto *n5 = new TNode<int>(20);
    auto *n6 = new TNode<int>(21);

    b1.inserisciRadice(n);
    b1.inserisciSinistro(b1.getRoot(), n1);
    b1.inserisciDestro(b1.getRoot(),n5);
    b1.inserisciSinistro(n1,n2);
    b1.inserisciDestro(n1,n3);
    b1.inserisciSinistro(n2,n4);
    b1.inserisciSinistro(n5,n6);
    //b1.stampaInorder(b1.getRoot());
    //cout << "Rimozione sottoalbero" << endl;

    //b1.cancellaSottoalbero(n1);
    //b1.stampaInorder(b1.getRoot());

    auto *n0 = new TNode<int>(90);
    auto *n10 = new TNode<int>(100);
    auto *n20 = new TNode<int>(110);
    auto *n30 = new TNode<int>(120);
    auto *n40 = new TNode<int>(130);
    auto *n50 = new TNode<int>(200);
    auto *n60 = new TNode<int>(210);

    BinaryTree<int> b2;
    b2.inserisciRadice(n0);
    b2.inserisciSinistro(n0, n10);
    b2.inserisciDestro(n0,n20);
    b2.inserisciSinistro(n10,n30);
    b2.inserisciDestro(n10,n40);
    b2.inserisciSinistro(n20,n50);
    b2.inserisciDestro(n20,n60);

    //b2.stampaInorder(b2.getRoot());

    BinaryTree<int> unione;
    unione = unione.unisciAlberi(b1,b2);
    unione.stampaInorder(unione.getRoot());

    cout << "\nTest: " << endl;
    BinaryTree<int> test;
    test.inserisciNodo(500);
    test.inserisciNodo(510);
    test.inserisciNodo(520);
    test.inserisciNodo(530);
    test.stampaInorder(test.getRoot());
    cout << "Altezza: " << test.altezza(test.getRoot()) << endl;
    cout << "Proprio: ";
    cout << test.proprio(test.getRoot()) << endl;

    cout << "Proprio: ";
    cout << b2.proprio(b2.getRoot()) << endl;

    BinaryTree<int> testComp;

    TNode<int> *t0 = new TNode<int>(0);
    TNode<int> *t1 = new TNode<int>(1);
    TNode<int> *t2 = new TNode<int>(2);
    TNode<int> *t3 = new TNode<int>(3);
    TNode<int> *t4 = new TNode<int>(4);

    testComp.inserisciRadice(t0);
    testComp.inserisciSinistro(t0, t1);
    testComp.inserisciDestro(t0,t2);
    testComp.inserisciSinistro(t1,t3);
    testComp.inserisciDestro(t1,t4);

    cout << "testComp completo?: " << testComp.isCompleto(testComp.getRoot()) << endl;
    testComp.cancellaSottoalbero(t2);
    cout << "testComp completo?: " << testComp.isCompleto(testComp.getRoot()) << endl;

/*
    cout << "Preorder: " << endl;
    b1.stampaPreorder(b1.getRoot());

    cout << "Inorder: " << endl;
    b1.stampaInorder(b1.getRoot());

    cout << "Postorder: " << endl;
    b1.stampaPostorder(b1.getRoot());

    */
}

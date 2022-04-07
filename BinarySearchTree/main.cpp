#include "BST.h"
#include <iostream>

using namespace std;

int main(){
	BST<string> b1;
	b1.insert("r", 10);

	b1.insert("a", 1);
	b1.insert("b", 11);
	b1.insert("c", 2);
	b1.insert("d", 14);
	b1.insert("e", 12);
	b1.insert("f", 15);
	b1.insert("g", 13);

	//b1.preorderPrint(b1.getRoot());

	cout << "Minimo: ";
	b1.min(b1.getRoot())->printNode();

	cout << "Massimo: ";
	b1.max(b1.getRoot())->printNode();

	cout << endl;

	cout << "Albero: " << endl;
	b1.preorderPrint(b1.getRoot());

	cout << endl;

	cout << "Predecessore di 14:\t";
	b1.predecessor(14)->printNode();

	cout << "Predecessore di 10:\t";
	b1.predecessor(10)->printNode();

	cout << "Successore di 10:\t";
	b1.successor(10)->printNode();

	cout << "Successore di 13:\t";
	b1.successor(13)->printNode();

	/*
	cout << "Eliminazione di 13" << endl;
	b1.remove(13);
	b1.preorderPrint(b1.getRoot());

	cout << endl;

	cout << "Eliminazione di 1" << endl;
	b1.remove(1);
	b1.preorderPrint(b1.getRoot());

	cout << endl;

	cout << "Eliminazione di 11" << endl;
	b1.remove(11);
	b1.preorderPrint(b1.getRoot());

	cout << endl;

	cout << "Eliminazione di 10" << endl;
	b1.remove(10);
	b1.preorderPrint(b1.getRoot());

	cout << "Eliminazione di 14" << endl;
	b1.remove(14);
	b1.preorderPrint(b1.getRoot());

	cout << endl;

	cout << "Eliminazione di 10" << endl;
	b1.remove(10);
	b1.preorderPrint(b1.getRoot());

	cout << "Eliminazione di 2" << endl;
	b1.remove(2);
	b1.preorderPrint(b1.getRoot());

	cout << "Eliminazione di 12" << endl;
	b1.remove(12);
	b1.preorderPrint(b1.getRoot());

	cout << "Eliminazione di 2" << endl;
	b1.remove(2);
	b1.preorderPrint(b1.getRoot());
*/
	/*cout << "Eliminazione di 2" << endl;
	b1.remove(2);
	b1.preorderPrint(b1.getRoot());*/


	BST<string> b2;
	b2.insert("r", 30);
	b2.insert("a", 40);
	b2.insert("b", 12);
	b2.insert("c", 18);
    b2.insert("c", 11);
	b2.insert("d", 55);
	b2.insert("d", 72);
    b2.insert("d", 54);

	cout << "Stampa preordine di b2:" << endl;
	b2.preorderPrint(b2.getRoot());

    cout << "Stampa postordine di b2:" << endl;
    b2.postorderPrint(b2.getRoot());

    cout << "Stampa invisita di b2:" << endl;
    b2.inorderPrint(b2.getRoot());

    cout << "Profondita di b2:\t" << b2.maxDepth(b2.getRoot()) << endl;

    /*
    cout << "Eliminazione di 11" << endl;
    b2.remove(11);
    b1.preorderPrint(b2.getRoot());

    cout << "Eliminazione di 18" << endl;
    b2.remove(18);
    b1.preorderPrint(b2.getRoot());

    cout << "Eliminazione di 30" << endl;
    b2.remove(30);
    b1.preorderPrint(b2.getRoot());

    */

    int sum = 0;

    //sum = b1.levelSum(b1.getRoot(), 2);
    // << "Somma: " << sum << endl;

    sum = b2.levelSum(b2.getRoot(), 3);
    cout << "Somma: " << sum << endl;

    b2.insert("a", 80);

    sum = b2.levelSum(b2.getRoot(), 4);
    cout << "Somma: " << sum << endl;

    b2.remove(80);

    sum = b2.levelSum(b2.getRoot(), 3);
    cout << "Somma: " << sum << endl;
}





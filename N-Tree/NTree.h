#ifndef N_TREE_NTREE_H
#define N_TREE_NTREE_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
struct TNode {
    T data;
    TNode<T> *parent;
    LinkedList<TNode<T> *> childs;

    TNode(T data, TNode<T> *parent = nullptr) {
        this->data = data;
        this->parent = parent;
    }
};

template<typename T>
class NTree {
public:
    //costruttore
    NTree() {
        root = nullptr;
        nodes = 0;
    }

    void inserisciRadice(TNode<T> *node) {
        if (isEmpty() == false) {
            cout << "L'albero ha gia una radice!" << endl;
            return;
        }

        this->root = node;
        nodes++;    //incrementa il numero di nodi
    }

    void inserisciFiglio(TNode<T> *parent, TNode<T> *child) {
        if (appartiene(parent) == false) {
            cout << "Il nodo padre non appartiene all'albero!" << endl;
            return;
        } else if (appartiene(child) == true) {
            cout << "Il nodo figlio e gia nell'albero. Un albero non ammette cicli!" << endl;
            return;
        }
        child->parent = parent;     //assegna il riferimento al padre
        parent->childs.inserisci(child);     //inserisce il figlio nella lista del genitore
        nodes++;
    }

    void inserisciFratello(TNode<T> *sibling, TNode<T> *toAdd) {
        if (appartiene(sibling) == false) {
            cout << "Il fratello non appartiene all'albero!" << endl;
            return;
        } else if (appartiene(toAdd) == true) {
            cout << "Il nodo da aggiungere e gia nell'albero. Un albero non ammette cicli!" << endl;
            return;
        } else if (sibling == root) {
            cout << "L'albero non puo avere due radici!" << endl;
            return;
        }

        toAdd->parent = sibling->parent;    //assegna al nodo da aggiungere lo stesso padre del fratello
        (sibling->parent)->childs.inserisci(toAdd);   //inserisce il fratello nella lista del genitore
        nodes++;
    }

    //rimuove il nodo e se ha figli pota l'albero dal dato nodo in poi
    void cancellaNodo(TNode<T> *toDelete) {
        if (isEmpty() == true) {
            cout << "L'albero e vuoto!" << endl;
            return;
        } else if (appartiene(toDelete) == false) {
            cout << "Il nodo non appartiene all'albero!" << endl;
            return;
        }

        if (isRoot(toDelete) == true) {
            root = nullptr;
        } else {
            for (int i = 0; i < (toDelete->parent)->childs.getSize(); i++) {
                if ((toDelete->parent)->childs.leggiValore(i) == toDelete) {
                    (toDelete->parent)->childs.cancella(i);
                }
            }
        }
    }

    //wrapper
    bool appartiene(TNode<T> *toCheck) {
        if (this->root == nullptr) {
            cout << "Impossibile effettuare il controllo di appartenenza: l'albero e vuoto!" << endl;
            return false;
        }
        bool *flag = new bool();    //puntatore a flag, ricorda di restituire *flag e non l'indirizzo
        *flag = false;

        appartiene(toCheck, this->root, flag);
        return *flag;
    }

    bool isEmpty() {
        if (root == nullptr)
            return true;
        else
            return false;
    }

    bool isLeaf(TNode<T> *node) {
        if (isEmpty() == true) {
            cout << "L'albero e vuoto!" << endl;
            return false;
        } else if (appartiene(node) == false) {
            cout << "Il nodo non appartiene all'albero!" << endl;
            return false;
        }

        if (node->childs.getSize() == 0)
            return true;
        else
            return false;
    }

    bool isRoot(TNode<T> *node) {
        if (node == root)
            return true;
        else
            return false;
    }

    TNode<T> *getRoot() {
        if (isEmpty() == true) {
            cout << "L'albero e vuoto!" << endl;
            return nullptr;
        }

        return this->root;
    }

    TNode<T> *getParent(TNode<T> *node) {
        if (isEmpty()) {
            cout << "L'albero e vuoto!" << endl;
            return nullptr;
        }

        if (appartiene(node) == false) {
            cout << "Il nodo non e presente nell'albero!" << endl;
            return nullptr;
        }

        if (node == root) {
            cout << "Il nodo è radice e non ha padre!" << endl;
            return nullptr;
        }

        return node;
    }

    //wrapper
    void stampaPrevisita() {
        cout << "Stampa Previsita: ";
        stampaPrevisita(getRoot());
        cout << endl;
    }

    //wrapper
    void stampaPostvisita() {
        cout << "Stampa Postvisita: ";
        stampaPostvisita(getRoot());
        cout << endl;
    }

private:
    TNode<T> *root;
    int nodes;

    void appartiene(TNode<T> *toCheck, TNode<T> *subRoot, bool *flag) {
        //ricerca DFS (preorder)
        if (subRoot == toCheck && *flag == false) {
            *flag = true;
            return;
        } else if (*flag == false) {
            for (int i = 0; i < subRoot->childs.getSize(); i++) {
                appartiene(toCheck, subRoot->childs.leggiValore(i), flag);
            }
        }
    }

    void stampaPrevisita(TNode<T> *node) {
        cout << node->data << " ";
        for (int i = 0; i < node->childs.getSize(); i++) {
            stampaPrevisita(node->childs.leggiValore(i));
        }
    }

    void stampaPostvisita(TNode<T> *node) {
        for (int i = 0; i < node->childs.getSize(); i++) {
            stampaPostvisita(node->childs.leggiValore(i));
        }
        cout << node->data << " ";
    }

};

#endif //N_TREE_NTREE_H

#include <iostream>
#include "Tree.h"

using namespace std;

template<typename T>
Tree<T>::Tree() {
    root = nullptr;
    nodes = 0;
}

template<typename T>
void Tree<T>::inserisciRadice(TNode<T> *root) {
    this->root = root;
    nodes++;
}

template<typename T>
void Tree<T>::inserisciFiglio(TNode<T> *node, TNode<T> *toAdd) {
    toAdd->parent = node;
    node->childs.inserisci(toAdd);
    nodes++;
}

template<typename T>
void Tree<T>::inserisciFiglio(TNode<T> *node, T data) {
    TNode<T> *toAdd = new TNode<T>(data);
    toAdd->parent = node;
    node->childs.inserisci(toAdd);
    nodes++;
}

template<typename T>
void Tree<T>::stampaPrevisita(TNode<T> *node) {
    /* cout << node->data << endl;

     if (isLeaf(node) == false) {
         for (int i = 0; i < node->childs.getSize(); i++) {
             stampaPrevisita(node->childs.leggiValore(i));
                 node = node->childs.leggiValore(i+1);
         }
         stampaPrevisita(node);
     }*/

    cout << node->data << endl;
    if (isLeaf(node) == false) {
        for (int i = 0; i < node->childs.getSize(); i++) {
            stampaPrevisita(node->childs.leggiValore(i));
        }
    }
}

//da fare
template<typename T>
void Tree<T>::stampaPostvisita(TNode<T> *node) {
    if (isLeaf(node) == true) {
        cout << node->data << endl;
    } else {
        for (int i = 0; i < node->childs.getSize(); i++) {
            stampaPostvisita(node->childs.leggiValore(i));

        }
        cout << node->data << endl;
    }
}

template<typename T>
void Tree<T>::stampaInvisita(TNode<T> *node) {
    if (isLeaf(node) == true) {
        cout << node->data << endl;
    } else {
        for (int i = 0; i < node->childs.getSize(); i++) {
            stampaInvisita(node->childs.leggiValore(i));
            cout << node->data << endl;
        }

    }
}


template<typename T>
void Tree<T>::inserisciSottoalbero(TNode<T> *node, Tree<T> subTree) {
    /* node: nodo di tree che verrà usato nella copia di tree
     * tree: albero al quale viene aggiunto il sottoalbero che viene copiato e NON modificato
     * subTree: sottoalbero da aggiungere
     */

    inserisciFiglio(node, subTree.root);
}

template<typename T>
void Tree<T>::cancellaSottoalbero(TNode<T> *node) {
    for (int i = 0; i < node->parent->childs.getSize(); i++) {
        if (node == (node->parent)->childs.leggiValore(i)) {
            (node->parent)->childs.cancella(i);
            return;
        }
    }

    cout << "Il nodo non appartiene all'albero!" << endl;
}

template<typename T>
int Tree<T>::altezza(TNode<T> *node) {
    if (isLeaf(node) == true) {
        return 0;
    } else {
        int maxAltezza = 0;
        for (int i = 0; i < node->childs.getSize(); i++) {
            maxAltezza = altezza(node->childs.leggiValore(i));
        }

        return maxAltezza + 1;
    }
}

template<typename T>
bool Tree<T>::isEmpty() {
    if (root == nullptr)
        return true;
    else
        return false;
}

template<typename T>
bool Tree<T>::isLeaf(TNode<T> *node) {
    if (node->childs.getSize() == 0) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool Tree<T>::isLastBrother(TNode<T> *node) {
    TNode<T> *parent = node->parent;
    if (parent->childs.leggiValore(parent->childs.getSize()) == node) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
TNode<T> *Tree<T>::getRoot() {
    return this->root;
}

template<typename T>
TNode<T> *Tree<T>::getParent(TNode<T> *node) {
    return node->parent;
}

template<typename T>
TNode<T> *Tree<T>::getFirstChild(TNode<T> *node) {
    if (node->childs.getSize() == 0) {
        cout << "Il nodo non ha figli!" << endl;
        return NULL;
    }

    node->childs.leggiValore(0);
}

template<typename T>
TNode<T> *Tree<T>::getNextBrother(TNode<T> *node) {
    TNode<T> *parent = node->parent;

    for (int i = 0; i < parent->childs.getSize(); i++) {
        if (node == parent->childs.leggiValore(i))
            //controlla che l'elemento successivo esista
            if (parent->childs.getSize() >= (i + 1) && parent->childs.leggiValore(i + 1) != nullptr)
                return parent->childs.leggiValore(i + 1);
    }

    cout << "Il nodo non ha altri fratelli!" << endl;
    return nullptr;
}





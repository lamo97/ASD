#ifndef TREE_TREE_H
#define TREE_TREE_H

#include "LinkedList.h"

template<typename T>
struct TNode {
    T data;
    TNode<T> *parent;
    LinkedList<TNode<T>*> childs;

    TNode() {
        data = NULL;
        parent = nullptr;
    }

    TNode(T data) {
        this->data = data;
        parent = nullptr;
    }
};

template <typename T>
class Tree{
public:
    Tree();
    void inserisciRadice(TNode<T>* root);
    void inserisciFiglio(TNode<T>* node, TNode<T>* toAdd);
    void inserisciFiglio(TNode<T>* node, T data);
    //Tree<T> inserisciPrimoSottoalbero(TNode<T>* node, Tree<T> subTree);
    //Tree<T> inserisciSottoalbero(TNode<T>* node, Tree<T> subTree);
    //void cancellaSottoalbero(TNode<T>* node);
    bool isEmpty();
    bool isLeaf(TNode<T>* node);
    bool isLastBrother(TNode<T>* node);
    TNode<T>* getRoot();
    TNode<T>* getParent(TNode<T>* node);
    TNode<T>* getFirstChild(TNode<T>* node);
    TNode<T>* getNextBrother(TNode<T>* node);

    void stampaPrevisita(TNode<T> *node);
    void stampaPostvisita(TNode<T> *node);
    void stampaInvisita(TNode<T> *node);//da fare

private:
    TNode<T>* root;
    int nodes;
};

#endif //TREE_TREE_H

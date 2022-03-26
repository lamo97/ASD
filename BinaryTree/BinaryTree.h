#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>

using namespace std;

template<typename T>
struct TNode {
    T data;
    TNode<T> *left;
    TNode<T> *right;
    TNode<T> *parent;

    TNode() {
        left = right = parent = nullptr;
    }

    TNode(T data) {
        this->data = data;
        left = right = parent = nullptr;
    }

    ~TNode() {
        if (parent->left == this) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }

    void printNode() {
        cout << "Data: " << data << "\tAddress: " << this << "\tParent: " << parent << "\tLeft: " << left << "\tRight: "
             << right << endl;
    }
};

template<typename T>
class BinaryTree {
public:
    BinaryTree();
    T leggiValore(TNode<T> *node);

    void inserisciRadice(TNode<T> *node);
    void inserisciSinistro(TNode<T> *node, T data);
    void inserisciSinistro(TNode<T> *node, TNode<T> *toAdd);
    void inserisciDestro(TNode<T> *node, T data);
    void inserisciDestro(TNode<T> *node, TNode<T> *toAdd);

    void cancellaSottoalbero(TNode<T> *node);
    BinaryTree<T> unisciAlberi(BinaryTree<T> t1, BinaryTree<T> t2);
    void inserisciNodo(T data); //inserisce un nodo seguendo la logica del preorder
    int altezza(TNode<T> *node);
    //wrapper per proprio (private)
    bool proprio(TNode<T> *root); //un albero binario si dice proprio se ogni nodo ha 0 o 2 figli

    void stampaPreorder(TNode<T> *root);
    void stampaInorder(TNode<T> *root);
    void stampaPostorder(TNode<T> *root);

    TNode<T> *getRoot();
    TNode<T> *getParent(TNode<T> *node);
    TNode<T> *getLeftChild(TNode<T> *node);
    TNode<T> *getRightChild(TNode<T> *node);

    bool isEmpty();
    bool isEmpty(TNode<T> *node);
    bool emptyLeft(TNode<T> *node);
    bool emptyRight(TNode<T> *node);

    int getNodesNumber();

private:
    TNode<T> *root;
    int nodes;  //numero di nodi nell'albero

    void inserimentoPreorder(TNode<T> *&node, TNode<T> *parent, T data);
    bool proprio(TNode<T> *node, int d, int level=0);
    int altezzaLeftmost(TNode<T> *root);
};

template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    nodes = 0;
}

template<typename T>
void BinaryTree<T>::inserisciRadice(TNode<T> *node) {
    if (nodes > 0) {
        cout << "L'albero ha gia una radice!" << endl;
        return;
    }

    root = node;
}

template<typename T>
void BinaryTree<T>::inserisciSinistro(TNode<T> *node, T data) {
    if (node->left != nullptr) {
        cout << "Il nodo ha gia un figlio sinistro!" << endl;
        return;
    }

    node->left = new TNode<T>(data);
    (node->left)->parent = node;

    nodes++;
}

template<typename T>
void BinaryTree<T>::inserisciSinistro(TNode<T> *node, TNode<T> *toAdd) {
    if (node->left != nullptr) {
        cout << "Il nodo ha gia un figlio sinistro!" << endl;
        return;
    }

    node->left = toAdd;
    toAdd->parent = node;

    nodes++;
}

template<typename T>
void BinaryTree<T>::inserisciDestro(TNode<T> *node, T data) {
    if (node->right != nullptr) {
        cout << "Il nodo ha gia un figlio destro!" << endl;
        return;
    } else if (node->left == nullptr) {
        cout << "Inserire prima il figlio sinistro!" << endl;
        return;
    }

    node->right = new TNode<T>(data);
    (node->right)->parent = node;

    nodes++;
}

template<typename T>
void BinaryTree<T>::inserisciDestro(TNode<T> *node, TNode<T> *toAdd) {
    if (node->right != nullptr) {
        cout << "Il nodo ha gia un figlio destro!" << endl;
        return;
    } else if (node->left == nullptr) {
        cout << "Inserire prima il figlio sinistro!" << endl;
        return;
    }

    node->right = toAdd;
    toAdd->parent = node;

    nodes++;
}

template<typename T>
void BinaryTree<T>::cancellaSottoalbero(TNode<T> *node) {
    if (node == nullptr || node == NULL) {
        return;
    }

    cancellaSottoalbero(node->left);
    cancellaSottoalbero(node->right);
    //node->printNode();
    delete node;
}

template<typename T>
BinaryTree<T> BinaryTree<T>::unisciAlberi(BinaryTree<T> t1, BinaryTree<T> t2) {
    BinaryTree<T> res;  //albero unione
    TNode<T> *rt = new TNode<T>(0); //nuova radice

    res.inserisciRadice(rt);    //la nuova radice diventa radice dell'albero unione
    res.inserisciSinistro(res.getRoot(), t1.getRoot());     //t1 diventa il sottoalbero sinistro
    res.inserisciDestro(res.getRoot(), t2.getRoot());       //t2 diventa il sottoalbero destro

    res.nodes = t1.getNodesNumber() + t2.getNodesNumber();  /*il numero di nodi dell'albero risultato sarà la somma
                                                            dei nodi dei due alberi*/
    return res;
}

template<typename T>
void BinaryTree<T>::inserisciNodo(T data) {
    //controlla che l'albero non sia vuoto, altrimenti aggiunge il nodo come radice
    if (getRoot() == nullptr) {
        TNode<T> *node = new TNode<T>(data);
        inserisciRadice(node);
        return;
    }

    inserimentoPreorder(root, nullptr, data);
}

template<typename T>
void BinaryTree<T>::inserimentoPreorder(TNode<T> *&node, TNode<T> *parent, T data) {
    if (node == nullptr) {
        node = new TNode<T>(data);
        node->parent = parent;
        return;
    } else if (altezza(node->left) <= altezza(node->right)) {
        inserimentoPreorder(node->left, node, data);
    } else {
        inserimentoPreorder(node->right, node, data);
    }
}

template<typename T>
int BinaryTree<T>::altezza(TNode<T> *node) {
    if (node == nullptr) {
        return -1;
    } else {
        //chiamata ricorsiva su ogni sottoalbero
        int left_height = altezza(node->left);
        int right_height = altezza(node->right);

        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

template <typename T>
bool BinaryTree<T>::proprio(TNode<T> *node, int d, int level) {
    if(node == nullptr)
        return true;

    if(node->left == nullptr && node->right == nullptr){
        return (d == level+1);
    }

    if(root->left == nullptr || root->right == nullptr){
        return false;
    }

    return proprio(node->left, d, level+1) && proprio(node->right, d, level+1);
}

//wrapper
template <typename T>
bool BinaryTree<T>::proprio(TNode<T> *root)
{
    int d = altezzaLeftmost(root);
    return proprio(root, d);
}

template <typename T>
int BinaryTree<T>::altezzaLeftmost(TNode<T> *root){
    int d = 0;
    while(root != nullptr){
        d++;
        root = root->left;
    }

    return d;
}

template<typename T>
void BinaryTree<T>::stampaPreorder(TNode<T> *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << "\n";
    stampaPreorder(root->left);
    stampaPreorder(root->right);
}

template<typename T>
void BinaryTree<T>::stampaInorder(TNode<T> *root) {
    if (root == nullptr) {
        return;
    }

    stampaInorder(root->left);
    if (root == this->root) {
        cout << "---\n";
    }
    cout << root->data << "\n";
    if (root == this->root) {
        cout << "---\n";
    }
    stampaInorder(root->right);
}

template<typename T>
void BinaryTree<T>::stampaPostorder(TNode<T> *root) {
    if (root == nullptr) {
        return;
    }
    stampaPostorder(root->left);
    stampaPostorder(root->right);
    cout << root->data << "\n";
}

template<typename T>
T BinaryTree<T>::leggiValore(TNode<T> *node) {
    return node->data;
}

template<typename T>
bool BinaryTree<T>::isEmpty() {
    if (root->left == nullptr && root->right == nullptr)
        return true;
    else
        return false;
}

//metodo per i subtree
template<typename T>
bool BinaryTree<T>::isEmpty(TNode<T> *node) {
    if (node->left == nullptr && node->right == nullptr)
        return true;
    else
        return false;
}

template<typename T>
TNode<T> *BinaryTree<T>::getRoot() {
    return root;
}

template<typename T>
TNode<T> *BinaryTree<T>::getParent(TNode<T> *node) {
    return node->parent;
}

template<typename T>
TNode<T> *BinaryTree<T>::getLeftChild(TNode<T> *node) {
    return node->left;
}

template<typename T>
TNode<T> *BinaryTree<T>::getRightChild(TNode<T> *node) {
    return node->right;
}

template<typename T>
bool BinaryTree<T>::emptyLeft(TNode<T> *node) {
    if (node->left == nullptr)
        return true;
    else
        return false;
}

template<typename T>
bool BinaryTree<T>::emptyRight(TNode<T> *node) {
    if (node->right == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int BinaryTree<T>::getNodesNumber() {
    return nodes;
}

#endif //BINARYTREE_BINARYTREE_H

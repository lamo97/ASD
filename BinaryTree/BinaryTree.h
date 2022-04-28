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
    BinaryTree() {
        root = nullptr;
        nodes = 0;
    }

    void inserisciRadice(TNode<T> *node) {
        if (nodes > 0) {
            cout << "L'albero ha gia una radice!" << endl;
            return;
        }

        root = node;
    }

    void inserisciSinistro(TNode<T> *node, T data) {
        if (node->left != nullptr) {
            cout << "Il nodo ha gia un figlio sinistro!" << endl;
            return;
        }

        node->left = new TNode<T>(data);
        (node->left)->parent = node;

        nodes++;
    }

    void inserisciSinistro(TNode<T> *node, TNode<T> *toAdd) {
        if (node->left != nullptr) {
            cout << "Il nodo ha gia un figlio sinistro!" << endl;
            return;
        }

        node->left = toAdd;
        toAdd->parent = node;

        nodes++;
    }

    void inserisciDestro(TNode<T> *node, T data) {
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

    void inserisciDestro(TNode<T> *node, TNode<T> *toAdd) {
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

    void cancellaSottoalbero(TNode<T> *node) {
        if (node == nullptr || node == NULL) {
            return;
        }

        cancellaSottoalbero(node->left);
        cancellaSottoalbero(node->right);
        //node->printNode();
        delete node;
    }

    BinaryTree<T> unisciAlberi(BinaryTree<T> t1, BinaryTree<T> t2) {
        BinaryTree<T> res;  //albero unione
        TNode<T> *rt = new TNode<T>(0); //nuova radice

        res.inserisciRadice(rt);    //la nuova radice diventa radice dell'albero unione
        res.inserisciSinistro(res.getRoot(), t1.getRoot());     //t1 diventa il sottoalbero sinistro
        res.inserisciDestro(res.getRoot(), t2.getRoot());       //t2 diventa il sottoalbero destro

        res.nodes = t1.getNodesNumber() + t2.getNodesNumber();  /*il numero di nodi dell'albero risultato sarà la somma
                                                            dei nodi dei due alberi*/
        return res;
    }

    //inserisce un nodo seguendo la logica del preorder
    void inserisciNodo(T data) {
        //controlla che l'albero non sia vuoto, altrimenti aggiunge il nodo come radice
        if (getRoot() == nullptr) {
            TNode<T> *node = new TNode<T>(data);
            inserisciRadice(node);
            return;
        }

        inserimentoPreorder(root, nullptr, data);
    }

    int altezza(TNode<T> *node) {
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

    //wrapper per proprio (private)
    //un albero binario si dice proprio se ogni nodo ha 0 o 2 figli
    bool proprio(TNode<T> *root) {
        int d = altezzaLeftmost(root);
        return proprio(root, d);
    }


    bool isCompleto(TNode<T> *root) {
        int rightH = altezza(root->left);
        int leftH = altezza(root->right);

        if (leftH == rightH && proprio(root->left) && proprio(root->right)) {
            return true;
        } else {
            return false;
        }
    }

    void stampaPreorder(TNode<T> *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->data << "\n";
        stampaPreorder(root->left);
        stampaPreorder(root->right);
    }

    void stampaInorder(TNode<T> *root) {
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

    void stampaPostorder(TNode<T> *root) {
        if (root == nullptr) {
            return;
        }
        stampaPostorder(root->left);
        stampaPostorder(root->right);
        cout << root->data << "\n";
    }

    T leggiValore(TNode<T> *node) {
        return node->data;
    }

    TNode<T> *getRoot() {
        return root;
    }

    TNode<T> *getParent(TNode<T> *node) {
        return node->parent;
    }

    TNode<T> *getLeftChild(TNode<T> *node) {
        return node->left;
    }

    TNode<T> *getRightChild(TNode<T> *node) {
        return node->right;
    }

    bool isEmpty() {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        else
            return false;
    }

    //metodo per i subtree
    bool isEmpty(TNode<T> *node) {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        else
            return false;
    }

    bool emptyLeft(TNode<T> *node) {
        if (node->left == nullptr)
            return true;
        else
            return false;
    }

    bool emptyRight(TNode<T> *node) {
        if (node->right == nullptr)
            return true;
        else
            return false;
    }

    int getNodesNumber() {
        return nodes;
    }

private:
    TNode<T> *root;
    int nodes;  //numero di nodi nell'albero

    void inserimentoPreorder(TNode<T> *&node, TNode<T> *parent, T data) {
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

    bool proprio(TNode<T> *node, int d, int level = 0) {
        if (node == nullptr)
            return true;

        if (node->left == nullptr && node->right == nullptr) {
            return (d == level + 1);
        }

        if (root->left == nullptr || root->right == nullptr) {
            return false;
        }

        return proprio(node->left, d, level + 1) && proprio(node->right, d, level + 1);
    }

    int altezzaLeftmost(TNode<T> *root) {
        int d = 0;
        while (root != nullptr) {
            d++;
            root = root->left;
        }

        return d;
    }
};

#endif //BINARYTREE_BINARYTREE_H

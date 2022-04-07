#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node() {
        key = -1;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(T data, int key) {
        this->data = data;
        this->key = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    bool operator<(Node *toCompare) {
        if (this->key < toCompare->key)
            return true;
        else
            return false;
    }

    bool operator>(Node *toCompare) {
        if (this->key > toCompare->key)
            return true;
        else
            return false;
    }

    bool operator<=(Node *toCompare) {
        if (this->key <= toCompare->key)
            return true;
        else
            return false;
    }

    bool operator>=(Node *toCompare) {
        if (this->key >= toCompare->key)
            return true;
        else
            return false;
    }

    bool operator==(Node *toCompare) {
        if (this->key == toCompare->key)
            return true;
        else
            return false;
    }

    void printNode() {
        if (this == nullptr) {
            return;
        }

        cout << key << "\t" << data;
        if (left != nullptr)
            cout << "\tLeft: " << left->key;
        if (right != nullptr)
            cout << "\tRight: " << right->key;

        cout << endl;
    }
};


template<typename T>
class BST {
public:
    BST() {
        root = nullptr;
    }

    //wrapper
    void insert(T data, int key) {
        if (root == nullptr) {
            //inserimento radice
            Node<T> *toAdd = new Node<T>(data, key);
            insertRoot(toAdd);
            return;
        }

        if (exists(getRoot(), key) == true) {
            cout << "La chiave e gia presente nell'albero!" << endl;
            return;
        }

        //se c'e gia una radice e la chiave non e gia presente nell'albero, aggiungi
        insert(data, key, getRoot());
    }

    //wrapper
    void remove(int key) {
        if (isLeaf(root) == true) {
            cout << "L'albero e vuoto!" << endl;
            return;
        }

        if (exists(getRoot(), key) == false) {
            cout << "Non c'e nessun elemento con questa chiave nell'albero!" << endl;
            return;
        }

        remove(search(key, getRoot()));
    }

    Node<T> *search(int key, Node<T> *subRoot) {
        if (subRoot->key == key)
            return subRoot;
        else if (subRoot->left != nullptr && subRoot->key > key)
            search(key, subRoot->left);
        else
            search(key, subRoot->right);
    }

    Node<T> *min(Node<T> *subRoot) {
        if (subRoot->left == nullptr)
            return subRoot;

        if (subRoot->left != nullptr)
            min(subRoot->left);
    }

    Node<T> *max(Node<T> *subRoot) {
        if (subRoot->right == nullptr)
            return subRoot;

        if (subRoot->right != nullptr)
            max(subRoot->right);
    }

    /* Dato un elemento la cui chiave appartiene all’insieme,
     * restituisce il prossimo elemento (più grande) */
    Node<T> *successor(int key) {
        if (exists(getRoot(), key) == false) {
            return nullptr;
        }

        Node<T> *node = search(key, getRoot());

        if (node->right == nullptr) {
            cout << "Il nodo non ha successori!" << endl;
            return nullptr;
        } else {
            return node->right;
        }
    }

    /* Dato un elemento la cui chiave appartiene all’insieme,
     * restituisce l'elemento precedente (più piccolo) */
    Node<T> *predecessor(int key) {
        //controllo sull'esistenza
        if (exists(getRoot(), key) == false) {
            return nullptr;
        }

        //crezione di un nodo con la chiave passata come parametro
        Node<T> *node = search(key, getRoot());

        if (node->left == nullptr && node->parent == nullptr) {
            //albero composto solo dalla radice
            cout << "Il nodo non ha predecessori o l'albero è composto solo dalla radice!" << endl;
            return nullptr;
        } else {
            if (node->parent == nullptr && node->left != nullptr) {
                /*la chiave si riferisce alla radice, quindi il primo
                predecessore e il suo figlio sinistro, se esiste */
                return node->left;
            } else if (node->left != nullptr && node->left < node->parent) {
                //figlio sinistro minore del genitore
                return node->left;
            } else {
                //genitore minore del figlio sinistro del nodo
                return node->parent;
            }
        }
    }


    void preorderPrint(Node<T> *root) {
        if (isLeaf(root) == true) {
            root->printNode();
            return;
        }

        root->printNode();
        if (root->left != nullptr) {
            preorderPrint(root->left);
        }
        if (root->right != nullptr) {
            preorderPrint(root->right);
        }
    }

    bool exists(Node<T> *node, int key) {
        if (node->key == key)
            return true;
        else if (node->key > key) {
            if (node->left != nullptr)
                exists(node->left, key);
            else
                return false;
        } else if (node->key < key) {
            if (node->right != nullptr)
                exists(node->right, key);
            else
                return false;
        }
    }


    bool isLeaf(Node<T> *node) {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        else
            return false;
    }

    Node<T> *getRoot() {
        return root;
    }

    void printParents() {
        for (int i = 1; i < 20; i++) {
            if (exists(getRoot(), i && search(i, getRoot())->parent != nullptr)) {
                cout << search(i, getRoot())->key << ": " << search(i, getRoot())->parent->key << endl;
            }
        }
    }

private:
    Node<T> *root;

    void insert(T data, int key, Node<T> *node) {
        //caso 1: il nodo è foglia
        if (isLeaf(node) == true) {
            if (node->key > key) {
                Node<T> *toAdd = new Node<T>(data, key);
                toAdd->parent = node;
                node->left = toAdd;
                return;
            } else if (node->key < key) {
                Node<T> *toAdd = new Node<T>(data, key);
                toAdd->parent = node;
                node->right = toAdd;
                return;
            }
        }

        //caso 2: il nodo ha solo un figlio destro
        if (node->left == nullptr && node->right != nullptr) {
            //chiave minore della chiave del nodo e nessun figlio sinistro
            if (node->key > key) {
                Node<T> *toAdd = new Node<T>(data, key);
                node->left = toAdd;
                toAdd->parent = node;
                return;
            } else if (node->key < key) {
                //chiave maggiore della chiave del nodo e figlio destro esistente
                insert(data, key, node->right);
                return;
            }
        }

        //caso 3: il nodo ha solo un figlio sinistro
        if (node->left != nullptr && node->right == nullptr) {
            //chiave maggiore della chiave del nodo e nessun figlio destro
            if (node->key < key) {
                Node<T> *toAdd = new Node<T>(data, key);
                node->right = toAdd;
                toAdd->parent = node;
                return;
            } else if (node->key > key) {
                //chiave minore della chiave del nodo e figlio sinistro esistente
                insert(data, key, node->left);
                return;
            }
        }

        //caso 4: il nodo ha gia un figlio sinistro e destro
        if (node->left != nullptr && node->right != nullptr) {
            //chiave minore della chiave del nodo
            if (node->key > key) {
                insert(data, key, node->left);
                return;
            } else if (node->key < key) {
                //chiave maggiore della chiave del nodo
                insert(data, key, node->right);
                return;
            }
        }
    }

    void remove(Node<T> *node) {
        //caso 1: il nodo è foglia - si rimuove semplicemente il nodo
        if (isLeaf(node) == true) {
            if (node->parent == nullptr) {
                //la radice è l'unico nodo nell'albero
                root = nullptr;
            } else if ((node->parent)->left != nullptr && (node->parent)->left == node) {
                //il nodo è il figlio sinistro del genitore
                (node->parent)->left = nullptr;
            } else {
                //il nodo è il figlio destro del genitore
                (node->parent)->right = nullptr;
            }

            delete node;
            return;
        }

        /* caso 2: il nodo da rimuovere ha solo un sottoalbero sinistro - il genitore del
         * nodo da rimuovere avrà come successore il sottoalbero
         * (destro o sinistro, in base a dove si trova il nodo in questione)
         * il sottoalbero (sinistro) del nodo da rimuovere
         */
        if (node->left != nullptr && node->right == nullptr) {
            if (node->parent == nullptr) {
                //il nodo da rimuovere è la radice
                (node->left)->parent = nullptr;
                root = node->left;
            } else if ((node->parent)->left != nullptr && (node->parent)->left == node) {
                //se node è figlio sinistro del nodo genitore
                (node->left)->parent = node->parent;
                (node->parent)->left = node->left;
            } else if ((node->parent)->right != nullptr && (node->parent)->right == node) {
                //se node è figlio destro del nodo genitore
                (node->left)->parent = node->parent;
                (node->parent)->right = node->left;
            }
            delete node;
            return;
        }

        /* caso 3: il nodo da rimuovere ha solo un sottoalbero destro - il genitore del
         * nodo da rimuovere avrà come successore il sottoalbero
         * (destro o sinistro, in base a dove si trova il nodo in questione)
         * il sottoalbero (destro) del nodo da rimuovere
         */
        if (node->right != nullptr && node->left == nullptr) {
            if (node->parent == nullptr) {
                //il nodo da rimuovere è la radice
                (node->right)->parent = nullptr;
                root = node->right;
            } else if ((node->parent)->left != nullptr && (node->parent)->left == node) {
                //se node è figlio sinistro del nodo genitore
                (node->right)->parent = node->parent;
                (node->parent)->left = node->right;
            } else if ((node->parent)->right != nullptr && (node->parent)->right == node) {
                //se node è figlio destro del nodo genitore
                (node->right)->parent = node->parent;
                (node->parent)->right = node->right;
            }

            delete node;
            return;
        }


        /* Caso 4: il nodo ha un sottoalbero sinitro e destro -
         * si sostituisce il nodo da rimuovere con il nodo maggiore del suo sottoalbero sinistro,
         * oppure equivalentemente con il nodo minore del suo sottoalbero destro.
         * A questo punto, però, si avrà un valore duplicato nell’albero; si richiama allora la
         * funzione di eliminazione sul nodo copiato, ricorsivamente.
         * Tutto questo si ripete fin quando la funzione non ricade nei primi 3 casi.
         */

        if (node->left != nullptr && node->right != nullptr) {
            node->data = max(node->left)->data;
            node->key = max(node->left)->key;

            remove(max(node->left));
        }
    }


    void insertRoot(Node<T> *toAdd) {
        root = toAdd;
        return;
    }
};

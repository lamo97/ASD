// Created by Gianfranco
// Implementazione della struttura dizionario con HashTable

#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#define SIZE 20

#include "LinkedList.h"
#include <typeinfo>

using namespace std;

template<typename K, typename V>
struct Bucket {
    K key;
    V value;
};

template<typename K, typename V>
class DizionarioHash {
private:
    LinkedList<Bucket<K, V>> table[SIZE]; //matrice per gestire i conflitti????

public:
    DizionarioHash() = default;     //costruttore
    ~DizionarioHash() = default;    //distruttore

    bool appartiene(K key) {
        int position = hashFunction(key);   //ipotetica posizione della chiave nell'array
        //scorre l'intera lista in quella posizione, nel caso ci siano stati conflitti all'inserimento
        for (int i = 0; i < table[position].getSize(); i++) {
            //confronta la chiave in posizione con quella data come parametro
            if (key == table[position].readValue(i).key)
                return true;
        }
        return false;
    }

    //versione del metodo di inserimento per l'aggiunta di bucket con il passaggio di buckets
    void inserisci(Bucket<K, V> toAdd) {
        if (appartiene(toAdd.key) == true) {
            cout << "La chiave e gia nel dizionario!" << endl;
        } else {
            int position = hashFunction(toAdd.key);
            table[position].add(toAdd);
        }
    }

    //versione del metodo di inserimento per l'aggiunta di bucket con il passaggio di chiave,valore
    void inserisci(K key, V value) {
        Bucket<K, V> toAdd;
        toAdd.key = key;
        toAdd.value = value;
        if (appartiene(toAdd.key) == true) {
            cout << "La chiave e gia nel dizionario!" << endl;
        } else {
            int position = hashFunction(toAdd.key);
            table[position].add(toAdd);
        }
    }

    void cancella(Bucket<K, V> toDelete) {
        if (appartiene(toDelete.key) == true) {
            int position = hashFunction(toDelete.key);
            for (int i = 0; i < table[position].getSize(); i++) {
                //confronta la chiave in posizione con quella dell'elemento da cancellare
                if (toDelete.key == table[position].readValue(i).key) {
                    table[position].cancel(i);
                    return;
                }
            }
        } else {
            cout << "L'elemento non e presente nel dizionario!" << endl;
        }
    }

    void cancella(K key) {
        if (appartiene(key) == true) {
            int position = hashFunction(key);
            for (int i = 0; i < table[position].getSize(); i++) {
                //confronta la chiave in posizione con quella dell'elemento da cancellare
                if (key == table[position].readValue(i).key) {
                    table[position].cancel(i);
                    return;
                }
            }
        } else {
            cout << "L'elemento non e presente nel dizionario!" << endl;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    int hashFunction(string key) {
        int sum = 0;
        //somma tutti i valori ASCII dei caratteri della stringa
        for (int i = 0; i < key.length(); i++) {
            sum = sum + key[i];
        }
        return sum % SIZE;
    }

    Bucket<K, V> recupera(K key) {
        if (appartiene(key) == true) {
            int position = hashFunction(key);
            for (int i = 0; i < table[position].getSize(); i++) {
                if (key == table[position].readValue(i).key)
                    return table[position].readValue(i);
            }
        } else {
            cout << "La chiave non e presente nel dizionario!" << endl;
        }
    }

    void aggiorna(K key, V value) {
        if (appartiene(key) == true) {
            int position = hashFunction(key);
            for (int i = 0; i < table[position].getSize(); i++) {
                if (key == table[position].readValue(i).key)
                    table[position].readValue(i).value = value;
            }
        } else {
            cout << "La chiave non e presente nel dizionario!" << endl;
        }
    }

    void stampaDizionario() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < table[i].getSize(); j++) {
                cout << "Chiave: " << table[i].readValue(j).key << " Valore: " << table[i].readValue(j).value << endl;
            }
        }
        cout << "---" << endl;
    }

};

#endif //DIZIONARIO_H

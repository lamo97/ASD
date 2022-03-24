// Implementazione della strtuttra Insieme sfruttando la LinkedList

#ifndef SET_SET_H
#define SET_SET_H

#include "LinkedList.h"

using namespace std;

template<typename T>
class Set {
public:
    Set() {
        size = 0;
    }

    ~Set() = default;

    void inserisci(T toAdd) {
        if (appartiene(toAdd) == true) {
            cout << "L'elemento e gia nell'insieme!" << endl;
            return;
        }

        elements.inserisci(toAdd);
        size++;
    }

    void cancella(T toDelete) {
        if (appartiene(toDelete) == false) {
            cout << "L'elemento non e nell'insieme!" << endl;
            return;
        }

        for (int i = 0; i < elements.getSize(); i++) {
            if (toDelete == elements.leggiValore(i)) {
                elements.cancella(i);
            }
        }
    }

    Set<T> unione(Set<T> s1, Set<T> s2) {
        Set<T> joined;
        T toAdd;

        if (s1.isEmpty() && s2.isEmpty()) {
            //s1, s2 entrambi vuoti
            cout << "Entrambi gli insiemi sono vuoti!" << endl;
            return joined;
        } else if (s1.isEmpty() == false && s2.isEmpty() == true) {
            //s2 vuoto
            return s1;
        } else if (s1.isEmpty() == true && s2.isEmpty() == false) {
            //s1 vuoto
            return s2;
        } else {
            //entrambi gli insiemi non vuoti
            for (int i = 0; i < s1.size; i++) {
                //copia il contenuto di s1 in joined
                joined.inserisci(s1.elements.leggiValore(i));
            }
            for (int i = 0; i < s2.size; i++) {
                /*copia il contentuto di s2 in joined, controllando preventivamente se ci sono
                ripetizioni, in modo da evitare gli alert stampati a video*/
                toAdd = s2.elements.leggiValore(i);
                if (joined.appartiene(toAdd) == false) {
                    joined.inserisci(toAdd);
                }
            }
            return joined;
        }
    }

    Set<T> intersezione(Set<T> s1, Set<T> s2) {
        T toAdd;
        Set<T> intersection;

        //controlla che nessuno degli insiemi sia vuoto
        if (s1.isEmpty() || s2.isEmpty())
            return intersection;

        //scorre gli elementi del primo insieme
        for (int i = 0; i < s1.size; i++) {
            toAdd = s1.elements.leggiValore(i);
            /*contolla che l'elemnto appartenga anche al secondo
            e che non sia già stato inserito nell'insieme risultato*/
            if (s2.appartiene(toAdd) == true && intersection.appartiene(toAdd) == false) {
                intersection.inserisci(toAdd);
            }
        }
        //scorre gli elementi del secondo insieme
        for (int i = 0; i < s2.size; i++) {
            toAdd = s2.elements.leggiValore(i);
            /*contolla che l'elemnto appartenga anche al primo
            e che non sia già stato inserito nell'insieme risultato*/
            if (s1.appartiene(toAdd) == true && intersection.appartiene(toAdd) == false) {
                intersection.inserisci(toAdd);
            }
        }
        return intersection;
    }

    Set<T> differenza(Set<T> s1, Set<T> s2) {
        T toAdd;
        Set<T> diff;

        if (s1.isEmpty()) {
            return diff;
        } else if (s2.isEmpty()) {
            return s1;
        } else{
            //scorre gli elementi di s1 e se non compaiono in s2 li aggiunge all'insieme risultato
            for(int i=0; i<s1.size; i++){
                toAdd = s1.elements.leggiValore(i);
                if(s2.appartiene(toAdd) == false){
                    diff.inserisci(toAdd);
                }
            }
            return diff;
        }
    }

    bool appartiene(T toCheck) {
        for (int i = 0; i < elements.getSize(); i++) {
            if (toCheck == elements.leggiValore(i))
                return true;
        }

        return false;
    }

    bool isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    void stampaInsieme() {
        elements.stampaValori();
    }

private:
    LinkedList<T> elements;
    int size;
};

#endif //SET_SET_H

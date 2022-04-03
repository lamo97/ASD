#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
    PriorityQueue<int> q1;
    PriorityQueue<int> q2;

    if(q1 == q2){
        cout << "si" << endl;
    }

    Node<int> n1(1,1);
    Node<int> n2(2,2);
    Node<int> n3(10,10);
    Node<int> n4(60,60);
    Node<int> n5(8,8);


    q1.inserisci(n1);
    q1.inserisci(n2);
    q1.inserisci(n3);
    q1.inserisci(n4);
    q1.inserisci(n5);
    q1.inserisci(100,100);

    q1.stampaCoda();
    cout << endl;

    q1.rimuovi();
    q1.stampaCoda();

}

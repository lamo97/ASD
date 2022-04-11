#include <iostream>
#include "MaxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue<int> q1;
    MaxPriorityQueue<int> q2;

    if(q1 == q2){
        cout << "si" << endl;
    }

    QNode<int> n1(1,1);
    QNode<int> n2(2,2);
    QNode<int> n3(10,10);
    QNode<int> n4(60,60);
    QNode<int> n5(8,8);
    QNode<int> n7(3,3);


    q1.inserisci(n1);
    q1.inserisci(n2);
    q1.inserisci(n3);
    q1.inserisci(n4);
    q1.inserisci(n5);
    q1.inserisci(100,100);
    q1.inserisci(n7);

    q1.stampaCoda();

    struct Test{
        int data;
    };

    Test t1;
    t1.data = 5;

    MaxPriorityQueue<Test> q3;
    q3.inserisci(t1, 5);
    cout << q3.leggiTesta().data.data << endl;
}

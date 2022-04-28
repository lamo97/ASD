#include <iostream>
#include "Dizionario.h"
using namespace std;

int main() {
    DizionarioHash<int, string> d;

    Bucket<int, string> b1;
    b1.key = 120;
    b1.value = "Marco";
    d.inserisci(b1);

    Bucket<int, string> b2;
    b2.key = 350;
    b2.value = "Francesco";
    d.inserisci(b2);

    Bucket<int, string> b3;
    b3.key = 310;
    b3.value = "Mirco";
    d.inserisci(b3);

    d.stampaDizionario();

    d.aggiorna(120, "Matteo");
    d.stampaDizionario();

    Bucket<int, string> b4;
    b4.key = 310;
    b4.value = "Ivan";
    d.inserisci(b4);

    d.inserisci(400, "John");

    d.cancella(b2);
    d.stampaDizionario();
    /*string test = "test";
    string test2 = "test";

    if(test == test2){
        cout << "Fatto" << endl;
        cout << test.length() << endl;
    }

    cout << "TEST: " << test[0] << endl;
    int t = (unsigned char) test[0];
    cout << "TEST 2: " << t << endl;

    cout << "Hash function test"<< endl;
    cout << "int:\t" << d.hashFunction(131) << endl;
    cout << "Marco:\t" << d.hashFunction("Marco") << endl;*/
}

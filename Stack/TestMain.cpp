#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.printStack();
    p.pop();
    p.printStack();
    std::cout << "isEmpty: " << p.isEmpty() << "\n";
}



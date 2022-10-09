#include <iostream>
#include "Stack.h"

int main() {
    /*List* a = new List();
    a->insertFirst(1);
    a->insertFirst(2);
    a->insertFirst(3);
*//*    a->print();
    if (a->exists(10))
        std::cout<<"true";
    else
        std::cout<<"false";
    std::cout<<'\n';
    a->removeFirst();*//*
    a->print();
    a->remove(1,List::DeleteFlag::EQUAL);
    a->print();*/

    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    std::cout<<stack.pop()<<"\n";
    stack.print();

    return 0;
}

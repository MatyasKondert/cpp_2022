//
// Created by Matyas Kondert on 10/9/2022.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>
#include "List.h"

class Stack
{

public:
    Stack();
    void push(int e);
    int pop();
    bool isEmpty() const;
    void print();
private:
    List* list;
};


#endif //LAB3_STACK_H

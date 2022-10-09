//
// Created by Matyas Kondert on 10/9/2022.
//

#include "Stack.h"

Stack::Stack(){
    this->list = new List();
}

bool Stack::isEmpty() const
{
    return (this->list->empty());
}

void Stack::push(int e)
{
    this->list->insertFirst(e);
}

int Stack::pop()
{
    if (this->list->empty())
        throw std::invalid_argument("List Is Empty");
    return this->list->removeFirst();
}

void Stack::print()
{
    this->list->print();
}

//
// Created by Matyas Kondert on 10/5/2022.
//

#include "List.h"

List::List()
{
    this->first = nullptr;
}

List::~List()
{
    if (this->first->next != nullptr)
        delete this->first->next;
}

void List::insertFirst(int d){
    Node * newNode = new Node(d,this->first);
    this->first = newNode;
    nodeCounter++;
}

void List::print() const{
    Node* tmp = this->first;
    while (tmp){
        std::cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
    std::cout<<'\n';
    tmp = nullptr;
}

bool List::exists(int d) const
{
    Node* tmp = this->first;
    while(tmp){
        if (tmp->value == d)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int List::size() const
{
    return this->nodeCounter;
}

bool List::empty() const
{
    if (nodeCounter==0)
        return true;
    return false;
}

int List::removeFirst()
{
    if (empty()){
        throw std::invalid_argument("List Is empty");
    }
   Node* tmp = this->first;
   this->first = this->first->next;
   int v = tmp->value;
   delete tmp;
   return v;
}

void List::remove(int d, List::DeleteFlag df){
    Node* prev;
    Node* current = this->first;
    switch (df)
    {
        case List::DeleteFlag::EQUAL:
            if (current->value == d){
                this->first = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            while(current != nullptr)
            {
                if (current->value == d){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = prev->next;
            }
            break;
        case List::DeleteFlag::GREATER:
            if (current->value > d){
                this->first = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            while(current != nullptr)
            {
                if (current->value > d){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = current->next;
            }
            break;
        case List::DeleteFlag::LESS:
            if (current->value < d){
                this->first = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            while(current != nullptr)
            {
                if (current->value < d){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = current->next;
            }
            break;
    }
}

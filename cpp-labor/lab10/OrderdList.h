//
// Created by Matyas Kondert on 11/23/2022.
//

#ifndef LAB10_ORDERDLIST_H
#define LAB10_ORDERDLIST_H

// OrderedList.h
#include <functional>
#include <iostream>
#include <utility>
using namespace std;
// Class declaration
template< class T, class LessComp = less<T>, class Equal = equal_to<T> >
class Iterator;
// Class definition
template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;

        Node(T value,Node* next):value(value),next(next)
        {}
    };

    int numberOfElements;
    Node* first;
public:

    OrderedList();

    ~OrderedList();

    bool isEmpty();

    void insert(T &value);

    int size() const;

    void remove(T &value);

    bool find(T &value) const;

    void print(ostream &os);

    friend class Iterator<T, LessComp, Equal>;
};


// Class definition
template< class T, class LessComp, class Equal >
class Iterator{
private:
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T,LessComp,Equal> &orderedList);

    bool hasNext();

    T next();
};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &orderedList):list(orderedList),act(orderedList.first){}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext()
{
    return act!= nullptr;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next()
{
    auto value = act->value;
    act = act->next;
    return value;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList()
{
    first = nullptr;
    numberOfElements = 0;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList()
{
    Node *tmp = first;
    while (tmp){
        tmp = first->next;
        delete first;
        first = tmp;
    }
    numberOfElements = 0;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty()
{
    return numberOfElements == 0;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &value)
{
    Node* tmpFront = first;
    Node* tmpBack;
    Node* newNode = new Node(value, nullptr);
    if (numberOfElements == 0)
    {
        first = newNode;
        numberOfElements++;
        return;
    }
    while (tmpFront != nullptr && LessComp()(tmpFront->value,value)){
        tmpBack = tmpFront;
        tmpFront = tmpFront->next;
    }

    if (tmpFront == first){
        newNode->next = first;
        first = newNode;
        numberOfElements++;
        return;
    }

    if (tmpFront == nullptr){
        tmpBack->next = newNode;
        numberOfElements++;
        return;
    }

    newNode->next=tmpFront;
    tmpBack->next = newNode;
    numberOfElements++;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const
{
    return numberOfElements;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(T &value)
{
    Node* tmpFront = first->next;
    Node* tmpBack = first;

    if (Equal()(first->value,value)){
        tmpFront = first;
        first = first->next;
        delete tmpFront;
        return;
    }

    while (tmpFront!= nullptr){
        if (Equal()(tmpFront->value,value)){
            tmpBack->next = tmpFront->next;
            delete tmpFront;
            return;
        }
        tmpBack = tmpFront;
        tmpFront = tmpFront->next;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &value) const
{
    Node* tmpFront = first;
    while (tmpFront!= nullptr){
        if (Equal()(tmpFront->value,value))
            return true;
        tmpFront = tmpFront->next;
    }
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::print(ostream &os)
{
    Node* tmpFront = first;
    while (tmpFront!= nullptr){
        os<<tmpFront->value<<" ";
        tmpFront = tmpFront->next;
    }
}


#endif //LAB10_ORDERDLIST_H

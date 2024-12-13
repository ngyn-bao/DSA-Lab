#include <iostream>
#include "quiz2.h"
using namespace std;

template <class T>
class Queue
{
protected:
    DLinkedList<T> list;

public:
    Queue() {}
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
    void clear();

    void push(T item)
    {
        // TODO: Push new element into the end of the queue
        list.add(list.size(), item);
    }

    T pop()
    {
        // TODO: Remove an element in the head of the queue
        return list.removeAt(0);
    }

    T top()
    {
        // TODO: Get value of the element in the head of the queue
        return list.get(0);
    }

    bool empty()
    {
        // TODO: Determine if the queue is empty
        return list.empty();
    }

    int size()
    {
        // TODO: Get the size of the queue
        return list.size();
    }

    void clear()
    {
        // TODO: Clear all elements of the queue
        list.clear();
    }
};
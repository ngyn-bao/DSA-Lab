#include <iostream>
#include "quiz2.h"

using namespace std;

template <class T>
class Stack
{
protected:
    DLinkedList<T> list;

public:
    Stack() {}
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
    void clear();

    void push(T item)
    {
        // TODO: Push new element into the top of the stack
        list.add(0, item);
    }

    T pop()
    {
        // TODO: Remove an element on top of the stack
        return list.removeAt(0);
    }

    T top()
    {
        // TODO: Get value of the element on top of the stack
        return list.get(0);
    }

    bool empty()
    {
        // TODO: Determine if the stack is empty
        return list.empty();
    }

    int size()
    {
        // TODO: Get the size of the stack
        return list.size();
    }

    void clear()
    {
        // TODO: Clear all elements of the stack
        list.clear();
    }
};

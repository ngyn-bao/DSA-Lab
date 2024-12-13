#include <bits/stdc++.h>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0);
    ~SLinkedList() {};
    void add(T e);
    void add(int index, T e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
T SLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count)
        throw std::out_of_range("Index is out of range!");

    Node *current;
    current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count)
        throw std::out_of_range("Index is out of range!");
    Node *current = this->head;

    for (int i = 0; i < count; i++)
    {

        if (i == index)
        {
            current->data = e;
        }
        current = current->next;
    }
}

template <class T>
bool SLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    if (this->count == 0)
        return true;
    return false;
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node *current = this->head;
    for (int i = 0; i < this->count; i++)
    {
        if (current->data == item)
            return i;
        current = current->next;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    /* Check if item appears in the list */
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->data == item)
            return true;
        current = current->next;
    }
    return false;
}
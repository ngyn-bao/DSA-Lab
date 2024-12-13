#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList();
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    T removeAt(int index);
    bool removeItem(const T &item);
    void clear();

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= this->count)
        throw std::out_of_range("Index is out of range!");

    T deletedData;
    Node *current = this->head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    deletedData = current->data;

    if (current->previous != nullptr)
        current->previous->next = current->next;
    else
        this->head = current->next;

    if (current->next != nullptr)
        current->next->previous = current->previous;
    else
        this->tail = current->previous;

    delete current;
    this->count--;

    return deletedData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            if (current->previous != nullptr)
                current->previous->next = current->next;
            else
                this->head = current->next;

            if (current->next != nullptr)
                current->next->previous = current->previous;
            else
                this->tail = current->previous;

            delete current;
            this->count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear()
{
    /* Remove all elements in list */
    while (!empty())
    {
        removeAt(0);
    }
}
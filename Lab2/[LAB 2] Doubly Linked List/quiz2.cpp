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
T DLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    Node *current = this->head;
    T getData;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    getData = current->data;
    return getData;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    /* Assign new value for element at given index in the list */
    Node *current = this->head;
    for (int i = 0; i < index; i++)
        current = current->next;

    current->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
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
bool DLinkedList<T>::contains(const T &item)
{
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}
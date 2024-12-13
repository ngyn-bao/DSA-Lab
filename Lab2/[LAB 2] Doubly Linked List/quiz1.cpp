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
void DLinkedList<T>::add(const T &e)
{
    Node *newNode = new Node(e);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
    count++;
    /* Insert an element into the end of the list. */
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    if (index < 0 || index > count)
        throw out_of_range("index is out of range");

    Node *newNode = new Node(e);
    if (count == 0)
    {
        head = tail = newNode;
        count++;
    }
    else if (index == 0)
    {

        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        count++;
    }
    else if (index == count)
    {
        add(e);
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        count++;
    }

    /* Insert an element into the list at given index. */
}

template <class T>
int DLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return count;
}
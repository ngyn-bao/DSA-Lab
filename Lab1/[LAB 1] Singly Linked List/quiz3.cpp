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
    SLinkedList();
    ~SLinkedList();
    void add(T e);
    void add(int index, T e);
    int size();

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
        Node(T data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */
    Node *newNode = new Node(e, nullptr);
    if (this->head == nullptr)
    {
        this->head = this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    if (index < 0 || index > this->count)
    {
        throw std::out_of_range("Index is out of range!");
    }

    Node *newNode = new Node(e, nullptr);

    if (index == 0)
    {
        newNode->next = this->head;
        this->head = newNode;
        if (this->count == 0)
        {
            this->tail = newNode;
        }
    }
    else if (index == this->count)
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    else
    {
        Node *prev = nullptr;
        Node *current = this->head;
        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }
    this->count++;
}

template <class T>
int SLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return this->count;
}

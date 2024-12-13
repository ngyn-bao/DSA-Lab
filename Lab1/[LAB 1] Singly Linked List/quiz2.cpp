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
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);
    T removeAt(int index);
    bool removeItem(T item);

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
T SLinkedList<T>::removeAt(int index)
{

    if (index < 0 || index >= count)
        throw std::out_of_range("Index is out of range!");

    Node *current = this->head;
    Node *prev = nullptr;

    T deletedData;

    if (index == 0)
    {

        deletedData = this->head->data;
        this->head = this->head->next;
        if (this->head == nullptr)
            this->tail = nullptr;
    }

    else
    {

        for (int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }

        deletedData = current->data;
        prev->next = current->next;

        // If we are removing the last node, update the tail
        if (current == this->tail)
        {
            this->tail = prev;
        }
    }
    delete current;
    this->count--;

    return deletedData;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (this->head == nullptr)
    {
        return false;
    }

    Node *prev = nullptr;
    Node *current = this->head;

    while (current != nullptr)
    {
        if (current->data == item)
        {
            if (current == this->head)
            {
                head = head->next;
                delete current;
                count--;

                if (this->head == nullptr)
                    this->tail = nullptr;
            }
            else
            {
                prev->next = current->next;
                if (current == this->tail)
                {
                    this->tail = prev;
                }
                delete current;
                this->count--;
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <class T>
void SLinkedList<T>::clear()
{
    /* Remove all elements in list */
    Node *current = this->head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    count = 0;
}

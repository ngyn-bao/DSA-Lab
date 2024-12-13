#include <iostream>
#include <sstream>
using namespace std;

class LinkedList
{
public:
    class Node;

private:
    Node *head;
    Node *tail;
    int size;

public:
    class Node
    {
    private:
        int value;
        Node *next;
        friend class LinkedList;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    LinkedList() : head(NULL), tail(NULL), size(0) {};
    void partition(int k);
};

void LinkedList::partition(int k)
{
    Node *lessHead = nullptr, *lessTail = nullptr;
    Node *equalHead = nullptr, *equalTail = nullptr;
    Node *greaterHead = nullptr, *greaterTail = nullptr;

    Node *current = this->head;

    while (current != nullptr)
    {
        if (current->value < k)
        {
            if (lessHead == nullptr)
            {
                lessHead = lessTail = current;
            }
            else
            {
                lessTail->next = current;
                lessTail = lessTail->next;
            }
        }
        else if (current->value == k)
        {
            if (equalHead == nullptr)
            {
                equalHead = equalTail = current;
            }
            else
            {
                equalTail->next = current;
                equalTail = equalTail->next;
            }
        }
        else
        {
            if (greaterHead == nullptr)
            {
                greaterHead = greaterTail = current;
            }
            else
            {
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
        }
        current = current->next;
    }

    if (lessTail != nullptr)
        lessTail->next = nullptr;
    if (equalTail != nullptr)
        equalTail->next = nullptr;
    if (greaterTail != nullptr)
        greaterTail->next = nullptr;

    if (lessHead != nullptr)
    {
        this->head = lessHead;
        if (equalHead != nullptr)
        {

            lessTail->next = equalHead;
            if (greaterHead != nullptr)
            {
                equalTail->next = greaterHead;
                this->tail = greaterTail;
            }
            else
            {
                this->tail = equalTail;
            }
        }
        else
        {
            if (greaterHead != nullptr)
            {
                lessTail->next = greaterHead;
                this->tail = greaterTail;
            }
            else
            {
                this->tail = lessTail;
            }
        }
    }
    else if (equalHead != nullptr)
    {
        this->head = equalHead;
        if (greaterHead != nullptr)
        {
            equalTail->next = greaterHead;
            this->tail = greaterTail;
        }
        else
        {
            this->tail = equalTail;
        }
    }
    else
    {
        this->head = greaterHead;
        this->tail = greaterTail;
    }

    if (this->tail != nullptr)
        this->tail->next = nullptr;
}
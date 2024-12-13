#include <iostream>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode();                      // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode *next); // Constructor with customized data

    LLNode *reverseLinkedList(LLNode *head)
    {
        // STUDENT ANSWER
        LLNode *current = head, *prev = nullptr, *next;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }
        return prev;
    }
};
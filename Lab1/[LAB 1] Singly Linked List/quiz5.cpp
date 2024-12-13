#include <iostream>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode();                      // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode *next); // Constructor with customized data

    LLNode *rotateLinkedList(LLNode *head, int k)
    {
        // STUDENT ANSWER
        if (k == 0 || head == nullptr)
            return head;

        LLNode *current = head;
        int length = 1;
        while (current->next != nullptr)
        {
            current = current->next;
            length++;
        }

        current->next = head;

        k = k % length;
        int stepToNewHead = length - k;

        current = head;
        for (int i = 1; i < stepToNewHead; i++)
        {
            current = current->next;
        }

        LLNode *newHead = current->next;
        current->next = nullptr;

        return newHead;
    }
};
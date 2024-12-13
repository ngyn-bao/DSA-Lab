#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val = 0, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

// Merge two sorted lists
ListNode *mergeSortList(ListNode *head);

// Sort an unsorted list given its head pointer
ListNode *mergeSortList(ListNode *head);

ListNode *mergeLists(ListNode *a, ListNode *b)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (a != nullptr && b != nullptr)
    {
        if (a->val < b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != nullptr)
    {
        tail->next = a;
    }
    else
    {
        tail->next = b;
    }

    return dummy.next;
}

ListNode *getMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *mergeSortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *mid = getMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = nullptr;

    left = mergeSortList(left);
    right = mergeSortList(right);

    return mergeLists(left, right);
}
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode();
    LLNode(int val, LLNode *next);

    LLNode *addLinkedList(LLNode *l0, LLNode *l1)
    {
        // STUDENT ANSWER
        LLNode *result = nullptr;
        LLNode *tail = nullptr;
        int carry = 0;

        while (l0 != nullptr || l1 != nullptr || carry != 0)
        {
            int sum = carry;

            if (l0 != nullptr)
            {
                sum += l0->val;
                l0 = l0->next;
            }

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            LLNode *newNode = new LLNode(digit, nullptr);

            if (result == nullptr)
            {
                result = newNode;
                tail = result;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return result;
    }
};